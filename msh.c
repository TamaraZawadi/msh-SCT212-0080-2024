#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


int main(void)
{
	char *line = NULL;
	size_t len = 0;

	char *argv[100];
	char *token;
	int i;	
	pid_t pid;
	int status =0;
	signal(SIGINT, SIG_IGN);

	while (1)
	{
	  printf("msh[%d]> ", status);
	  fflush(stdout);

	if (getline(&line,&len,stdin) ==-1)
	{
		break;
	}
	i = 0;
	token = strtok(line, " \t\n");

	while (token != NULL && i < 99)
	{
	    argv[i] = token;
	    i++;
	    token = strtok(NULL, " \t\n");
	}

	argv[i] = NULL;	

	if (argv[0] == NULL)
	{
 	   continue;
	}

	if (strcmp(argv[0], "cd") == 0)
	{
	    char *directory;

	    if (argv[1] == NULL)
	    {
        	directory = getenv("HOME");
	    }
	    else
	    {	
        	directory = argv[1];
	    }

	    if (directory == NULL)
	    {
        	fprintf(stderr, "cd: HOME not set\n");
	    }
	    else if (chdir(directory) == -1)
	    {
	        perror("cd");
	    }
	    continue;
		}
		
	if (strcmp(argv[0], "help") == 0)
	{
	    printf("Mini Shell Help\n");
	    printf("Built-in commands:\n");
	    printf("cd [dir] - Change the current directory\n");
	    printf("help - Display this help message\n");
	    printf("exit - Exit the shell\n");
	    printf("External commands can also be executed.\n");

	    continue;
	}

	if (strcmp(argv[0], "exit") == 0)
	{
	    free(line);
	    exit(EXIT_SUCCESS);
	}
	pid = fork();

	if (pid == -1)
	{
	    perror("fork");
	}

	else if (pid == 0)
	{
	signal(SIGINT, SIG_DFL);

	    execvp(argv[0], argv);

	    perror("execvp");
	    exit(EXIT_FAILURE);
	}
	else
	{
	    if (waitpid(pid, &status, 0) == -1)
	    {
	        perror("waitpid");
	    }
	 else if (WIFEXITED(status))
    	{
        	status = WEXITSTATUS(status);
    	}
	    else if (WIFSIGNALED(status))
    	{
        	status = 128 + WTERMSIG(status);
    	}
	}
	}

	free(line);

    return 0;
}


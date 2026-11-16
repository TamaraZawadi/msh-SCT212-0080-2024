#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
	char *line = NULL;
	size_t len = 0;

	char *argv[100];
	char *token;
	int i;	
	pid_t pid;

	while (1)
	{
	  printf("msh$ ");
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
	pid = fork();

	if (pid == -1)
	{
	    perror("fork");
	}

	else if (pid == 0)
	{
	    execvp(argv[0], argv);

	    perror("execvp");
	    exit(EXIT_FAILURE);
	}
	else
	{
	    if (waitpid(pid, NULL, 0) == -1)
	    {
	        perror("waitpid");
	    }
	}
	}

	free(line);

    return 0;
}


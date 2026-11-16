#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
	char *line = NULL;
	size_t len = 0;

	char *argv[100];
	char *token;
	int i;	

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
		for (int j = 0; argv[j] != NULL; j++)
		{
		    printf("argv[%d]: %s\n", j, argv[j]);
		}
	}

	free(line);

    return 0;
}

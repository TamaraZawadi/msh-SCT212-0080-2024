#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
	  printf("msh$ ");
	  fflush(stdout);

	if (getline(&line,&len,stdin) ==-1)
	{
		break;
	}
	printf("%s", line);
	}

	free(line);

    return 0;
}

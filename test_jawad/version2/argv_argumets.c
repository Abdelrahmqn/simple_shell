#include"main.h"

/**
 * _spliting - Function that tokenizes the command line arguments.
 * @input_command: command to be tokenized.
 * @line: the line to be spilted.
 * Return: an array of command
 */
char **_splitting(char *line)
{
        int num_args = 0, i = 0;
        
        char *token = NULL, *line_dup = NULL;
        char **line_command = NULL;
       /* char DELIM[] = " \t\n"; */

	if (line == NULL)
		return (NULL); /* check an empty line */
	
	line_dup = strdup(line); /* create duplacata */
	
	token = strtok(line_dup, DELIM); /* ponter the first elemnt in the line) */
        
	if (token == NULL) /* check if the first token is null (just space and tab) */
	{
		free(line_dup), line_dup = NULL; /* free the duplicata and set to NULL */
		free(line), line = NULL; /* free the line and set to NULL */
		return (NULL); /* return NULL the main function */
	}       
	
	while (token != NULL)
	{
		num_args++;
		token = strtok(NULL, DELIM);
	}

	free(line_dup), line_dup = NULL;

	line_command = malloc(sizeof(char *) * (num_args + 1));

	if (line_command == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, DELIM);

        while (token != NULL && num_args < LIM_ARGS - 1)
        {
                line_command[i] = strdup(token);
                token = strtok(NULL, DELIM);
		i++;
	}
        line_command[num_args] = NULL;
	free(line), line = NULL;      

        return (line_command);
}


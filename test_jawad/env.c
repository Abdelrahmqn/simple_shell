#include "main.h"
/**
 * _env_variables - function that itarates arguments variable to execute
 *
 * @envp: the environment variable.
 *
*/
void _env_variables(char **envp)
{
	char *print_env;
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		print_env = envp[i];
		write(1, &print_env, 1);
	}
}

#include <stdio.h>
/*
 * fprintf()
 * printf()
 * stderr
 * getchar()
 * perror()
 */
#include <unistd.h>
/*
 * chdir()
 * fork()
 * exec()
 * pid_t
 *
 */
#include <string.h>
/* strcmp()
 * strtok()
 */
#include <stdlib.h>
/* malloc()
 * realloc()
 * free()
 * exit()
 * execvp()
 * EXIT_SUCCESS, EXIT_FAILURE
 */

#include <sys/wait.h>
#include <sys/types.h>

/*  This file is about creating your own shell in  'C'.
 *  Objective: is to learn all concepts behind the implementations.
 */

/*
 *  1. Command is entered, and if length is non-null; it's stored in history
 *  2. Parsing -  breaking up commands into individual words or strings.
 *  3. Checking for special characters like pipes, etc is done.
 *  4. Hanling Pipes
 *  5. Executing system commands and libraries ---- by forking a child and calling execvp.
 */

char *read_line(void)
{
	int buffer_size = SH_BUF_SIZE; 
	int position = 0; 

	char *buffer = malloc(sizeof(char) * buffer_size); 
	if (!buffer)
	{
		fprintf(stderr, "sh: Allocation error\n");
		exit(EXIT_FAILURE);
	}

}










void run_shell_loop(void)
{
	// run_shell_loop doesn't take any parameters

	char *line; 
	char **args; 
	int status; 

	do 
	{
		printf("#@! ");
		line = read_line();
		args = split_line();
		status = execute_line(args);

		free(line);
		free(args);
	}while(status);
}


int main( int argc, char **argv)
{

	/* argc is the argument count 
	 * argv is the argment vector
	 */

	printf("Entering the custom shell\n");
	// Load config files if any
	
	// Run Command Loop

	run_shell_loop();

	// Perform any shutdown or cleanup operations.

	return EXIT_SUCCESS;
}

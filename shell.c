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


/*
 *  ------------------------------------------------------------------------------------------------------------
 */

# define SH_BUF_SIZE 1024
# define TOK_BUF_SIZE 64
# define TOK_DELIM " \t\r\n\a"



/*
 *  ------------------------------------------------------------------------------------------------------------
 */

// Understanding the logic here, but need to understand the definitions.....


char **split_line(char *line)
{
	int buffer_size = TOK_BUF_SIZE, position = 0;
	char **tokens = malloc(buffer_size * sizeof(char*));
	char *token, **tokens_backup;

	if (!tokens)
	{
		fprintf(stderr, "sh: Allocation error\n");
		exit(EXIT_FAILURE);
	}


}





/*
 * read_line() - reads entries from stdin
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

	int c; 

	while(1)
	{
		c = getchar();
		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		}

		else if (c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}

		else
		{
			buffer[position] = c; 
		}

		position++;
	}

	/* What happens if we have exceeded the buffer??
	 * We will have to reallocate some memory right?
	 */

	if (position >= buffsize)
	{
		buffer_size += SH_BUF_SIZE;
		buffer = realloc(buffer, buffer_size);

		// every time you reallocate memory; check for NULL?!
		if (!buffer)
		{
			fprintf(stderr, "sh: Allocation error\n");
			exit(EXIT_FAILURE);
		}
	}
}


/*
 *  run_shell_loop() function - Serves as an orchestrator
 */

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

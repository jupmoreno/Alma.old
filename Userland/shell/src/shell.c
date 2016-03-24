#include <shell.h>
#include <stdio.h>
#include <commands.h>
#include <memory.h>
#include <numbers.h>
#include <strings.h>

char user[MAX_USER_NAME] = "root";
char * program = "shell";

static void shell_bss_clear();

static int parseCommand(char * buffer, int size);
static command_t * getCommand(const char * cmd);
static args_t * getArgs(char * buffer);

#define COMMAND_MAX_ARGS 10 // TODO: Temporal fix! Needs malloc to remove
static char * argv[COMMAND_MAX_ARGS] = {};
static args_t args = {argv, 0};

int main() {
	args_t * args, noargs = {NULL, 0};
	command_t * command;
	int ret, should_clear;
	char buffer[MAX_BUFFER_LENGTH]; // TODO: Buffer global?

	// Shell cycle
	while(TRUE) {
		// Print prompt
		printf("%s@%s:$> ", user, program);

		// Get command's name
		// ret = -1: error, 1: more args, 0: no more args
		ret = parseCommand(buffer, MAX_BUFFER_LENGTH);
		// if ret !=0 -> clear buffer
		should_clear = ret; 

		// If error, print it
		if(ERROR_OCCURRED(ret)) {
			printf("Uups! There was an error reading the command. Try again!\n");
		} else if(buffer[0]) { // If not empty string, continue
			// Get command from list
			command = getCommand(buffer);

			// If command == null -> command invalid, print error
			if(command == NULL) {
				printf("YO! The command '%s' doesn't exist. Don't try to fool me!\n", buffer);
			} else {
				// Get the arguments if ret == 1 (meaning it has arguments)
				// If ret == 0 -> doesn't have arguments, send null arguments
				args = ret ? getArgs(buffer + ret + 1) : &noargs;

				// If error getting the args -> print it
				if(args == NULL) {
					printf("Uups! There was an error reading the arguments. Try again!\n");
				} else {
					// If args were read, then no need to clear buffer
					should_clear = FALSE;

					// Run command, get it's return value
					ret = command->run(*args);
					// If error occurred -> print it
					if(ERROR_OCCURRED(ret)) {
						printf("(%d) Humm... That last command didn't end as espected.\n", ret);
					}
				}
			}
		}

		// If should_clear -> clear buffer
		if(should_clear) {
			CLEAR_SCAN_BUFFER;
		}
 	}

	return OK;
}

static int parseCommand(char * buffer, int size) {
	int ret, hasMoreArgs;

	ret = scanw(buffer, size);
	if(ret == -1 || buffer[ret] == '\0') {
		return -1;
	}

	if(buffer[ret] == ' ') {
		hasMoreArgs = TRUE;
	} else {
		hasMoreArgs = FALSE;
	}

	buffer[ret] = '\0';

	return hasMoreArgs ? 1 : 0;
}

static command_t * getCommand(const char * cmd) {
	int i = 0;

	if(cmd[0] == 0) {
		return NULL;
	}

	// Search for the command in the list of commands
	for(i = 0; i < _COMMANDS_SIZE; i++) {
		// If found, return pointer to it
		if(!strcmp(cmd, commands[i].name)) {
			return &commands[i];
		}
	}

	return NULL;
}

static args_t * getArgs(char * buffer) {
	int ret, i = 0, hasMoreArgs = TRUE;

	args.argc = 0;
	while(hasMoreArgs) {
		ret = scanw(buffer, MAX_BUFFER_LENGTH);

		if(ret == -1 || buffer[ret] == '\0') {
			return NULL;
		}

		if(buffer[ret] == '\n') {
			hasMoreArgs = FALSE;
		} else {
			if(i + 1 >= COMMAND_MAX_ARGS) {
				return NULL;
			}
		}

		buffer[ret] = '\0';
		args.argv[i++] = buffer;
		args.argc++;
		buffer += ret + 1;
	}

	return &args;
}

// #define _SHELL_ERRORS 5
// static const char * error_message[_SHELL_ERRORS] = {
// 	"Unknown",
// 	"Invalid command.\nUse help command to show a list of possible commands",
// 	"Missing arguments",
// 	"Too many arguments",
// 	"Invalid arguments"
// 	// FUTURE ERROR MESSAGE HERE !! REMEMBER TO CHANGE _SHELL_ERRORS !!
// };

// void shell_printe(int error) {
// 	error = ABS(error);

// 	if(error >= _SHELL_ERRORS) {
// 		error = 0;
// 	}

// 	printf("<ERROR> %s.\n", error_message[error]);
// }
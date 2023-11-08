#ifndef COMMANDS_H
#define COMMANDS_H

#include "definitions.h"

// Executes an external command.
void execute_external_command(char **tokens);

typedef struct CommandStruct {
   int first;          // index to the first token in the array "token" of the command
   int last;           // index to the first token in the array "token" of the command
   char *sep;	       // the command separator that follows the command,  must be one of the separators "|", "&", and ";"
   char **argv;        // an array of tokens that forms a command
   char *stdin_file;   // if not NULL, points to the file name for stdin redirection                        
   char *stdout_file;  // if not NULL, points to the file name for stdout redirection                        
} Command;

// Used to spearate list of token array into sequence of commands to be stored in Commands to execute
int separateCommands(char *token[], Command command[]);

#endif // COMMANDS_H

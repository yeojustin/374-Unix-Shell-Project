// command.h

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <glob.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definitions.h"

// static const char WHITE_SPACE[2] = {(char)0x20, (char)0x09};

typedef struct CommandStruct
{
  char *name;
  char *stdin;
  char *stdout;
  char *stderr;
  char *argv[MAX_ARGUMENTS];
  int argc;
  int background;
  int pipe;
  int redirection;
} Command;

Command *createCommand(char *input, int background, int pipe);
int getArgs(char *input, Command *command);
char *getSeparator(char *input);
void processCommandLine(char *input, int background, int pipe, int iteration, Command **commands);processCommand
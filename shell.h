// shell.h

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wordexp.h>
#include <readline/readline.h>
#include <readline/history.h>


#include "command.h"

#define BUF_SIZE 256
#define CHANGE_DIR "cd"
#define PRINT_DIR "pwd"
#define PROMPT "prompt"
#define EXIT "exit"
#define HISTORY "history"

extern char *promptName;
extern Command *commandArray[MAX_COMMANDS];
extern char *input;

int redirection(Command *command);
void collectChildren();
void handleSignals();
void display_history();
int setupSignals();
int toggleSignalBlock(int flag, int signalNumber);
void freeCommands(Command **commands);
void executeCommands(Command **commands);
void createPipedProcesses(Command **pipedCommands, int count);
void createProcess(Command *command);

#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <signal.h>
#include "shell.h"

int main() {
    char *input;

    setupSignals();

    while (1) {
        input = readline(promptName);

        // Handle interruptions (e.g., signals)
        while (input == NULL && errno == EINTR) {
            input = readline(promptName);
        }

        if (input && *input) {  // Check if input is not empty
            add_history(input);  // Add to history

            toggleSignalBlock(SIG_BLOCK, SIGCHLD);

            handleCommandLine(input, 0, 0, 0, commandArray);
            executeCommands(commandArray);
            freeCommands(commandArray);

            toggleSignalBlock(SIG_UNBLOCK, SIGCHLD);
        }

        free(input);  // Free memory allocated by readline
    }

    exit(0);
}

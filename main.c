#include "history.h"
#include "commands.h"
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

int main() {
    char *input;
    char *tokens[MAX_ARG_SIZE];

    while (1) {
        input = readline("myshell> ");
        if (input == NULL) {
            continue; // Handle EOF
        }
        if (*input) {
            add_history(input); // Add non-empty input to history
        }

        int i = 0;
        tokens[i] = strtok(input, " ");
        while (tokens[i] != NULL) {
            i++;
            tokens[i] = strtok(NULL, " ");
        }

        if (tokens[0] != NULL) {
            if (strcmp(tokens[0], "exit") == 0) {
                handle_exit();
            } else if (strcmp(tokens[0], "cd") == 0) {
                change_directory(tokens[1]);
            } else if (strcmp(tokens[0], "pwd") == 0) {
                print_working_directory();
            } else if (strcmp(tokens[0], "history") == 0) {
                display_history();
            } else {
                execute_external_command(tokens);
            }
        }

        free(input); // Free the memory allocated by readline
    }

    return 0;
}

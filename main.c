#include "history.h"
#include "commands.h"
#include "definitions.h"
#include "directory.h"
#include "exit.h"

#include <stdio.h>
#include <string.h>

int main() {
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_ARG_SIZE];

    while (1) {
        printf(DEF_SHELL_PROMPT);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue; // Handle EOF
        }
        input[strcspn(input, "\n")] = 0; // Remove newline character

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

        add_to_history(input);
    }

    return 0;
}

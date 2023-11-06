#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The array to store history commands and the count of commands are defined here.
char *history[HISTORY_SIZE];
int history_count = 0;

void add_to_history(const char *cmd) {
    if (history_count < HISTORY_SIZE) {
        history[history_count++] = strdup(cmd);
    } else {
        free(history[0]);
        memmove(history, history + 1, sizeof(char*) * (HISTORY_SIZE - 1));
        history[HISTORY_SIZE - 1] = strdup(cmd);
    }
}

void display_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

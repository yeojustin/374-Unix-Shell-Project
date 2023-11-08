#include "exit.h"
#include <stdlib.h>

void handle_exit() {
    // Clean up history.
    for (int j = 0; j < HISTORY_SIZE; j++) {
        free(history[j]);
    }
    exit(0);
}
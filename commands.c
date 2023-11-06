#include "commands.h"
#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <glob.h>

void handle_exit() {
    // Clean up history.
    for (int j = 0; j < HISTORY_SIZE; j++) {
        free(history[j]);
    }
    exit(0);
}

void change_directory(const char *path) {
    if (path == NULL) {
        chdir(getenv("HOME"));
    } else {
        if (chdir(path) != 0) {
            perror("chdir failed");
        }
    }
}

void print_working_directory() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd failed");
    }
}

void list_directory_contents(const char *path) {
    DIR *dir;
    struct dirent *entry;
    if (path != NULL) {
        dir = opendir(path);
    } else {
        dir = opendir(".");
    }
    if (dir == NULL) {
        perror("opendir failed");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

void execute_external_command(char **tokens) {
    if (strchr(tokens[0], '*') || strchr(tokens[0], '?')) {
        glob_t results;
        int ret = glob(tokens[0], 0, NULL, &results);
        if (ret == 0) {
            execvp(results.gl_pathv[0], results.gl_pathv);
            globfree(&results);
        } else {
            perror("glob failed");
        }
    } else {
        pid_t pid = fork();
        if (pid == 0) {
            execvp(tokens[0], tokens);
            perror("execvp failed");
            exit(1);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("fork failed");
        }
    }
}

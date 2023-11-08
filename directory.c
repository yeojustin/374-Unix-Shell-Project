#include "directory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <glob.h>

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
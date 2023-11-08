#ifndef DIRECTORY_H
#define DIRECTORY_H

// Changes the current directory.
void change_directory(const char *path);

// Prints the current working directory.
void print_working_directory();

// Lists the contents of a directory.
void list_directory_contents(const char *path);

#endif // DIRECTORY_H
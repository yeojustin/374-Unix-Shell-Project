#ifndef COMMANDS_H
#define COMMANDS_H

// Handles the 'exit' command.
void handle_exit();

// Changes the current directory.
void change_directory(const char *path);

// Prints the current working directory.
void print_working_directory();

// Lists the contents of a directory.
void list_directory_contents(const char *path);

// Executes an external command.
void execute_external_command(char **tokens);

#endif // COMMANDS_H

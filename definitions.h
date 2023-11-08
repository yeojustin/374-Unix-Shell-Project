#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// shell prompt
#define DEF_SHELL_PROMPT "%% "

// History buffer size
#define HISTORY_SIZE 10

// for cmd line inputs
#define MAX_INPUT_SIZE 1000
#define MAX_ARG_SIZE 100

// command separators
#define PIPE_SEP  "|"                            // pipe separator "|"
#define CON_SEP   "&"                            // concurrent execution separator "&"
#define SEQ_SEP   ";"                            // sequential execution separator ";"

// wildcards
#define WILDCARD_QUES '?'
#define WILDCARD_ASTK '*'

// error msg
#define CONSEC_SEP_ERR "Error: Consecutive separators as arg\n"
#define FIRST_ARG_ERR "Error: First arg is a separator"
#define LAST_ARG_ERR "Error: Last arg is a pipe separator"
#define UNKN_ERR "Error: Unknown error occured"

#endif // DEFINITIONS_H
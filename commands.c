#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <glob.h>
#include <unistd.h>
#include <sys/wait.h>

#include "commands.h"

// return 1 if the token is a command separator
// return 0 otherwise
int isSeparator(char* token)
{
    int i=0;
    char* commandSeparators[] = {PIPE_SEP, CON_SEP, SEQ_SEP, NULL}; // null to mark end of array

    while (commandSeparators != NULL) 
    {
        if (strcmp(commandSeparators[i], token) == 0) 
        {
            return 1;
        }
        ++i;
    }

    return 0;
}


// fill one command structure with the details for execution
void fillCommandStructure(Command* cp, int first, int last, char* sep)
{
    cp->first = first;
    cp->last = last-1;
    cp->sep = sep;
}


// process standard in/out redirections in a command
void searchRedirection(char *token[], Command *cp)
{
     int i; 
     for (i = cp->first; i <= cp->last; ++i) {
         if (strcmp(token[i], "<") == 0) {   // standard input redirection
              cp->stdin_file = token[i+1];
              ++i;
         } else if (strcmp(token[i], ">") == 0) { // standard output redirection
              cp->stdout_file = token[i+1];
              ++i;
         }
     }
}


// build command line argument vector for execvp function
void buildCommandArgumentArray(char *token[], Command *cp) 
{
    int n = (cp->last - cp->first + 1)           // the number of tokens in the command
            - (cp->stdin_file != NULL ? 2 : 0)   // remove 2 tokens for stdin redirection
            - (cp->stdout_file != NULL ? 2 : 0)  // remove 2 tokens for stdout redirection
            + 1;                                 // the last element  in argv must be a NULL

     // re-allocate memory for argument vector
     cp->argv = (char **) realloc(cp->argv, sizeof(char *) * n);   
     if (cp->argv == NULL) {
         perror("realloc");
         exit(1);
     }

     // build the argument vector
     int i;
     int k = 0; 
     for (i=cp->first; i<= cp->last; ++i ) {
         if (strcmp(token[i], ">") == 0 || strcmp(token[i], "<") == 0) 
             ++i;    // skip off the std in/out redirection
         else {
             cp->argv[k] = token[i];
             ++k;
         }
     }
     cp->argv[k] = NULL;
}


int separateCommands(char* token[], Command command[])
{
    int i;
    int numTokens;

    // find out num of tokens in token array
    i=0;
    while (token[i] != NULL)
    {
        ++i;
    }

    numTokens = i;

    // if numTokens is zero means command line is empty for sure
    if (numTokens == 0)
    {
        return 0;
    }

    // check if first token is a separator
    if (isSeparator(token[0]))
    {
        return -3;   
    }

    // check last token is not a separator then add sequence separator
    if (!isSeparator(token[numTokens-1]))
    {
        token[numTokens] = SEQ_SEP;
        ++numTokens;
    }
    int first = 0;
    int last;
    char* separator;
    int c = 0;

    for (i=0; i<numTokens; ++i)
    {
        last = i;
        if (isSeparator(token[i]))
        {
            separator = token[i];
            if (i != 0 && first == last)
            {
                return -2;
            }

            fillCommandStructure(&(command[c]), first, last, separator);
            ++c;
            first = i+1;
        }
    }

    // check the last token of the last command
    if (strcmp(token[last], PIPE_SEP) == 0)
    {
        return -4;
    }

    // calculate the num of commands
    int numCommands = c;

    return numCommands;
}


void isWildcard(Command *cp)
{
    // check for wildcard '*' or '?' expansion
    if (cp->argv[0] != NULL && strchr(cp->argv[0], WILDCARD_ASTK) 
                            || strchr(cp->argv[0], WILDCARD_QUES))
    {
        glob_t result;
        
        // use glob func for wildcard expansion
        if (glob(cp->argv[0], GLOB_NOCHECK, NULL, &result) == 0)
        {
            int argc = result.gl_pathc;

            // dynamically allocate memory for expanded argument
            char** expanded_args = (char**)malloc((argc+1)*sizeof(char*));
            if (expanded_args == NULL) 
            {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }

            
        }


    }
}



void execute_external_command(char *tokens[]) 
{
    if (strchr(tokens[0], WILDCARD_ASTK) || strchr(tokens[0], WILDCARD_QUES)) {
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
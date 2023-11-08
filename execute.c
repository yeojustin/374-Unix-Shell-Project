#include "execute.h"
#include "commands.h"

#include <stdlib.h>
#include <unistd.h>

void execute_external_command(char* tokens[])
{
    Command cmds[MAX_INPUT_SIZE];

    int numCmd = separateCommands(tokens, &cmds);

    // check for distinct commands
    if (numCmd < 1)
    {   
        switch (numCmd)
        {
            case -4:
                printf(LAST_ARG_ERR);
                break;
            
            case -3:
                printf(CONSEC_SEP_ERR);
                break;

            case -2:
                printf(FIRST_ARG_ERR);
                break;
            
            default:
                prinf(UNKN_ERR);
        }

        return;
    }
    else
    {
        for (int i=0; i<numCmd; ++i)
        {
            // construct arg array
            buildCommandArgumentArray(tokens, &cmds[i]);

            // process stdin/stdout redirection for current command
            searchRedirection(tokens, &cmds[i]);

            // fork child process to execute commands
            pid_t pid = fork();

            if (pid < 0) // fork failed
            {
                perror("Fork failed");
                exit(EXIT_FAILURE);
            }
            else if (pid == 0) // child process
            {
                // execute command
                execvp(&cmds[i].argv[0], &cmds[i].argv[1]);
                perror("Execution failure");
                exit(EXIT_FAILURE);
            }
            else // parent process
            {
                wait(NULL); // wait for child to complete
            }
        }
    }

}
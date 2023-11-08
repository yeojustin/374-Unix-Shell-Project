# Unix-Shell-Project

WIP, 18 more days

TODO:
1. Reconfigurable shell prompt
2. pwd
3. dir walk
4. wild card
5. redirection of stdout and in
6. shell pipeline | 
7. Bg job exec
8. Seq job exec
9. Cmd hist
10. Shell inherit from parent
11. exit
12. Daemionise and claim zombies

@Montkz
Done:
- Wildcard
- Dir walk
- History
- Execution

8/11
@merceix
Wildcard still does not expand directory
History working but up/down key cannot be used to access history
Execution does not take in 

Fixes:
- Further modularisation of codebase
- makefile, wip
- Args to command
- Wildcard path expansion
- Execution of command based on arg
- Pipe commands

WIP: 
- execute.c -> 'hasWildCards(Command *cp)'
- redirection of stdin and out

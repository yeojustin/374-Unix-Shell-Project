| Feature                                     | Basic Functionality | Advanced Functionality |
|---------------------------------------------|---------------------|-------------------------|
| Compilation and build                       | ✅                 |                         |
| Simple commands                             | ✅                 |                         |
| Shell built-ins                             | ✅                 |                         |
| Tokenization                                | ✅                 |                         |
| Wildcard expansion * ?                      | ✅                 |                         |
| Handling of Ctrl-C, Ctrl-\ and Ctrl-Z       | ✅                 |                         |
| Management of zombies                       | ✅                 |                         |
| Sequential execution                        |                     | ✅                     |
| Concurrent execution                        |                     | ✅                     |
| Standard I/O and error redirection          |                     | Err redirection not working                     |
| Shell pipelines                             |                     | ✅                     |
| Command history                             |                     | need overhaul from "main branch" implementation            |
| Complex command lines with mixture of separators |               | ✅                     |
| Handling of slow system calls               |                     | ✅                     |


Fixes and additions from 'main' branch
1. compelete overhaul because execution does not seaprate tokens and handle complex mixtures
2. missing tokenisation from separators to handle command line
3. create tokenisation > command line wrt separators (working)
4. fix wildcard exact '?' and integrated it into inital wildcard all '*'
5. ALL other requirments as per assignment (see check list)

###TODOs: 
1. testcases (do as you go)
- suggest creating a c source file
- create multiple block of functions then create a command ie. % testshell to run the functions
- functions auto parse in commands from function into command line

2. history implementation
- from 'main' branch, generally on track but not as per requirements as of now
- need some overhaul and then merge with 'v4-fix-90%' branch
- need it to not just store in an array of of char* but also allow it to be accessed through command line using UP / DOWN arrow key ie  ^[[A, ^[[B input

3. Fix stderr redirection
- implementation done, but somehow it is still not working. Need further debugging

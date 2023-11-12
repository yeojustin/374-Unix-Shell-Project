| Feature                                     | Basic Functionality | Advanced Functionality           |
|---------------------------------------------|---------------------|----------------------------------|
| Compilation and build                       | ✅                 |                                  |
| Simple commands                             | ✅                 |                                  |
| Shell built-ins                             | ✅                 |                                  |
| Tokenization                                | ✅                 |                                  |
| Wildcard expansion ( * ? )                  | ✅                 |                                  |
| Handling of Ctrl-C, Ctrl-\ and Ctrl-Z       | ✅                 |                                  |
| Management of zombies                       | ✅                 |                                  |
| Change Prompt                               | ✅                 |                                  |
| Sequential execution                        |                     | ✅                              |
| Concurrent execution                        |                     | ✅                              |
| Standard I/O and error redirection          |                     | Err redirection not working     |
| Shell pipelines                             |                     | ✅                              |
| Command history                             |                     | Needs overhaul from 'main' branch implementation |
| Complex command lines with mixture of separators |               | ✅                              |
| Handling of slow system calls               |                     | ✅                              |

**Fixes and additions from 'main' branch:**
1. Complete overhaul because execution does not separate tokens and handle complex mixtures.
2. Missing tokenization from separators to handle the command line.
3. Create tokenization > command line with respect to separators (working).
4. Fix wildcard exact '?' and integrate it into the initial wildcard '*'.
5. All other requirements as per the assignment (see the checklist).

**TODOs in ['v4-fix-90%'](https://github.com/yeojustin/Unix-Shell-Project/tree/v4.0-fix-90%25) branch:**
1. Test cases (do as you go).
   - Suggest creating a C source file.
   - Create multiple blocks of functions, then create a command (e.g., `% testshell`) to run the functions.
   - Functions should automatically parse in commands from the function into the command line as test command lines based on requirements.
   - Handle edge cases

2. History implementation.
   - From 'main' branch, generally on track but not as per requirements as of now.
   - Need some overhaul and then merge with ['v4-fix-90%'](https://github.com/yeojustin/Unix-Shell-Project/tree/v4.0-fix-90%25) branch.
   - Need it to not just store in an array of `char*` but also allow it to be accessed through the command line using UP / DOWN arrow keys (i.e., `^[[A`, `^[[B` input).

3. Fix stderr redirection.
   - Implementation done, but somehow it is still not working. Need further debugging.

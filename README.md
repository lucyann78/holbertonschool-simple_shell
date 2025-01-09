# Simple Shell
simple shell implementation that can execute commands from the command line, similar to the standard Unix/Linux shell.
___
# Usage 
shell will not display a prompt when it is ready to accept commands. Enter the command you wish to execute and press Enter. The shell will then execute the command and display the output.

* [$ ./hsh
* [ls
  * file1 file2 file3
* [echo  Hello, world!
  * Hello, world!
* [cat  file1
  * This is the content of file1.
* The shell also supports some built-in commands, such as exit.
___
# Files

Overview of the files in this repository:
| file | description |
|---|---|
| shell.h | Header file containing function prototypes and macros. |
| env_fetch.c| Verifies tokens|
| _getenv.c | Finds the environment |
| parse_input.c | Analyzes the user input and tokenizes it. |
| execute_command.c |Forks process, executes a command and waits if necessary.|
| find_or_execute_command | Checks the command input for execution.|
| mainshell.c| Entry point, command line interptreter.|
___
# Flowchart
![simple_shellflow_chart](https://github.com/hruiz1191/holbertonschool-simple_shell/blob/main/Screenshot%202025-01-08%209.06.11%20PM.png)
1. Start
2. Display prompt: "$ "
3. Read command
4. Is it "exit"?
   * Yes: End
5. No: Continue
6. Split command into words: Separate the command into the part that indicates the action and its arguments.
7. Search for command in database: Check if the command exists in the list of known commands.
8. If the command exists:
   * Validate arguments: Ensure that the provided arguments are valid for the command.
   * Execute command: Call the corresponding function to execute the command.
   * Handle errors: If an error occurs during execution, display an error message.
9. If the command does not exist:
8. Display error message: Inform the user that the command is not recognized.
10. Go back to step 2
___
# AUTHORS
This shell was created by:
* Lucy ann [Github](https://github.com/lucyann78)
* Hector Ruiz [Github](https://github.com/hruiz1191/)

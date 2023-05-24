Simple Shell project
by Warrior Govender and Gabriela da Silva

In this project we have Created a simple shell which should:

Task 0:
Abeautiful code that passes the Betty checks.

Task 1:
Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
Handle the “end of file” condition (Ctrl+D).

Task 2:
Simple shell 0.1 + should:
Handle command lines with arguments.

Task 3:
Simple shell 0.2 + should:
Handle the PATH.
fork must not be called if the command doesn’t exist.

Task 4:
Simple shell 0.3 + should:
Implement the exit built-in, that exits the shell.
Usage: exit.
You don’t have to handle any argument to the built-in exit.

Task 5:
Simple shell 0.4 + should:
Implement the env built-in, that prints the current environment.

Task 6:
Simple shell 0.1 + should:
Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline.
You don’t have to be able to move the cursor

Task 7:
Simple shell 0.2 +:
You are not allowed to use strtok

Task 8:
Simple shell 0.4 + should:
handle arguments for the built-in exit
Usage: exit status, where status is an integer used to exit the shell

Task 9:
Simple shell 1.0 + should:
Implement the setenv and unsetenv builtin commands:
setenv
Initialize a new environment variable, or modify an existing one
Command syntax: setenv VARIABLE VALUE
Should print something on stderr on failure
unsetenv
Remove an environment variable
Command syntax: unsetenv VARIABLE
Should print something on stderr on failure

Task 10:
Simple shell 1.0 + should:
Implement the builtin command cd:
Changes the current directory of the process.
Command syntax: cd [DIRECTORY]
If no argument is given to cd the command must be interpreted like cd $HOME
You have to handle the command cd -
You have to update the environment variable PWD when you change directory
man chdir, man getcwd

Task 11:
Simple shell 1.0 + shoudl:
Handle the commands separator ";"

Task 12:
Simple shell 1.0 + should:
Handle the && and || shell logical operators

Task 13:
Simple shell 1.0 + should:
Implement the alias builtin command
Usage: alias [name[='value'] ...]
alias: Prints a list of all aliases, one per line, in the form name='value'
alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value

Task 14:
Simple shell 1.0 + should:
Handle variables replacement
Handle the $? variable
Handle the $$ variable

Task 15:
Simple shell 1.0 + should:
Handle comments (#)

Task 16:
Simple shell 1.0 + should:
Your shell can take a file as a command line argument
The file contains all the commands that your shell should run before exiting
The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from stdin

Simple Shell project
by Warrior Govender and Gabriela da Silva

In this project we have Created a simple shell which should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
Handle the “end of file” condition (Ctrl+D).

Simple shell 0.1 + should:
Handle command lines with arguments.

Simple shell 0.2 + should:
Handle the PATH.
fork must not be called if the command doesn’t exist.

Simple shell 0.3 + should:
Implement the exit built-in, that exits the shell.
Usage: exit.
You don’t have to handle any argument to the built-in exit.

2Simple shell 0.4 + should:
Implement the env built-in, that prints the current environment.

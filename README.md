# Simple Shell
___
#### A simple UNIX command interpreter.

![Alt](https://github.com/BongweKE/simple_shell/blob/main/imgs/simple_shell.png?raw=true)

![Build Status](https://img.shields.io/github/directory-file-count/BongweKE/simple_shell?style=flat-square) ![Build Status](https://img.shields.io/github/languages/count/BongweKE/simple_shell?color=red&style=flat-square) ![Build Status](https://img.shields.io/github/languages/top/BongweKE/simple_shell?color=green&style=flat-square)


This shell program is developed using the C programming language. It has the exact same output as sh (/bin/sh) as well as the exact same error output.

## Usage
`./simple_shell`
The above command runs the executable file that opens up the shell environment where all the input commands are executed. An example of its operation is illustrated below.
```sh
root@pc: ./simple_shell
$ ls
/tmp /bin /root
$ mkdir new_folder
$ ls
/tmp /bin /root /new_folder
$ exit
root@pc:
```
An indepth description of the files in this repo are as follows:

#### main.h
main.h is the header file that comtains all function declarations are done and library dependencies are called. It has been protected from double inclusion using preprocessors.
#### main.c
This is where the main function of the program resides.
`int main(void);`
The function is responsible for creating the shell environment, forking child processes each time a command is entered and aborting the child process once the command has been executed. It utilizes the Fork() function to do that.
![Alt](https://github.com/BongweKE/simple_shell/blob/main/imgs/pg%201%20simple_shell-simple%20shell%20ui.drawio.png?raw=true)
The function returns 0 on success.
#### shell.c
shell.c through its function run() takes in the full command from the user and breaks them into atomic commands and their respective arguments and/or flags for execution. The function is described below.\
`void run(char *input);`\
`@input`: the line from shell prompt\
Using the function strtok() of the string.h library the command breakdown implementation is as follows:\
i)We use single space between prompt string to separate the string in the strtok arguments.\
ii) create argv to be the array to hold commands in atomic form and do a malloc check for it.\
iii) after populating it with given args, ensure argv array is NULL terminated and pass the resultant array argv to which command to check the path of the executable in the given system.\
The function returns nothing given that it is of void return type.
#### which.c
which.c through its function which() takes in the broken down commands, arguments and flags from shell.c as an array, uses the first element (the command) and checks its validity using the stat() function if the libararies sys/types.h, sys/stat.h and unistd.h. This is done by appending the command to the path values of the shell's environment and checking if it is an executable.\
`char *which(char **cmd);`\
`@cmd`: The array of broken down string (commands) received from shell.c for processing.\
The function return either the exceutable path, or (nil) if none is found.
![Alt](https://github.com/BongweKE/simple_shell/blob/main/imgs/simple_shell-_which.jpg?raw=true)
#### fork.c
fork.c throught its function Fork() creates duplicate process for the calling process. The new process is called the child process. This function is used in creating new child processes that prompt for user commands once one commands have been exceuted.\
`pid_t Fork(void);`\
The function returns the process ID of the child process if successful otherwise, outputs an error.
#### execve.c
execve.c executes a different program in the calling program using its Execve() function.\
`void Execve(char *argv[], char **environ)`\
`@argv`: The arguments of that program, including its path as the first index.\n
`@environ`: The environment variables for the program.\
The Execve() function utilizes the execve() function of the unistd.h library in executing the other program. It also listens for specific kinds of command entered.  and executes then accordingly. For example, 'exit' command is used to exit the shell environment.
![Alt](https://github.com/BongweKE/simple_shell/blob/main/imgs/simple_shell-execve%20call.jpg?raw=true)
The function returns nothing.
#### error.c
error.c outputs error messages in the standard output when errors are encoutered in the program.\
`void unix_error(char *msg);`\
`@msg`: The error message that should be output.\
The function returns nothing.


# ICS 2305 - Systems Programming Assignment Question 1

# Minimal Shell (msh)

## Author
Name: Tamara Zawadi 
Reg No: SCT212-0080/2024

## Overview

This project involves the implementation of a minimal, dependable command-line shell called `msh` for an embedded Linux training lab, using the C programming language.
The shell provides an onteractive command-line interface that shows clearly how Unix runs programs and  allows users to execute programs.

## How to Build and Run

###Prerequisites
- Linux operating system.
- GCC compiler.
- GNU Make (if using the Makefile)
- Git.

### Clone the Repository
git clone https://github.com/TamaraZawadi/msh-SCT212-0080-2024.git

### Change the directory to your cloned repo
cd msh-SCT212-0080-2024

### Compile using GCC
gcc -Wall -Wextra -o msh msh.c

### Run the Shell
./msh


## Features Implemented
The shell will implement the following features:

1. Command prompt and user input using getline() and free() : **Completed**
2. Command parsing using strtok() and an array of pointers  : **Completed**
3. External command execution using fork(), execvp() and waitpid() : **Completed**
4. Built-in commands (`cd[dir]`, `help`, `exit.cd`)using chdir and getenv : **Completed**


### Why cd cannot be an external program

cd must be a built-in command because if implemented as an external executable, it would call "chdir()" which
affects only the process that calls it.
If cd were executed as an external command in a child process created by fork(), only the child's working directory
 would change but the parent shell would remain in its original directory.

5. Exit status handling using WIFEXITED(), WEXITSTATUS() and WIFSIGNALED() : **Completed**
6. Background process execution using & and WNOHANG   : **Completed**
7. Output redirection using open(), dup2() and close() : **Completed**
8. Signal handling using SIGINT : **Completed**

   
## Design Explanation
The mini shell (msh) is implemented in C and follows the basic structure of a Unix command-line interpreter. Its main function runs a continuous loop that displays a prompt, reads user input, processes commands and executes external programs.

The getline() function is used to read input dynamically, allowing commands of different lengths. The allocated memory is released using free() when the shell exits. Command parsing is performed using strtok(), which separates the input into individual arguments using spaces, tabs and newline characters. These arguments are stored in an array of pointers, with a NULL terminator required by execvp().

Built-in commands are handled directly by the shell. The cd command uses chdir() to change the shell's working directory, while getenv() retrieves the HOME directory when no destination is provided. The help command displays available built-in commands, and exit terminates the shell.

External commands are executed using process creation and management functions. The shell calls fork() to create a child process, which then uses execvp() to execute the requested program. The parent process uses waitpid() to wait for foreground processes and retrieve their exit status.

The shell also supports background execution through the & operator. Background processes are started without blocking the prompt, and waitpid() with WNOHANG is used to check for completed background processes. Output redirection is implemented using open(), dup2() and close() in the child process. Signal handling allows the shell to ignore SIGINT while child processes restore the default signal behaviour, enabling Ctrl+C to interrupt a running command without terminating the shell.


## Known Limitations
- No pipelines or command chaining, Only a single command per line is supported.
- Background processes are checked for completion using waitpid() with WNOHANG when the shell returns to the main input loop. A completed background process may remain a zombie while the shell is waiting for new input.
- Output redirection supports > for creating or truncating files. It does not support append redirection (>>), input redirection (<) or pipes (|).
- The shell does not implement advanced features such as command history, tab completion or command chaining.
- Arguments containing spaces inside quotes (e.g., echo "hello world") are split into separate tokens by strtok().


## Sources and AI tool declaration
### Sources
- ICS 2305 Systems Programming Practical Assignment (13 November 2026), Question 1.
https://piazza.com/class_profile/get_resource/mtvs/m59uyn4ue/mwd8lia7rgm/11

- Linux man pages for getline(), strtok(), fork(), execvp(), waitpid(), chdir(), getenv(), open(), dup2(), close() and signal handling.

### AI-tool declaration
- ChatGPT was used tool to clarify assignment requirements explain C programming and Unix system calls, assist with debugging, and review the project documentation.

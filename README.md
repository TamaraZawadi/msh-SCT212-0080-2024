
#ICS 2305 - Systems Programming Assignment Question 1

# Minimal Shell (msh)

##Author
Tamara Zawadi - SCT212-0080/2024

## Overview

This project involves the implementation of a minimal, dependable command-line shell called msh for an embedded Linux training lab, using the C programming language.
The shell provides a command-line interface that shows clearly how Unix runs programs and  allows users to execute programs.

## How to Build and Run

###Prerequisites
- Linux operating system.
- GCC compiler.
- GNU Make.
- Git.

###Clone the Repository
git clone https://github.com/TamaraZawadi/msh-SCT212-0080-2024.git
###Change the directory to your cloned repo
cd msh-SCT212-0080-2024

###Build the project
make

###Run the Shell
./msh

###Clean build files
make clean

## Features Implemented
The shell will implement the following features:

1. Command prompt and user input using getline() and free() : Completed
2. Command parsing using strtok() and an array of pointers  : Completed
3. External command execution using fork(), execvp() and waitpid() : Completed
4. Built-in commands (`cd[dir]`, `help`, `exit.cd`)using chdir and getenv : Completed

###Why cd cannot be an external program

cd must be a built-in command because if implemented as an external executable, it would call "chdir()" which
affects only the process that calls it.
If cd were executed as an external command in a child process created by fork(), only the child's working directory
 would change but the parent shell would remain in its original directory.

5. Exit status handling using WIFEXITED(), WEXITSTATUS() and WIFSIGNALED() : Completed
6. Background process execution using & and WNOHANG   : Not attempted
7. Output redirection using open(), dup2() and close() : Not attempted
8. Signal handling using SIGINT : Not attempted

##Design Explanation (200 to 400 words)


##Known Limitations


##Sources and AI tool declaration
###Sources
- ICS 2305 Systems Programming Practical Assignment (13 November 2026), Question 1.
https://piazza.com/class_profile/get_resource/mtvs/m59uyn4ue/mwd8lia7rgm/11

- Linux man pages.

###AI-tool declaration
- ChatGPT was used tool to clarify assignment requirements

# 0x15. C - Simple Shell
---
## Description
* Write a simple UNIX command interpreter.
* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?
## Files
---
File|Task
---|---
builtins.c | exiteme, printenv, cd - functions
env.c | function to write env
exec.c | execute command
getcommand.c | functions get_line, split_line - gets input from stdin
getpath.c | functions get_env, dirTok, checkPath - gets PATH from environment
looper.c | main loop to initiate shell
prompt.c | print prompt
shell.c | main function
shell.h | header with libraryies and prototypes
stringhelpers | functions _strcmp, _strdup _strlen
Directory Name | Description
---|---
simple_shell |Write a simple UNIX command interpreter
## Authors
Heindrick Cheung && Damon Nyhan
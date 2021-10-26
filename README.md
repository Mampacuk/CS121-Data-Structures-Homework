# CS121C Data Structures

American University of Armenia

CS121C Data Structures Course Homework Assignments by Alexander Israelyan

## Foreword
### Prerequisites
*	Make sure you have the latest build of `g++`.
*	It is absolutely *NECESSARY* that you have `make` in your shell.
### Structure of Files
*	At the root, folders "HW??" represent the respective homework assignments.
*	In each of them, find respective exercise by the "ex??" folder.
### Testing and Compilation
*	PLEASE use the Makefile for compilation. There are two rules you may be interested in, along with other tools:
	* Running `make`, which will invoke the `all` rule, compiles the program to be turned in.
	* Running `make test`, which will invoke the `test` rule, if present, compiles a tester for the problem to help you evaluate this work.
	* Running `tester.sh` to feed to the program some arguments.
*	There are others standard rules at your disposal, such that `clean`, `fclean`, `re` and so on that are completely interoperable (even though it is preferred if you run this on UNIX-like systems).

## Notes
### General
*	_SCHOOL 42's COMPUTERS HAVE AN OLD VERSION OF `g++` THAT DOESN'T SUPPORT SOME FUNCTIONS OF C++11_. If your compiler is too new, it may spit out compiltation errors, but IT IS NOT MY FAULT. Fix the errors youself.
### Homework 1
*	Notice that in "ex05", the starting coordinates are rather swapped. This shouldn't be an issue though.
### Homework 2
*	PLEASE make your arrays of strings NULL-terminated, following the C-style best practices and conventions. _NOT NULL-TERMINATED MATRICES OF CHARS WON'T WORK!_
*	The analysis of the complexity can be found in the respective folder in the corresponding `analysis.txt` files.
*	Use the `tester.sh` provided by me to test the algorithms! Be wary; they may contain mistakes, so be sure to double-check.
### Homework 3
*	Please be aware that _it's impossible to return a NULL reference to indicate failure of an inspecting function (such as DoublyLinkedList<D>::back(), DoublyLinkedList<D>::front() and so on)_. Thus it is your and only __your__ responsibility if the program causes segmentation fault when you try to call DoublyLinkedList<D>::front() on an empty DoublyLinkedList object. (Note that the alternative textbook uses the same approach)
### Homework 4
*	Please note that several checks about types and boundaries are omitted which is compliant with the textbook solutions.
*	Notice that in "ex03", it's part of _C++ philosophy_ that getting out of bounds of a container is the programmer's responsibility. If a programmer tries to dereference an `end()` iterator, it's a guaranteed segmentation fault and is not the developer's (mine) fault. Thus I do not check for sizes when creating such odd-walking iterators.
Hence usage of `end()` as a delimiter for `begin()` is not possible (you can't initialize a `begin()` and put `end()` as a loop condition) -- this is contradictory to the design of the problem.

## References and Materials
This is a good read if you don't find my code readable:
*	Arguments for `main()` in C-based languages: https://youtube.com/playlist?list=PLVQYiy6xNUxxDlCkkCX262SI90TsllYUW
*	Compilation of C-based programs (also `define`s): https://youtube.com/playlist?list=PLVQYiy6xNUxxMI_GiGGb2hxMcd3IwNYRy
*	Makefiles, as well as Static C Libraries (the `libft` folder you see at the root of my homework): https://youtube.com/playlist?list=PLVQYiy6xNUxw6n6q_i8wek6U7t7CeAXhU
*	Makefile manual: https://www.gnu.org/software/make/manual/make.html
*	Simple bash scripting tutorial, to run my test.sh testers: https://linuxconfig.org/bash-scripting-tutorial
If you're on Windows and you wanna get `g++` with the rest of C-family compilers, follow [this link](https://code.visualstudio.com/docs/languages/cpp).

If you're on Windows and you wanna run a tester.sh, you can use either a virtual machine (say VirtualBox) or Git Bash (note that Git Bash has its quirks and requires additional amendments to the script so it works).

If you're on a Unix-like system and you want to compile using Makefile, if you're using homebrew, do
```
brew install make
```
If you're under Windows then you have to get the aforementioned WIndows port and chocolatey which is the Windows homebrew alternative. After you get it, run
```
choco install make
```
in the PowerShell.

# CS121-DataStructures

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
### Homework 1
*	Notice that in "ex05", the starting coordinates are rather swapped. This shouldn't be an issue though.
### Homework 2
*	PLEASE make your arrays of strings NULL-terminated, following the C-style best practices and conventions. _NOT NULL-TERMINATED MATRICES OF CHARS WON'T WORK!_
*	The analysis of the complexity can be found in the respective folder in the corresponding `analysis.txt` files.
*	Use the `tester.sh` provided by me to test the algorithms! Be wary; they may contain mistakes, so be sure to double-check.
### Homework 3
*	Please be aware that _it's impossible to return a NULL reference to indicate failure of an inspecting function (such as DoublyLinkedList<D>::back(), DoublyLinkedList<D>::front() and so on)_. Thus it is your and only __your__ responsibility if the program causes segmentation fault when you try to call DoublyLinkedList<D>::front() on an empty DoublyLinkedList object.
c207 Week 03:
=======
### Additional guidelines for the LMS Lab Task
In this lab we learn about building a multi-file C project.
Each project should have its own folder, so you should create one
for this sample project. It's a good idea to download all LMS
files (`list.c`, `list.h` and `Makefile`), and all files of this
github site (except for `README.md`), then place them under your
sample project folder.
 
  * Task 1 (Header files): Choose a very simple task for `main-1.c`. 
For example, just create a list that have 10 nodes with data value
from 1 to 10, then remove and print each data. File `main-1.c` in this github
site is a skeleton for that simple task. Note: to add a new node, 
you can first use list_add_start, then list_add_end. 

  * Task 2 (Module making): To make a module for stack, you need to
build 2 files: `stack.h` and `stack.c`. The first contains only 
the description of data type `Stack` (or `stack_t` if you like), and 
the prototype of the functions `new_stack`, `free_stack` ... The second
contains the implementation of the functions. Note that these functions
are very simple - **just a single statement in the body of each function**.
Again, main-2.c should be very simple, such as: insert the number 1, 2, ...,
10 into a queue, then dequeue, print, and push them into a stack, and
finally pop them from the stack and print again. File main-2.c from this
site serves as a skeleton for that simple task.

  * Task 3 (Compiling and linking): Here you should realise 2 different 
ways of compiling a multi-file C project. If we take Task 1 as a project, the first way to compile is:

`gcc -o main-1 main-1.c list.c`

And the second way is to use 3 commands:

1. `gcc -c main-1.c`
1. `gcc -c list.c`
1. `gcc -o main-1 main-1.o list.o`

A good point of the second way is: if you change `main-1.c`, you just need to do step 1 and 3 to compile the whole project.
 No think about this advantage if your project contains hundreds of `.c` files.

  * Task 4 (Makefile): Learn to use automatic compilation with `Makefile`.
If your current folder has a text file `Makefile`, in minGW you can run
command `make`. It will read that `Makefile` and will follow the instructions
 in that file and compile your project. Open and read that `Makefile` and
 try to understand. 

  * Additional task: If you think that the above main-1.c and main-2.c are
 too boring, you can write some other program that have a better use
 of stack/queue. Or you can try to use `postfix.c`. Can you add an extra
 goal into your `Makefile`, called `postfix`, which is for compiling 
 postfix? (remember that postfix is a combination of 3: postfix.c, list.c, 
 and stack.c). Try to modify `Makefile` so that when you run `make postfix` 
 the system will compile postfix for you. Try and enjoy `postfix` with 
 `postfix < postfix_data.txt`. 

How to use this github site?
----------------------------
### If you just want a single file, say, `all.c`:
  * Click on `all.c` and you will see its content 
  * Copy the content and paste into your jEdit/editor window, then save as `all.c`

### If you want to download the whole directory:
  * Download this whole directory by clicking `Clone or Download` --> `Download ZIP`, it will normally be downloaded to your `Downloads` folder under the name `c207-master` or `c207-master.ZIP`
  * Then copy or move the folder `c207` from `Downloads` to under your working folder, say, `week2/`
  * If the downloaded `c207-master` has the extension `.ZIP`, you likely need to expand the zipped file with command `unzip c207-master.ZIP`. If that failes, you probably need to use some other tool to unzip, ask Google.
 
-------------------------------------------------------------
by Anh Vo, anhvir@gmail.com, for use in unimelb COMP20007 workshops.

For a teaching week, a new content is (normally) uploaded at the very beginning of the week, and that content is removed one week later.

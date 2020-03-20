c207 Lab Week 03: C modules
=======
Instructions for this lab:
--------------------------
  * First, goto **`LMS/Canvas-->Modules-->Workshops-->Week3`**.
You can also click [here](https://canvas.lms.unimelb.edu.au/courses/8028/pages/week-3) to navigate to that link.
  * Read (and discuss with your mates to understand) sections 1,2, and 3 of the "Computer Lab" page in **'workshop3.pdf'** (available from the above link).
  * Try to do as required section 3, that is, "create your own Makefile to compile the racecar_test program from Question 2". The steps include:
    * Download and unzip **`lab_files.zip`** from LMS. Alternatively, 
downclod/clone this whole github directory in to your working directory, then you can `cd c207/lab_files` and se the files.
    * Compile the package `lab_files` manually with
```bat
gcc -Wall -o racecar.c
gcc -Wall -o racecar_test.c
gcc -o racecar racecar.o racecar_test.c
```

    * Then, build the Makefile using your editor. When editing, 
note that each target should start from column 0 in the screen, but each associated command **must be preceded by one and only one `<TAB>`**  
    * After having Makefile, you can now run automatic compilation with
```bat
make
```

  * Share your work with your mates, then check if your doing is correct by watching Anh doing the thing.
  * Move on with sections 4 and 5 of the `Computer Lab`. It would be great if you can build the list module by yourselves. Please have a try, at least
to recall how easy/difficult the job could be.


Additional Exercises
--------------------
  * Play with the package `postfix` in this github page. This package:
    * use Alistair's `listopt.c` to build a module for list (`alistair_listops.c` and `alistair_listops.h`),
    * use list module to build a module for stack (`stack.c` and `stack.h`)
    * use stack module to evaluate postfix expressions like 5 3 * (which means 5*3) and 5 3 2 + *  (which means 5*(3+2) )
  * Build Makefile for that postfix package
  * Complete the file `play_list.c` and try it. Add an additional target, named `play` to your `Makefile` for compiling `play_list.c` 
  




How to use this github site?
----------------------------
### If you want to download the whole directory:
  * Download this whole directory by clicking `Clone or Download` --> `Download ZIP`, it will normally be downloaded to your `Downloads` folder under the name `c207-master` or `c207-master.ZIP`
  * Then copy or move the folder `c207` from `Downloads` to under your working folder, say, `week2/`
  * If the downloaded `c207-master` has the extension `.ZIP`, you likely need to expand the zipped file with command `unzip c207-master.ZIP`. If that failes, you probably need to use some other tool to unzip, ask Google.
 
### If you just want to copy a single file, say, **`fibonacci.c`**:
  * Click on `fibonacci.c` and you will see its content in a markup format,
  * Click on **`Raw`** button, and you'll see it in text format, 
  * Copy the text content and paste into your editor window, then save as **`fibonacci.c`** in your local workspace.

-------------------------------------------------------------
by Anh Vo, avo@unimelb.edu.au, for use in unimelb COMP20007 workshops.

For a teaching week, a new content is (normally) uploaded at the very beginning of the week, and that content is removed one week later.

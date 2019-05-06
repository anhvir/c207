c207 Week 09:
=======

  Instructions this week:
--------------- 
  * For this week's lab, follow the instruction in `LMS.Workshop.Week9`. Note that `all files` needed for this lab can be downloaded from that `LMS.Workshop.Week9` thank to great work of our head tutor. 
If you want some hints, read the second part of this document. 

  Hints for lab this week
---------------------------
First at all, of course, create a separate folder for this week's lab. Let's call it `sort` and make it the working directory. You should download all `*.c` and `.h` files supplied in LMS this week to this folder. Then: 
  * You can build `Makefile` by take a copy from assignment 1 and make some trivial changes. OR you can compile with `gcc -Wall -o sort main.c arrays.c sorting.c`. OR, if you believe that you have no foreign files in the folder, you can just compile with `gcc -Wall -o sort *.c`
  * Try the program by running `./sort` and evaluate the output.
  * Now, do the four tasks described in the lab sheet. Note that for Task 1 you can start hybrid_sort() with a copy of function quicksort(), then change it (just a bit) by make a call to insertion_sort() or quicksort() appropriately. Note that you also need ao add some lines to main() in main.c so that it uses your new hybrid_sort().  


How to use this github site?
----------------------------
### If you just want a single file, say, `all.c`:
  * Click on `all.c` and you will see its content 
  * Copy the content and paste into your jEdit/editor window, then save as `all.c`

### If you want to download the whole directory:
  * Download this whole directory by clicking `Clone or Download` --> `Download ZIP`, it will normally be downloaded to your `Downloads` folder under the name `c207-master` or `c207-master.ZIP`
  * Then copy or move the folder `c207` from `Downloads` to under your working folder, say, `week2/`
  * If the downloaded `c207-master` has the extension `.ZIP`, you likely need to expand the zipped file with command `unzip c207-master.ZIP`. If that fails, you probably need to use some other tool to unzip, ask Google.
 
-------------------------------------------------------------
by Anh Vo, anhvir@gmail.com, for use in unimelb COMP20007 workshops.

For a teaching week, a new content is (normally) uploaded at the very beginning of the week, and that content is removed one week later.

c207 Week 09:
=======

  Instructions this week:
--------------- 
  * For this week's lab, follow the instruction in `LMS.Workshop.Week9`. The programming exercise for this week is small, and you should be able to do it from scratch.
If you want some hints, read the second part of this document. 

  Hints for lab this week
---------------------------
Just build a single .c file, a data file, then compile and test.
Some hints are:
  * Remember to break a (even not so long) program into functions for easy management.
  * You might want to have a function, say, `input()`, for reading input data, including a value for `n`, and the array `p[1..n]` of prices. You should use the value n to dynamically allocate memory for the arrays. Ideally the function `input` should return the value n. That also means that the array `p[]` (which has `n+1` elements) must be dynamically allocated within the function `input()`. You can do that with the function header:

     `int input(int **p)`

then, after scanf value for `n`, allocate memory with:
	`*p=  calloc( (n+1) * sizeof ( **p ));`
(remember the rule of `adding one more * to the sizeof`? )

  * What's the difference between `calloc` and `malloc`? They are almost the same, except that `calloc` also zero the memory for you. So:

	`*p=  calloc( (n+1) * sizeof ( **p ));`
      
is effectively equivalent to:
  
	*p=  malloc( (n+1) * sizeof ( **p ));

	for (i=0; i<n+1; i++) *p[i]= 0;



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

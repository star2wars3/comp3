***********************************Files****************************************
Annotated Output: output.txt
Readme: README.txt
********************************************************************************
Email: Aaron_Milgram@student.uml.edu

Steps:

1. Started with the .ll file because almost no changes are necessary to make it work

2. Continued with the .c file because that requires only slghtly more work than
the .ll file.

3. Within the microcode file (the .mc file) first do parsing to determine wether to do
multiplication, right shift, or division.

First I added in the Right Shift Functionality because that is already given to us.

Then I did multipliation. I check for overflow by checking for the wrong sign.

For division first I check the sign of both dividend and divisor.
If the dividend or divisor are negative I set a variable to 1 or -1 accordingly.
If both are the same sign then I set the variable to 0.

Then I set both divisor or dividend to their absolute values, do the positive integer
division, then re-add the signs as needed. In every case including edge cases I set the
remainder into a, the quotient into b, and then call a finalization function that pushes the values
into the stack. and sets ac based on if the division was legal.

I couldn't figure out how to get the program to compile so I don't know if my code works for certain
But I am confident in the algorithm I utilised so I think that the microcode should work. In total I
think that 90% of the project is working.

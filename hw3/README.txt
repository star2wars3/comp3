***********************************Files****************************************
Source Files: hw3.asm
Makefile: N/A
Annotated Output: annotatedOutput.txt
Readme: README.txt
********************************************************************************
Email: Aaron_Milgram@student.uml.edu

Degree of Success: 75

What works: 
Early cases:
0,1,2,3 work but this is just due to
overlap between fibonacci and whatever pattern I ended up coding.

The main function:
This loops through the array of input values and calls the
fibonacci function. 

Problems: While what I created is most definitely recursive (exponentially so),
it doesn't output the fibonacci sequence. Instead, it outputs some sort of exponential
set of numbers.

ex. Numbers 0-9 result in output of:
0,1,1,2,2,4,4,8,8,16

In addition, when I use larger numbers then the amount of time it takes the function to run
becomes exponentially larger. I think that I am  hitting the base case of 1 more than I should be.

For numbers 15 and larger, the output becomes 0. I am unsure which sort of overflow I should attribute this too but currently leaning towards an int overflow. (stack or integer).



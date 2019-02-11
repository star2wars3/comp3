***********************************Files****************************************
Source Files: main.c, input.txt
Makefile: Makefile
Annotated Output: annotatedOutput.txt
Readme: README.txt
********************************************************************************
Email: Aaron_Milgram@student.uml.edu

Degree of Success: 75

To start off, I know that the final result my program outputs is incorrect. However,
I believe that my algorithm is almost working.

The basics steps involved are as follows, first shift the mantissa to the left until it aligns with the mantissa with the smaller exponent.

Then add the mantissas together. After that, reposition the exponents, fix the exponent if necessary and
re-add the bias.

I believe that the biggest issue I ran into was that as I attempted to shift the mantissa to the left,
there were too many cases where bits would overflow. When I first encountered this, my first attempt to try fixing this was to try using a larger object. This didn't fix the issue. 

My next idea was to implement an Integer class which could hold more bytes but this seemed impractical
so I opted against it.

I just realized that I should have shifted the smaller of the mantissa rather than the larger one.
This seems to have improved the situation somewhat.

Next major issue: Ridiculously large numbers. I appear to get extremely large numbers for some sets of input. These numbers appear larger than can be stored in an int so the fact that they exist (albeit not
the culprit of their cause) likely has to do with the dynamically allocated chunk of memory I attempted
to use to try and stop the integer overflow mentioned earlier. Not sure of the cause for this one but its probably why 0 + 0 appears as an absurdly large number.

Beyond that, numbers which are close to their actual results tend to have segments with clear
relations to the floats which they are supposed to be the sum of.

For example 7 + 5.03 comes back as 5.03 (one of the easier to see examples)




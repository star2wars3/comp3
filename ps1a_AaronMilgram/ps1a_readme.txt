/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Aaron Milgram
Hours to complete assignment: 5
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The core of the assignment was to create Linear Feedback Shift Register
and test it using the Boost Libraries. To create a LFSR first you get a 
string of bits and a tap position. To advance the LFSR first compare the
bit at the beginning of the string and at the tap position via xor. Left
the entire string and set the last bit to the result of the xor operation
performed earlier. This results in a set of looping bit strings with 
different "Random" number values.

/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
N/A
/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I went to the IT department to get the Boost Libraries Working
/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
While I installed Boost fairly easily, I struggled to get them working.

Another I encountered was that my original makefile would first try to compile.
the code without flags and would then try to compile with flags. 
(My old makefile was recursive and very generic) However, it
failed without flags then it wouldn't advance to compiling with flags.

My new makefile works but seems to compile code into executables designed 
for a different architecture.
/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
To implement the LFSR, I used a vector<bool>

/*Mia in a Tech competition was assigned a task for writing a function to determine how closely two words resemble
each other.

How will Mia do this task?

Example, the words "TICK" and "TOCK" have a score of 3, since three characters (T, C, K) are the same.

Similarly, "CAT" and "DOG" score 0, since no letters match.

You are given Strings A and B and you have to return an integer K indicating the score (as defined above) of how
closely the two match.

Input :

First line of input contains an integer T denoting the number of test cases. Each test case contains two lines of
input, where first line contains the string A and second line contains the string B.

Output :

For each test case print the score on a line.

Constraints :

A and B will each contain between 1 and 500 characters, inclusive.
Each character of a and b will be 'A'-'Z'.
1 <= T <= 50
TEST CASE 1

INPUT
3
TICK
TOCK
CAT
DOG
APPLE
APPLES  
FANTASTIC
ANTASTIC
OUTPUT
3
0
5
TEST CASE 2

INPUT
4
TICK
TOCK
CAT
DOG
APPLE
APPLES  
FANTASTIC
ANTASTIC
OUTPUT
3
0
5
0
*/
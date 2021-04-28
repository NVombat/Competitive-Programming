/*Codeforces - 32B
Ternary numeric notation is quite popular in Berland. To telegraph the ternary number the Borze alphabet is used.
Digit 0 is transmitted as «.», 1 as «-.» and 2 as «--». You are to decode the Borze code, i.e. to find out the ternary
number given its representation in Borze alphabet.

Input
The first line contains a number in Borze code. The length of the string is between 1 and 200 characters.
It's guaranteed that the given string is a valid Borze code of some ternary number (this number can have
leading zeroes).

Output
Output the decoded ternary number. It can have leading zeroes.

Examples
input
.-.--

output
012

input
--.

output
20

input
-..-.--

output
1012
*/

//CODE:

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Scan Input String
    string st;
    cin >> st;

    //Run for each character in the string
    for(int i=0; i<st.length(); i++)
    {
        //If the current character is a '.' -> Borze equivalent = 0
        if(st[i]=='.')
            cout << "0";
        //If the current character is a '-' and the following character is a '.' -> Borze equivalent = 1
        if(st[i]=='-' and st[i+1]=='.')
        {
            cout << "1";
            //We increment 'i' so we can skip the current and next characters and move two steps ahead
            //This is because our if statement checks two indices in the array
            i++;
        }
        //If the current character is a '-' and the following character is also a '-' -> Borze equivalent = 2
        if(st[i]=='-' and st[i+1]=='-')
        {
            cout << "2";
            //We increment 'i' so we can skip the current and next characters and move two steps ahead
            //This is because our if statement checks two indices in the array
            i++;
        }
    }

    return 0;
}
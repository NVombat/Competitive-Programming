/* The grandest stage of all, Wrestlemania XXX recently happened. And with it, happened one of the biggest
heartbreaks for the WWE fans around the world. The Undertaker's undefeated streak was finally over.
Now as an Undertaker fan, you're disappointed, disheartened and shattered to pieces. And Little Jhool doesn't
want to upset you in any way possible. (After all you are his only friend, true friend!) Little Jhool knows that
you're still sensitive to the loss, so he decides to help you out.

Every time you come across a number, Little Jhool carefully manipulates it. He doesn't want you to face numbers which
have "21" as a part of them. Or, in the worst case possible, are divisible by 21.

If you end up facing such a number you feel sad... and no one wants that - because you start chanting "The streak is
 broken!" , if the number doesn't make you feel sad, you say, "The streak lives still in our heart!"

Help Little Jhool so that he can help you!

Input Format:
The first line contains a number, t, denoting the number of test cases.
After that, for t lines there is one number in every line.

Output Format:
Print the required string, depending on how the number will make you feel.
TEST CASE 1

INPUT
3
120
121
231
OUTPUT
The streak lives still in our heart!
The streak is broken!
The streak is broken!
TEST CASE 2

INPUT
4
69521
7484
78175
86424
OUTPUT
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
 */

//CODE:
#include <iostream>
using namespace std;

//Check Function Declaration
bool check(int num);

int main()
{
  //Number of testcases
  int t;
  cin >> t;
  
  //Runs for each test case
  for(int i=0; i<t; i++)
  {
    //Scans Number
    int num;
    cin >> num;
    //If number is divisible by 21
    if(num%21==0)
    {
      cout << "The streak is broken!" << endl;
    }
    else
    {
      //Call check function
      if(check(num))
      {
        cout << "The streak is broken!" << endl;
      }
      else
      {
        cout << "The streak lives still in our heart!" << endl;
      }
    }
  }
}

//Check function - checks if number contains a '21'
bool check(int num)
{
  bool flag = true;
  while(flag)
  {
    //If number is less than 21 exit function
    if(num<21)
    {
      flag = false;
    }
    else
    {
      //Take 2 digits at a time from the right
      int val = num%100;
      //If 21 then return true
      if(val==21)
      {
        return true;
      }
      //Divide by 100 to look at the rest of the number as ints round off
      num = num/100;
    }
  }
  //Return false if function is exited
  return false;
}  
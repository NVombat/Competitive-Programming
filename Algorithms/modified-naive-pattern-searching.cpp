/*Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all
occurrences of pat[] in txt[].

You may assume that n > m. Consider a situation where all characters of pattern are different.
TEST CASE 1

INPUT
AABCD
ABCD
OUTPUT
Pattern found at index 1
TEST CASE 2

INPUT
ABCEABCDABCEABCD
ABCD
OUTPUT
Pattern found at index 4
Pattern found at index 12
*/

//CODE:
#include <iostream>
using namespace std;

void search(string str, string pat)
{
  //Thus at each character of the string it checks for the pattern
  //Run for length of the string
  for(int i=0; i<str.length(); i++)
  {
    int j;
    //Run for length of pattern
    for(j=0; j<pat.length(); j++)
    {
      //If pattern is not present break and move to next char of string to check pattern again
      if(pat[j]!=str[i+j])
        break;
    }
    //If j increments to length of pattern -> it means pattern was found
    //Thus print i -> Index where pattern started
    if(j==pat.length())
      cout << "Pattern found at index " << i << endl; 
  }
}

int main()
{
  //Scan String and Pattern
  string str, pat;
  cin >> str >> pat;
  
  //Call search function
  search(str, pat);
  return 0;
}
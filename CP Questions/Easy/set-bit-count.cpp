/*Given a positive integer n, count the total number of set bits in binary representation of all
numbers from 1 to n.
TEST CASE 1

INPUT
8
OUTPUT
Total set bit count is 13
TEST CASE 2

INPUT
12
OUTPUT
Total set bit count is 22
*/

//CODE:

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

//Returns the number of 'ones' in the binary number (list)
int countOnes(list<int> x)
{
  //cnt - counts the number of 1s
  int cnt = 0;
  //Takes in a list as a parameter
  for(auto it=x.begin(); it!=x.end(); ++it)
  {
    //If element of list is a 'one'
    if(*it==1)
    {
      //increment count
      cnt++;
    } 
  }
  //Return the count variable
  return cnt;
}

//Converts number n to binary and returns a list containing the binary number
list<int> toBinary(int n)
{
  //List to store the binary number
  list<int> l;
  //Performs operations till number is greater than 0
  while(n>0)
  {
    //Divide number by 2 and push the remainder into list
    l.push_front(n%2);
    n/=2;
  }
  
  //Return list
  return l;
}

int main() 
{
  //Scans number
  int n;
  cin >> n;
  //Keeps count of total number of ones
  int cnt = 0;
  //Runs from 1 to n
  for(int i=1; i<=n; i++)
  {
    //Convers number to binary and adds number of ones to cnt
    list<int> l = toBinary(i);
    cnt += countOnes(l);
  }
  //Prints final count
  cout << "Total set bit count is " << cnt;
  
  return 0;
}

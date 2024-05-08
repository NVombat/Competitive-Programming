/*David has been acting weird for a few days. You finally come to know that its because his proposal has been rejected.

He is trying hard to solve a problem but because of the rejection he can't really focus. Can you help him? The
question is: Given a number n , find if n can be represented as the sum of 2 desperate numbers (not necessarily different),
where desperate numbers are those which can be written in the form of (a*(a+1))/2 where a > 0 .

Input :

The first input line contains an integer n (1<=n<=10^9).

Output :

Print "YES" (without the quotes), if n can be represented as a sum of two desperate numbers, otherwise print "NO"
(without the quotes).

TEST CASE 1

INPUT
45
OUTPUT
NO
TEST CASE 2

INPUT
256
OUTPUT
YES
*/

//CODE:
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
  //Scan Number
  long long n;
  cin >> n;
  
  //Create vector to store the desperate numbers
  vector<int> v;
  
  //Store all the desperate numbers in the vector
  for(int a=1; a<n; a++)
  {
    v.push_back((a*(a+1))/2);
  }
  
  //Start and end are variables to keep track of the index of the vectors
  //Start is the start of the vector and end is the end index of the vector
  //We add the first and last numbers of the vector
  int start = 0, end = v.size()-1;

  //Runs the loop till we reach the middle or reach an element for the second time
  while(start<=end)
  {
    //If the first and last element sum is less than the number
    if((v[start]+v[end])<n)
      //Increment start to the next element 
      start++;
    //If the first and last element sum is more than the number
    else if((v[start]+v[end])>n)
      //Decrement end
      end--;
    //If it adds up to the number 
    else
    {
      //Print yes
      cout << "YES" << endl;
      break;
    }
  }
  
  //If end exceeds start (start becomes greater than end)
  if(start>end)
    cout << "NO" << endl;
  
  return 0;
}
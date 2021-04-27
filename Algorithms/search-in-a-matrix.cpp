/*Given an n x m matrix, where every row and column is sorted in increasing order, and a number x .

The task is to find whether element x is present in the matrix or not.

Expected Time Complexity : O(m + n)

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each
test case consists of three lines.
First line of each test case consist of two space separated integers N and M, denoting the number of element in a row
and column respectively.
Second line of each test case consists of N*M space separated integers denoting the elements in the matrix in row major
order.
Third line of each test case contains a single integer x, the element to be searched.

Output:

Corresponding to each test case, print in a new line, 1 if the element x is present in the matrix, otherwise simply
print 0.

Constraints:
1<=T<=200
1<=N,M<=30
TEST CASE 1

INPUT
2
3 3
3 30 38 44 52 54 57 60 69
62
1 6
18 21 27 38 55 67
55
OUTPUT
0
1
TEST CASE 2

INPUT
2
3 2
2 16 18 20 25 30
60
4 3
2 30 49 56 57 64 20 10 34 54 63 72
68
OUTPUT
0
0
*/

//CODE:
#include <iostream>
using namespace std;

int main() 
{
  //Scan number of testcases
  int t;
  cin >> t;
  //Run for each testcase
  for(int a=0; a<t; a++)
  {
    //n=rows m=columns in the matrix
    int n, m;
    cin >> n >> m;
    
    //arr = matrix 
    int arr[n][m];
    //Scan matrix values
    for(int b=0; b<n; b++)
    {
      for(int c=0; c<m; c++)
      {
        cin >> arr[b][c];
      }
    }
    
    //x = number to be found in matrix
    int x;
    cin >> x;

    bool flag = false;
    
    //For O(m+n) - Start at the top right of the matrix
    //If element is found set flag to true
    //If element is smaller than current element - move to the left
    //If element is larger than current element - move down
    //Repeat until you go out of bounds - element not present
    int i = 0, j = m-1;
    {
      while(i<n and j>=0)
      {
        //If number is the element
        if(x==arr[i][j])
        {
          flag=true;
          break;
        }
        //If number is larger than element 
        else if(x>arr[i][j])
        {
          i++;
        }
        //If number is smaller than element
        else if(x<arr[i][j])
        {
          j--;
        }
      }
    }
    
    //Check flag values for final output
    if(!flag)
    {
      cout << "0" << endl;
    }
    else
    {
      cout << "1" << endl;
    }
  }
  return 0;
}

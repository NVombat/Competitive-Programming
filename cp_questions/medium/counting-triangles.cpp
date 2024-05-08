/*You are given n triangles.

You are required to find how many triangles are unique out of the given triangles. For each triangle you are given three
integers a,b,c , the sides of a triangle.
A triangle is said to be unique if there is no other triangle with same set of sides.
Note : It is always possible to form triangle with given sides.

INPUT:

First line contains n, the number of triangles. Each of next n lines contain three integers a,b,c (sides of a triangle).

Output:

print single integer, the number of unique triangles.

Constraints:

1 <= n <= 10^5
1 <= a,b,c <= 10^15
TEST CASE 1

INPUT
3
1 2 3
2 3 4
2 4 3
OUTPUT
1
TEST CASE 2

INPUT
5
7 6 5
5 7 6
8 2 9
2 3 4
2 4 3
OUTPUT
1
*/

//CODE: - O(n**2)

//CHECKS COMBINATIONS OF ALL TRIANGLES
#include <iostream>
using namespace std;

int main() 
{
  //Number of triangles
  int n;
  cin >> n;
  
  //Scan all the sides into a 2D array
  //Rows are individual triangles with 3 sides
  //Columns are indiviual sides
  int arr[n][3];
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<3; j++)
    {
      cin >> arr[i][j];
    }
  }
  
  //Uniq Boolean Array stores whether the particular triangle is unique or not
  bool uniq[n];
  //Set all to true initially
  for(int i=0; i<n; i++)
  {
    uniq[i] = true;
  }
  
  int k=0, cnt=0, flag=0;
  //Run for each triangle from 0 to n-1
  for(int i=0; i<n-1; i++)
  {
    //If triangle is not unique then skip and go to next triangle
    //cout << "I = " << i << "---------------------------" << endl;
    if(uniq[i]==false)
    {
      //cout << "SKIPPING CUZ FALSE" << endl;
      continue;
    }
    
    //Run for each triangle from 1 to n 
    for(int p=i+1; p<n; p++)
    {
      //If triangle is not unique then skip and go to next triangle
      //cout << "P = " << p << "---------------------------" << endl;
      if(uniq[p]==false)
      {
        //cout << "SKIPPING CUZ FALSE" << endl;
        continue;
      }
      //Compare all the sides of triangle arr[p] to arr[i]
      //k and j traverse the sides of the triangle
      for(int j=0; j<3; j++)
      {
        //If one of the sides match
        //cout << "Loop Iteration: " << j << endl;
        if(arr[i][k]==arr[p][j])
        {
          //Increment k to go to the next side for triangle arr[i]
          //cout << "K: " << k << endl;
          k++;
          //Set j to -1 so it can start from the 0th side of triangle arr[p]
          j=-1;
          //Flag keeps track of how many sides match
          flag++;
          //cout << "Flag: " << flag << endl;
          //Break out of loop if flag is 3 cuz all sides match
          if(flag==3)
            break;
        }
      }
      //If all sides match then flag is 3
      if(flag==3)
      {
        //This means both arr[i] and arr[p] are not unique this set their values of uniq[i] and uniq[p] to false
        uniq[i] = false;
        uniq[p] = false;
        //cout << "SAME!!" << endl;
        //Reset values of k and flag
        k=0;
        flag = 0;
      }
      else
      {
        //Reset values of k and flag
        //cout << "NOT SAME!!" << endl;
        k=0;
        flag=0;
      }
    }
  }
  
  //Count the number of triangles which are still unique
  //If uniq[i] is true then triangle is unique
  for(int i=0; i<n; i++)
  {
    if(uniq[i]==true)
      cnt++;
  }
  //Print final answer
  cout << cnt << endl;
  return 0;
}
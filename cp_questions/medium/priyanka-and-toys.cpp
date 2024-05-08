/*Little Priyanka visited a kids' shop. There are N toys and their weight is represented by an array W=[w1, w2,...,wN].
Each toy costs 1 unit, and if she buys a toy with weight w', then she can get all other toys whose weight lies
between [w',w'+4] (both inclusive) free of cost.

Input Format:
The first line contains an integer N i.e. number of toys.
Next line will contain N integers,w1,w2,...,wN , representing the weight array.

Output Format:
Minimum units with which Priyanka could buy all of toys.

Constraints
1 <= N <= 10^5
0 <= wi <= 10^4, where i belongs to [1,N]
TEST CASE 1

INPUT
5
1 2 3 17 10
OUTPUT
3
TEST CASE 2

INPUT
4
1 2 3 17
OUTPUT
2
*/

//CODE:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //Number of toys
  int n;
  cin >> n;
  
  //Scan toys into array
  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }

  //Set start index at 0
  int start=0;
  //Cnt is the number of toys bought and set to 1 as the first toy is always bought
  int cnt=1;
  
  //Sort the array
  sort(arr, arr+n);
  
  //Traverse the array from the first element
  for(int i=1; i<n; i++)
  {
    //If the ith toy's value is in range of 4 from the start toy then continue
    if(arr[i]-arr[start]<=4)
    {
      continue;
    }
    //If the difference in value of the ith toy and the start toy is greater than 4
    //Buy the toy and set start to that toy and continue
    if(arr[i]-arr[start] > 4)
    {
      cnt++;
      start = i;
    }
  }
  
  //Print the number of toys bought
  cout << cnt << endl;
  
  return 0;
}
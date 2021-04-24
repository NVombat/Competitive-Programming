/*Given an sorted array A[i] of N positive integers having all the numbers occuring exactly twice, except for one
number which will occur only once. Find the number occuring only once.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases
follow. The first line of each test case contains a positive integer N, denoting the size of the array.
The second line of each test case contains a N positive integers, denoting the elements of the
array.


Output
Print out the singly occuring number.


Constraints
1 <= T <= 100
0 < N <= 100
0 <= A[i] <= 100
TEST CASE 1

INPUT
2
5
1 1 2 5 5
7
2 2 5 5 20 30 30
OUTPUT
2
20
TEST CASE 2

INPUT
2
3
1 5 5
5
2 2 5 5 20
OUTPUT
1
20*/

//CODE:
#include <iostream>
using namespace std;

void binarySearch(int arr[], int l, int r);

int main()
{
  //Number of testcases
  int t;
  cin >> t;
  //Runs per testcase
  for(int i=0; i<t; i++)
  {
    //Scans size of each array
    int n;
    cin >> n;
    //Scans array
    int arr[n];
    for(int j=0; j<n; j++)
    {
      cin >> arr[j];
    }
    
    //Use binary search to find element that isnt repeated
    binarySearch(arr, 0, n-1);
  }
  
  //THIS METHOD IS O(N)
    //a,b keep track of two elements at a time in the array that are consecutive
    //Starts with a being the first element and b being the second
    /*int a=0, b=a+1;
    //Runs through the array
    for(int j=0; j<n-1; j++)
    {
      //If the consecutive elements are same then increment a and b by two
      //Thus moving a and b to be the index of the next two elements
      if(arr[a]==arr[b])
      {
        a+=2;
        b+=2;
      }
      else
      {
        //If elements are not the same then first element hasnt been repeated
        //Thus print element and go to next testcase
        cout << arr[a] << endl;
        break;
      }
    }*/
  return 0;
}

//All numbers will occur for the first time on an even index
void binarySearch(int arr[], int l, int r)
{
  //Final element that is not repeated
  if(l==r)
  {
    cout << arr[l] << endl;
    return;
  }
  
  //find midpoint
  int mid = l + (r-l)/2;
  
  //If mid point index is even 
  if(mid%2==0)
  {
    //compare the element to the next element
    if(arr[mid]==arr[mid+1])
    {
      //Search right half if they match
      binarySearch(arr, mid+2, r);
    }
    else
    {
      //Search left half
      binarySearch(arr, l, mid);
    }
  }
  //If mid point index is odd
  else
  {
    //compare mid element with previous element
    if(arr[mid]==arr[mid-1])
    {
      //If they match search right half
      binarySearch(arr, mid+1, r);
    }
    else
    {
      //search left half
      binarySearch(arr, l, mid-1);
    }
  }
}
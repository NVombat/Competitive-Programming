/*Andrew is very fond of Maths.He has N boxes with him,in each box there is some value which represents the Strength of
the Box.The ith box has strength A[i]. He wants to calculate the Overall Power of the all N Boxes.

Overall Power here means Sum of Absolute Difference of the strengths of the boxes(between each pair of boxes) multiplied
by the Maximum strength among N boxes. Since the Overall Power could be a very large number,output the number modulus
10^9+7(1000000007).

Input

First line of the input contains the number of test cases T. It is followed by T test cases. Each test case has 2 lines.
First line contains the number of boxes N. It is followed by a line containing N elements where ith element is the
strength of Andrew's ith box.

Output

For each test case, output a single number, which is the Overall Power for that testcase.

Constraints

1<=T<= 10

2<=N<=10^5

0<=A[i]<=10^9
TEST CASE 1

INPUT
1
3
3 1 2
OUTPUT
12
TEST CASE 2

INPUT
2
2
1 2
5
4 5 3 1 2
OUTPUT
2
100
*/

//CODE:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//MergeSort Function Declaration
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main() 
{
  //Scan number of testcases
  int t;
  cin >> t;
  //Run per testcase
  for(int i=0; i<t; i++)
  {
    //Scan number of elements
    int n;
    cin >> n;
    
    //Scan elements into array
    int arr[n];
    for(int j=0; j<n; j++)
    {
      cin >> arr[j];
    }
    
    //Perform mergesort to sort array
    mergeSort(arr, 0, n-1);
    //sort(arr, arr+n);
    
    //Calculates the sum OF the absolute difference BETWEEN each pair of elements
    int sum = 0;
    for(int x=0; x<n-1; x++)
    {
      for(int y=x+1; y<n; y++)
      {
        //Finds the absolute difference between each pair of elements and adds to sum
        sum += abs(arr[x]-arr[y]);
      }
    }
    //Result is the sum multiplied by the largest number in the array
    int res = ((sum*arr[n-1])%1000000007);
    cout << res << endl;
  }
  return 0;
}

//MergeSort Function
void mergeSort(int arr[], int l, int r)
{
  //If the leftmost index is smaller than the rightmost index
  if(l<r)
  {
    //Mid point
    int m = (l+r)/2;
    //MergeSort left half
    mergeSort(arr, l, m);
    //Merge Sort right half
    mergeSort(arr, m+1, r);
    //Merge all the parts into final sorted array
    merge(arr, l, m, r);
  }
}

//Merges elements into final sorted array
void merge(int arr[], int l, int m, int r)
{
  int i=l; //Starting index of left subarray
  int j=m+1; //Starting index of right sub array
  int k=l; //Starting index for the temp array
  int temp[r+1]; //Temp array to store sorted elements
  
  //Until one of the arrays empties
  while(i<=m && j<=r)
  {
    //If element in left subarray is smaller than element in right subarray
    if(arr[i]<=arr[j])
    {
      //Smaller element from left subarray is put into temp array
      temp[k] = arr[i];
      //We move to next index of the left sub array and the temp array
      i++;
      k++;
    }
    else
    {
      //smaller element from right sub array is put into temp array
      temp[k] = arr[j];
      //We move to the next index of the right sub array and temp array
      j++;
      k++;
    }
  }
  
  //We empty the remaining elements of the left sub array into temp
  while(i<=m)
  {
    temp[k] = arr[i];
    i++;
    k++;
  }
  
  // We empty the remaining elements of the right sub array into temp
  while(j<=r)
  {
    temp[k] = arr[j];
    j++;
    k++;
  }
  
  //Finally we assign the orginal array to be temp
  for(int s=l; s<=r; s++)
  {
    arr[s] = temp[s];
  }
}
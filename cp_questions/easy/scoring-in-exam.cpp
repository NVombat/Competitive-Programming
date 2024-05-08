/*Milly is at the examination hall where she is reading a question paper. She checked the question paper and discovered
that there are N questions in that paper. Each question has some score value. Ideally it's like questions requiring more
time have more score value and strangely no two questions on the paper require same time to be solved.

She is very excited by looking these questions. She decided to solve K questions while maximizing their score value.
Could you please help Milly to determine the exact time she needs to solve the questions.

Input

First line of input contains two space separated integers N and Q, where N is the number of questions available and Q is
number of queries
Next line contains N space separated integers denoting the time Ti of N questions
Next line contains N space separated integers denoting the scores Si of N questions
Next Q lines contains a number K each, the number of questions she wants to solve
Output

Print the time required for each query in a separate line.
Constraints

1 <= N <= 105
1 <= Q <= 105
1 <= K <= N
1 <= Ti, Si <= 109
TEST CASE 1

INPUT
5 2
2 3 9 4 5
3 5 11 6 7
5
3
OUTPUT
23
18
TEST CASE 2

INPUT
6 4
3 5 1 7 4 2
5 7 3 9 6 4
5 
2
4
6
OUTPUT
21
12
19
22
*/

//CODE:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
  //Scan number of questions and queries
  int n, q;
  cin >> n >> q;
  
  //Scan time and marks
  int time[n], marks[n];
  for(int i=0; i<n; i++)
  {
    cin >> time[i];
  }
  for(int i=0; i<n; i++)
  {
    cin >> marks[i];
  }
  
  //sort time in descending order - greater() - puts greater element first
  sort(time, time+n, greater<int>());
  //we dont need to keep track of both arrays as the time is directly proportional to the marks
  
  //Run per query
  for(int x=0; x<q; x++)
  {
    int query, sum=0;
    //Scan each query
    cin >> query;
    //Add those many elements and print the final total time
    for(int j=0; j<query; j++)
    {
      sum = sum + time[j];
    }
    cout << sum << endl;
  }
  return 0;
}
//Can also use descending order InsertionSort
/*
void inSort(int arr[], int n)
{
  int i, j, key;
  for(i=1; i<n; i++)
  {
    key = arr[i];
    j=i-1;
    
    while(j>=0 and arr[j]<key)
    {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}*/
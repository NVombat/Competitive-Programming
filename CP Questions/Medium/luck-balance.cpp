/*Lena is preparing for an important coding competition that is preceded by N sequential preliminary contests. She
believes in "saving luck", and wants to check her theory. Each contest is described by two integers, Li and Ti :

1. Li is the amount of luck that can be gained by winning the contest. If Lena wins the contest, her luck balance will
decrease by Li; if she loses it, her luck balance will increase by Li.
2. Ti denotes the contest's importance rating. It's equal to 1 if the contest is important, and it's equal to 0 if it's
unimportant.
If Lena loses no more than K important contests, what is the maximum amount of luck she can have after competing in all
the preliminary contests? This value may be negative.

Input Format

The first line contains two space-separated integers, N (the number of preliminary contests) and K (the maximum number
of important contests Lena can lose), respectively.

Each line i of the N subsequent lines contains two space-separated integers, Li (the contest's luck balance) and Ti
(the contest's importance rating), respectively.

Constraints
1<=N<=100
0<=K<=N
1<=Li<=10^4
0<=Ti<=1
Output Format

Print a single integer denoting the maximum amount of luck Lena can have after all the contests.
TEST CASE 1

INPUT
6 3
5 1
2 1
1 1
8 1
10 0
5 0
OUTPUT
29
TEST CASE 2

INPUT
2 1
1 1
8 1
10 0
5 0
OUTPUT
7
*/

//CODE:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //Number of contests n, max number of important losses k, and luck l;
  int n, k, l=0;
  cin >> n >> k;
  
  //Scan the luck balance and whether it is important or not in two separate arrays
  int arr[n], imp[n];
  for(int i=0; i<n; i++)
  {
    cin >> arr[i]  >> imp[i];
    //IF the contest isnt important then add it to the luck and set that luck balance to 0
    if(imp[i]==0)
    {
      l+=arr[i];
      arr[i]=0;
    }
  }
  
  //Sort the luck array now in descending order
  sort(arr, arr+n, greater<int>());
  
  //we can lose k contests 
  int ind=0;
  while(k--)
  {
    //Add the luck of those lost contests to the total luck
    l+=arr[ind];
    ind++;
  }
  
  //Subtract the remaining luck from the total luck as we have to win the remaining contests
  while(ind<n)
  {
    l-=arr[ind];
    ind++;
  }
  
  //Output final total luck 
  cout << l << endl;
  return 0;
}
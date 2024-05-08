/*Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and
in each round Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or
equal to M(<=M).

After each round, All the soldiers who are dead in previous round will reborn.Such that in each round there will be N
soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each
round and total sum of their powers.

1<=N<=10000

1<=power of each soldier<=100

1<=Q<=10000

1<=power of bishu<=100
TEST CASE 1

INPUT
4
1 2 3 4
3
3
10
2
OUTPUT
3 6
4 10
2 3
TEST CASE 2

INPUT
7
1 2 3 4 5 6 7
3
3
10
2
OUTPUT
3 6
7 28
2 3
*/

//CODE:

#include <iostream>
using namespace std;

int main() 
{
  //Number of soldiers
  int n;
  cin >> n;
  
  //Scan soldier powers into array
  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }
  
  //Number of rounds
  int q;
  cin >> q;
  //For each round
  while(q--)
  {
    //Scan power of Bishu
    int p;
    int sum = 0, cnt = 0;
    cin >> p;
    for(int i=0; i<n; i++)
    {
      //If power is more than soldiers
      if(p>=arr[i])
      {
        //Add sum and inc count 
        cnt++;
        sum+=arr[i];
      }
    }
    //Output final sum and count
    cout << cnt << " " << sum << endl;
  }
  return 0;
}
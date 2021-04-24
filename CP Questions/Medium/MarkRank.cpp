/*All the students who give test can score from 1 to 10^18. Lower the marks , better the Rank. Now instead of directly
telling the marks of student they have been assigned groups where marks are distributed in continuous intervals, you
have been given l(i) lowest mark of interval i and r(i) highest marks in interval i. So marks distribution in that 
interval is given as l(i), l(i)+1, l(i)+2 . . . r(i).

Now Hermoine ask queries in which she gives rank of the student (x) and you have to tell marks obtained by that student.
Note: rank1 is better than rank2 and rank2 is better than rank3 and so on and the first interval starts from 1.

Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each test case
contains two space separated values N and Q denoting the no of groups and no of queries asked respectively.

The next line contains N group of two integers separated by space which shows lowest marks in group i ie l(i) and
highest marks in group i ie r(i) such that if i < j then r(i) < l(j). The next lines contain Q space separated integers
x, denoting rank of student.


Output:
For each query output marks obtained by student whose rank is x(1<=x<=10^18).


Constraints:
1<=T<=50
1<=N<=10^5
1<=Q<=10^5
1<= l(i) < r(i) <=10^18
1<=x<=10^18

TEST CASE 1

INPUT
1
3 3
1 10 12 20 22 30
5 15 25
OUTPUT
5 16 27
TEST CASE 2

INPUT
1
3 3
1 10 15 20 21 30
5 11 23
OUTPUT
5 15 27
*/

//CODE:
#include <iostream>
using namespace std;

int main() 
{
  //Number of testcases
  int t;
  cin >> t;
  //Run per testcase
  for(int x=0; x<t; x++)
  {
    //Number of lowest marks-highest mark pairs - n =>[1 10], [12 20], [23 30]
    //Number of queries - q
    int n, q;
    cin >> n >> q;
    
    //Scan the sets into a 2D array so each row is a interval
    //Column 1 = lower limit of interval
    //Column 2 = upper limit of interval
    int marks[n][2];
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<2; j++)
      {
        cin >> marks[i][j];
      }
    }
    
    //Rank array stores the marks of the students in order of the ranks
    //Thus if first marks interval is 1-10 then index 1-10 will store that 
    //If second marks interval is 12-20 then index 11-20 will store that
    //therefore index 11 will store 12 and 12, 13 and 13, 14 and so on
    //this carries forward for the next interval as well

    int rank[100] = {0};
    //l is used to index the rank array 1-...
    //k is used to index the marks array to access the intervals one by one 
    int k=0, l=1;
    //Runs for the number of queries
    while(q--)
    {
      //Scans the query
      int r;
      cin >> r;
      //cout << "K: " << k << "-------------------------------------" << endl;
      //Runs from the lowest marks to the highest marks in an interval
      for(int i=marks[k][0]; i<=marks[k][1]; i++)
      {
        //If the query is the same as the index of the rank array [rank of the student]
        if(r==l)
        {
          //Print the marks of that student
          //cout << "YES" << endl;
          cout << i << " ";
          //cout << "l-1: " << rank[l-1] << endl;
          //cout << "l-2: " << rank[l-2] << endl;
          //cout << "l: " << rank[l] << endl;
          //cout << "l+1: " << rank[l+1] << endl;
          //cout << "l+2: " << rank[l+2] << endl;
        }
        //Update the ranks array to set that rank to those marks
        //cout << "I: " << i << endl;
        rank[l] = i;
        //Increment the rank index
        //cout << "-------> " <<  rank[l] << endl;
        //cout << "L: " << l << endl;
        l++;
      }
      
      /*for(int z=1; z<=30; z++)
      {
        cout << rank[z] << "->";
      }
      cout << endl;*/
      //Increment k to go to the next interval of marks
      k++;
    }
  }
  return 0;
}
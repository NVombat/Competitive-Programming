/*You've got a 5 × 5 matrix, consisting of 24 zeroes and a single number one. Let's index the matrix rows by numbers
from 1 to 5 from top to bottom, let's index the matrix columns by numbers from 1 to 5 from left to right. In one move,
you are allowed to apply one of the two following transformations to the matrix:

Swap two neighboring matrix rows, that is, rows with indexes i and i + 1 for some integer i (1 ≤ i < 5).
Swap two neighboring matrix columns, that is, columns with indexes j and j + 1 for some integer j (1 ≤ j < 5).
You think that a matrix looks beautiful, if the single number one of the matrix is located in its middle (in the cell
that is on the intersection of the third row and the third column). Count the minimum number of moves needed to make
the matrix beautiful.

Input
The input consists of five lines, each line contains five integers: the j-th integer in the i-th line of the input
represents the element of the matrix that is located on the intersection of the i-th row and the j-th column. It is
guaranteed that the matrix consists of 24 zeroes and a single number one.

Output
Print a single integer — the minimum number of moves needed to make the matrix beautiful.

Examples
input
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

output
3

input
0 0 0 0 0
0 0 0 0 0
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0

output
1
*/
//CODE:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //5x5 matrix with m rows and n columns (5, 5)
    int m=5, n=5;
    //rc, cc are the coordinates of the centre of the matrix
    int rc=2, cc=2;
    //rx, cx are the coordinates of the position of the 1 in the matrix
    int rx=-1, cx=-1;
    //Flag allows us to break out of the loop as soon as we see a 1 - saves time
    int flag=0;

    //Matrix mxn
    int mat[m][n];
    for(int i=0; i<m; i++) 
    {
        for(int j=0; j<n; j++)
        {
            //Scan elements 
            cin >> mat[i][j];
            //If element scanned is 1
            if(mat[i][j]==1)
            {
                //Store the coordinates(indices) of the position of the 1
                rx=i;
                cx=j;
                //cout << rx << "-->" << cx << endl;
                //Set flag to 1 -> so that we can break out of the loops - as we dont need to scan more
                flag=1;
            }
        }
        //If flag is 1 -> the 1 has been located in the array thus we break out of loop
        if(flag==1)
            break;
    }
    
    //These are the absolute values of the distance from the position of the 1 and the mid point of the matrix
    int a = abs(rc-rx);
    int b = abs(cc-cx);
    //cout << a << "-->" << b << endl;
    
    //Number of steps taken is the sum of a and b
    cout << a+b;

    return 0;
}

/*Codeforces - 266B
During the break the schoolchildren, boys and girls, formed a queue of n people in the canteen. Initially the children
stood in the order they entered the canteen. However, after a while the boys started feeling awkward for standing in
front of the girls in the queue and they started letting the girls move forward each second.

Let's describe the process more precisely. Let's say that the positions in the queue are sequentially numbered by
integers from 1 to n, at that the person in the position number 1 is served first. Then, if at time x a boy stands
on the i-th position and a girl stands on the (i + 1)-th position, then at time x + 1 the i-th position will have a
girl and the (i + 1)-th position will have a boy. The time is given in seconds.

You've got the initial position of the children, at the initial moment of time. Determine the way the queue is going
to look after t seconds.

Input
The first line contains two integers n and t (1 ≤ n, t ≤ 50), which represent the number of children in the queue and
the time after which the queue will transform into the arrangement you need to find.

The next line contains string s, which represents the schoolchildren's initial arrangement. If the i-th position in
the queue contains a boy, then the i-th character of string s equals "B", otherwise the i-th character equals "G".

Output
Print string a, which describes the arrangement after t seconds. If the i-th position has a boy after the needed time,
then the i-th character a must equal "B", otherwise it must equal "G".

Examples
input
5 1
BGGBG

output
GBGGB

input
5 2
BGGBG

output
GGBGB

input
4 1
GGGB

output
GGGB
*/
//CODE:

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Scan number of students in queue and the time through which B and G will switch places
    int n, t;
    cin >> n >> t;

    //Scan the input in a string -> Queue which is represented with 'B' for Boys and 'G' for girls
    string st;
    cin >> st;
    char arr[n];
    //Store each character in the string in the array
    for(int i=0; i<st.length(); i++)
    {
        //We store it in the array so we can swap individual characters later
        arr[i] = st[i];
    }

    //Run for the time t thus complexity = O(t*n)
    while(t--)
    {
        //Each time unit t -> all the boys standing in front of girls swap with the girls behind them
        for(int j=0; j<n; j++)
        {
            //If the current character is a Boy and the next one is a Girl and the Boy isn't the last one in the queue
            if(arr[j]=='B' && j!=n-1 && arr[j+1]=='G')
            {
                //Switch the positions of the boy and girl
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                //Increment j once (two times including for loop) as now we have swapped B and G this we can go past these two
                //We are now to look at the next set of elements
                j++;
            }
            //If the current character is a Girl -> No swapping
            else
                continue;
        }
    }

    //Print result formation in queue after t seconds
    for(int i=0; i<n; i++)
    {
        cout << arr[i];
    }

    return 0;
}

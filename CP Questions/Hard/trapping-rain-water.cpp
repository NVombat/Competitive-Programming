//LEETCODE
//Q -> Given n non-negative integers representing an elevation map where the width of each bar is 1,
//     compute how much water it can trap after raining.

/*
EXPLANATION:
We take an array of non negative integers as input and calculate the size of the array.
We then find the value of the block with maximum height(Maxima) and we find the number of times this occurs in the array.
We also find the index of the last occurring maxima in the array
We then split the problem into two parts: (We do this because of certain types of test cases)
    1)Calculate water trapped from the front to the last maxima
    2)Calculate water trapped from the end to the last maxima
Now to solve 1 and 2...
PART1:
We set a variable called start index at 0 -> This variable represents the block after which water can START getting trapped
We then traverse the array from index 1 to the index where the last occurring maxima is present
If the value of the array at the start index is greater than the next element(since i is always greater than start index), we take the difference between the two values and add that to the water trapped
THIS IS BECAUSE THE HEIGHT OF THE START INDEX BLOCK IS THE MAXIMUM AMOUNT OF WATER ANY COLUMN AFTER IT CAN STORE UNTIL IT COMES ACROSS A TALLER BLOCK THAN THE ONE AT START INDEX
If the value of the array at the start index is less than or equal to the next element, we cant store water so we set Start index to that particular value of i, i automatically increments as part of the for loop
This is repeated till we reach the last occurrence of the maxima

PART2
At this stage we call the reverse_trap function which takes the height array, its size and the index of the last occurring maxima
If the index of the last occurring maxima is the same as the end of the array - we return 0 as the array has ended
Otherwise we do the same procedure as we did in PART1 but backwards till we reach the index of the last occurring maxima

We then add the water we trapped from the front and back and thats the final value of the water trapped
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Calculates the water trapped from the back of the elevation map till the last maxima
int reverse_trap(int arr[], int n, int max_ind)
{
    //If the final maxima occurs at the last index then return 0
    //cout << "ENTERING REVERSE:" << endl << "----------------------" << endl;
    if(max_ind==n-1)
    {
        //cout << "MAXIMA OCCURS AT THE END" << endl << "------------------------" << endl;
        return 0;
    }

    //w = water trapped from the back
    int w = 0;
    //Last index is the same as start index but from the back thus it starts at the end
    int l_i = n-1;
    //Runs from last index till the last maxima
    for(int i=n-2; i>=max_ind; i--)
    {
        //If height at the start index(from back) is greater than the next index -> POSSIBLE TO STORE WATER
        //cout << "L_I: " << l_i << endl << "Reverse I: " << i << endl;
        if(arr[l_i]>arr[i])
        {
            //cout << "POSSIBLE" << endl;
            //Adds water to the total (Diff between the two heights)
            w+=arr[l_i]-arr[i];
            //cout << "Water: " << w << endl;
            //cout << "---------------------------------------------" << endl;
            continue;
        }

        //If height at the start index is equal to or smaller than the next index -> CANT STORE WATER
        else if(arr[l_i]<=arr[i])
        {
            //Updates l_i and moves to next iteration
            //cout << "NOT POSSIBLE CHANGING L_I" << endl;
            //cout << "L_I: " << l_i << endl;
            l_i = i;
            //cout << "NEW L_I: " << l_i << endl;
            //cout << "---------------------------------------------" << endl;
            continue;
        }
    }
    //Returns water stored from the back
    return w;
}

int main()
{
    //Height array for elevation map and size of array
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1}; //{0,1,0,2,1,0,1,3,2,1,2,1,3,2,1,2,1,3,2,1,2,1,3,2,1,2,1}; //{6,9,9}; //{7,4,0,9}; //{3,0,0,2,0,4}; //{4,2,0,3,2,5}; //{1,8,6,2,5,4,8,3,7};
    int s = sizeof(height)/sizeof(height[0]);

    //Finds the maximum height and the number of occurrences
    //Initially max height is first element and count of that element is 1
    int max_num = height[0];
    int max_cnt = 1;
    //Finds the index of the last occurring maxima
    int final_max_ind = 0;

    for(int j=1; j<s; j++)
    {
        //If max height occurs again increment count and set index of final occuring maxima
        if(height[j]==max_num)
        {
            max_cnt++;
            final_max_ind = j;
        }

        //If current height is greater than max height, update max height and set count back to 1 and update index of final occurring maxima
        else if(height[j]>max_num)
        {
            max_num=height[j];
            max_cnt=1;
            final_max_ind = j;
        }
    }
    //cout << "Max Height: " << max_num << " And Max Count: " << max_cnt << endl;

    //Keeps track of water trapped
    int water=0;
    //Starting index  for the calculation of trapped water
    int s_i=0;

    for(int i=1; i<=final_max_ind; i++)
    {
        //If height at the start index is greater than the next index -> POSSIBLE TO STORE WATER
        //cout << "S_I: " << s_i << endl << "I: " << i << endl;
        if(height[s_i]>height[i])
        {
            //Water is incremented to the difference between the height at the start index and the current(next) index
            //cout << "POSSIBLE" << endl;
            water+=height[s_i]-height[i];
            //cout << "Water: " << water << endl;
            //cout << "---------------------------------------------" << endl;
            continue;
        }

        //If height at the start index is equal to or smaller than the next index -> CANT STORE WATER
        else if(height[s_i]<=height[i])
        {
            //Switch start index to the current index and i increments through for loop
            //cout << "NOT POSSIBLE CHANGING S_I" << endl;
            //cout << "S_I: " << s_i << endl;
            s_i = i;
            //cout << "NEW S_I: " << s_i << endl;
            //cout << "---------------------------------------------" << endl;
            continue;
        }
    }
    //cout << "Water till max: " << water << endl << "INDEX OF MAX FINAL: " << final_max_ind << endl;
    //Calls the function to calculate water from the end of the elevation map to the final maxima
    int rev_water = reverse_trap(height, s, final_max_ind);

    //Adds the total water trapped and outputs that value
    water+=rev_water;
    cout << "WATER TRAPPED: " << water << endl;
    //cout << water << endl;
    return 0;
}
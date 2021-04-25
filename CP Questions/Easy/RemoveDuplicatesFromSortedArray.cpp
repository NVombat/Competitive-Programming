/*Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new
length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra
memory.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to
the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 
Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]
Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3,
and 4 respectively. It doesn't matter what values are set beyond the returned length.
*/
//CODE:

#include <iostream>
#include <vector>
using namespace std;

//FUNCTION TO REMOVE DUPLICATES
int removeDuplicates(vector<int>& nums)
{
    //If the array passed is empty then return 0 (print nothing)
    if(nums.size()==0)
        return 0;
    
    //Keep track of two pointers to the array
    int i=0;
    for(int j=1; j<nums.size(); j++)
    {
        //If the element is repeated then move forward to the next element and compare the ith element with it
        if(nums[i]==nums[j])
        {
            continue;
        }
        //As soon as the element is a different one
        else
        {
            //We increment i and then set nums[i] to the new element
            i++;
            nums[i]=nums[j];
        }
    }
    
    //We return the number of elements that are unique as i increments every time a new(unique) element arrives
    //This will in turn print only the 
    return i+1;    
}

int main()
{
    //MAIN FUNCTION WOULD PASS ARRAY BY REF AND THEN PRINT UNIQUE ELEMENTS
    //LEETCODE HAD ONLY ABOVE FUNCTION TO COMPLETE
}
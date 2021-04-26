/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add
up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

//CODE:

#include <iostream>
#include <vector>
#include <map> //We use a map to represent a hashmap where one value maps to one key
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    //res will store the result - index of the two numbers that add up to the target
    vector<int> res;
    map<int, int> hmap;
    
    //Insert all the vector values into the map so we can keep track of the value and index simultaneously
    for(int i=0; i<nums.size(); i++)
    {
        //Inserts Value and Index
        hmap.insert(pair<int, int>(nums[i], i));
    }
    
    //Here we run through each element in the vector
    for(int i=0; i<nums.size(); i++)
    {
        //We calculate the compliment of that particular number wrt to the target (what we need to get to the sum)
        //rem  = target - current number
        int rem = target - nums[i];
        //cout << "Rem: " << rem << endl;
        //cout << "Value: " << hmap.find(rem)->second << endl;

        //We use a boolean variable to check if the current value isnt itself also the remainder 
        //If the current value is also the remainder then we set the bool value to true
        //Else done remains false
        bool done = false;
        if(hmap.find(rem)->second==i) //->second and ->first refer to the value and key of the particular elements in a map
            done = true;
        
        //If the value we are looking for does exist(rem) (BECAUSE REM + NUM[I] = TARGET)
        //And The current value isnt the also the remainder

        //hmap.find(rem) fetches the value from the map which equals the rem (Thus rem + curr value = Target)
        //.find() returns an iterator to the element we are looking for 
        //If the element is not present it returns an iterator hmap.end()
        if(hmap.find(rem)!=hmap.end() and done==false)
        {
            //Insert the index of the current value and the element which equals rem
            res.push_back(i);
            res.push_back(hmap.find(rem)->second);
            //return the result vector
            return res;
        }
    }
    
    //Empty vector
    return res;
}

int main()
{
    //Vector array of numbers from which we find if we can reach the target sum with a particular pair of numbers
    vector<int> nums;
    
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(12);
    nums.push_back(4);
    nums.push_back(6);
    
    //Target sum
    int target = 13;
    
    //Result array calls function to check if two numbers can add up to the target
    vector<int> result = twoSum(nums, target);
    
    //If the result array is empty - no solution
    if(result.size()==0)
    {
        cout << "No Solution" << endl;
        return 0;
    }

    //Print Result vector which contains the index of the two numbers in the nums array that add up to the target
    cout << "[ ";
    for(auto it=result.begin(); it!=result.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "]";
    
    return 0;
}
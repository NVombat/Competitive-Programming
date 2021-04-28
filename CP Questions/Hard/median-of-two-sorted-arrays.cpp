/*LEETCODE
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
*/
//CODE:

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    //We merge the two vectors into one array in a sorted manner so we can find the median
    //The size of the merged array is the sum of the sizes of the vectors
    int total_size = nums1.size()+nums2.size();
    int arr[total_size];
    
    //i represents the index of the merged array
    //j represents the index of the first vector
    //k represents the index of the second vector
    int i=0, j=0, k=0;
    
    //Insert elements into resultant array until one of the vectors is empty
    while(j<nums1.size() && k<nums2.size())
    {
        //If num at vector 1 is smaller than num at vector 2
        if(nums1[j]<=nums2[k])
        {
            //Insert that number into resultant array and increment the indexes i and j 
            arr[i] = nums1[j];
            i++;
            j++;
        }
        //If num at vector 2 is smaller than num at vector 1
        else
        {
            //Insert that number into resultant array and increment the indexes j and k 
            arr[i] = nums2[k];
            i++;
            k++;
        }
    }
    
    //Insert any remaining elements
    //If the two vectors are of different sizes then only one will still have elements in it at this stage
    //The one with the largest value integer

    //Empty the first vector if it has elements
    while (j<nums1.size())
    {
        arr[i] = nums1[j];
        i++;
        j++;
    }

    //Empty the second vector if it has element
    while (k<nums2.size())
    {
        arr[i] = nums2[k];
        i++;
        k++;
    }

    //At this stage the merged array is sorted and we can go on to find the median
    
    // cout << "I: " << i << endl;
    // cout << "J: " << j << endl;
    // cout << "K: " << k << endl;
    // cout << "Total_Size: " << total_size << endl;
    
    //If the total size of the merged array is odd -> there will be only one middle element thus that will be the median
    if(total_size%2!=0)
    {
        //We find the middle index of the array
        //The median is the element present at the middle index
        int mid = (total_size-1)/2;
        double median = arr[mid];
        //Return median value
        return median;
    }
    //If the total size of the merged array is even -> there will be two middle elements
    //The median will be the average of the two elements
    else
    {
        //We find the two middle indexes 
        int mid = total_size/2;
        int mid2 = mid-1;
        
        //cout << "MID: " << mid << endl;
        //cout << "MID2: " << mid2 << endl;
        //cout << "MEDIAN1: " << arr[mid] << endl;
        //cout << "MEDIAN2: " << arr[mid2] << endl;
        
        //We find the average of the two elements at those indexes and then return the median
        double median = (arr[mid] + arr[mid2])/2.0;
        return median;
    }
}

int main()
{
    //Two vectors with values
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);

    //Find median of the two vectors and print the answer
    double median = findMedianSortedArrays(v1, v2);
    cout << "Median of the two sorted arrays is:  " << median << endl;

    return 0;
}
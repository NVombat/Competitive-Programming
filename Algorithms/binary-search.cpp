#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Function prototypes
bool binarySearch(int arr[], int l, int r, int x);
void bubbleSort(int arr[], int n);
void print(int arr[], int n);

int main()
{
    //Size of array
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;

    //Scan elements into array
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    //Print array
    print(arr, n);
    //Sort the array as elements need to be in a sorted order for binary search
    bubbleSort(arr, n);
    //Print sorted array
    print(arr, n);

    //Query user for element to be searched
    int x;
    cout << "Enter element you want to search for: " << endl;
    cin >> x;

    //Call binary search and if true then found
    if(binarySearch(arr, 0, n-1, x))
        cout << "Found in array" << endl;
    //Else not found in array
    else
        cout << "Not found in array" << endl;

    return 0;
}

//Function to perform binary search
bool binarySearch(int arr[], int l, int r, int x)
{
    //If the rightmost index is greater than the leftmost
    if(r>=l)
    {
        //Find midpoint of array
        int mid = l + (r-l)/2;
        //If element to be found is the middle element return true
        if(x==arr[mid])
            return true;
        //If element is larger than mid element then recursively search the upper half
        else if(x > arr[mid])
            return binarySearch(arr, mid+1, r, x);
        //If element is smaller than mid element then recursively search the lower half
        else
            return binarySearch(arr, l, mid-1, x);
    }
    //If element is not found -> return false
    return false;
}

//Performs bubble sort in ascending order on the array
void bubbleSort(int arr[], int n)
{
    //Boolean variable set to false -> The sort will continue until done is not true
    bool done = false;
    while(!done)
    {
        //We set done to true for each iteration
        done = true;
        //temp variable to help swap integers
        int temp;
        for(int i=0; i<n-1; i++)
        {
            //Sort in ascending order
            if(arr[i]>arr[i+1])
            {
                //Swaps the values using temp variable
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                //After a swap we set done back to false
                //It will again be set to true when it re-enters the while loop
                //But when there are no more swaps to be made it will remain true and exit loop
                done = false;
            }
        }
    }
}

//Prints the array
void print(int arr[], int n)
{
    //Prints the entire array
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "-->";
    }
    cout << endl;
}

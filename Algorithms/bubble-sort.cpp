#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Function prototypes
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

    //Print array before sorting
    cout << "UNSORTED ARRAY: " << endl;
    print(arr, n);
    //Sort
    bubbleSort(arr, n);
    //Print array after sorting
    cout << "SORTED ARRAY: " << endl;
    print(arr, n);

    return 0;
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

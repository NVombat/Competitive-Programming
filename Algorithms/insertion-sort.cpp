#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Function prototypes
void insertionSort(int arr[], int n);
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
    insertionSort(arr, n);
    //Print array after sorting
    cout << "SORTED ARRAY: " << endl;
    print(arr, n);

    return 0;
}

//Performs insertion sort in ascending order on the array
//It inserts elements into the correct position
void insertionSort(int arr[], int n)
{
    int i, j, key;
    for(i=1; i<n; i++)
    {
        //j is always the index before i
        j=i-1;
        //key is the current element we are at
        key = arr[i];
        //While j is a valid index and element at [j] is larger than current element (since ascending order)
        while(j>=0 and arr[j]>key)
        {
            //Shift element at [j] to go after the current element
            arr[j+1] = arr[j];
            //Decrement j
            j--;

        }
        //When j finally becomes invalid due to the decrements or reaching the correct position
        //We finally put the current element in the empty position
        arr[j+1] = key;
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

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Function prototypes
void mergeSort(int arr[], int l, int r);
void mergeArray(int arr[], int l, int m, int r);
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
    mergeSort(arr, 0, n-1);
    //Print array after sorting
    cout << "SORTED ARRAY: " << endl;
    print(arr, n);

    return 0;
}

void mergeSort(int arr[], int l, int r)
{
    //If the leftmost index is greater than or equal to the rightmost index exit function
    if(l>=r)
        return;
    //Find mid point of array
    //Recursively call mergeSort on each half
    //Then merge the two half arrays
    else
    {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        mergeArray(arr, l, m, r);
    }
}

//Merge Function
void mergeArray(int arr[], int l, int m, int r)
{
    //Size of the temporary arrays which will be merged (left half array and right half array)
    int a = m-l+1;
    int b = r-m;

    //Temp arrays
    int tmp1[a];
    int tmp2[b];

    //Copy data in temp arrays
    for (int i=0; i<a; i++)
        tmp1[i]=arr[l+i];
    for (int j=0; j<b; j++)
        tmp2[j]=arr[m+1+j];

    //i = Initial index of first sub-array
    //j = Initial index of second subarray
    //k = Initial index of merged sub-array
    int i=0, j=0, k=l;

    //Merge the elements in ascending order
    while (i<a and j<b)
    {
        if (tmp1[i] <= tmp2[j])
        {
            arr[k]=tmp1[i];
            i++;
        }
        else
        {
            arr[k]=tmp2[j];
            j++;
        }
        k++;
    }

    //Copy the remaining elements
    while(i<a)
    {
        arr[k]=tmp1[i];
        i++;
        k++;
    }

    //Copy the remaining elements
    while(j<b)
    {
        arr[k]=tmp2[j];
        j++;
        k++;
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

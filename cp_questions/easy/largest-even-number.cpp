/*In this problem there is a number P (always a whole number) with N digits.
Now find out the largest possible even number formed with all the digits
TEST CASE 1

INPUT
5
1324
3415436
1023422
03517
3555
OUTPUT
4312
6543314
4322210
75310
5553
TEST CASE 2

INPUT
3
315436
1422
73555
OUTPUT
653314
4212
75553
*/

//CODE:
#include <iostream>
#include <list>
#include <iterator>
#include <string>
using namespace std;

int main() 
{
  //Number of testcases
  int n;
  cin >> n;
  //Runs for each test case
  for(int i=0; i<n; i++)
  {
    //Scans number as string (Because number can start with 0 which cant be ignored)
    //String is easier to break into digits 
    string num;
    cin >> num;
    
    //Create a list of integers and a reverse iterator to traverse it
    list<int> l;
    list<int>::reverse_iterator it;
    
    //Small_even will store the smallest even digit in the number
    //It is set to the smallest number out of range (basically > 9) as 10 is 2 digits
    int small_even = 10;
    
    //Runs through the number string
    for(int i=0; i<num.length(); i++)
    {
      //Changes each digit (Char of string) to a char
      char x = num[i];
      //In ASCII code, the digits start from 48 thus changes char to int
      int val = (int)x - 48;
      //If the digit is even and smaller than the current value of small_even
      if(val%2==0 and val<small_even)
      {
        //Set the smaller even digit to the small_even
        small_even = val;
      }
      //Push digit into list
      l.push_back(val);
    }
    
    //SORT LIST
    l.sort();
    
    //flag to ignore the small_even digit only once (If there is more than 1 of the same small_even digits)
    int flag = 2;
    //Traverse List
    for(it=l.rbegin(); it!=l.rend(); ++it)
    {
      //If element is small_even
      if((*it==small_even))
      {
        //Decrement the flag and ignore the small_even (continue traversing)
        flag--;
        if(flag==1)
        {
          continue;
        }
        //If small_even digit occurs more than once then dont ignore the second time and print it
        cout << *it;
      }
      //If it is not the small_even digit then print
      else
      {
        cout << *it;
      }
    }
    //At this stage if small_even is not 10 then print small_even at the end of the number
    if(small_even!=10)
    {
      cout << small_even << endl;
    }
    //If small_even is 10 - then there is no even digit in the number thus move to next test case
    else
    {
      cout << endl;
    }
  }
  return 0;
}


//ALTERNATE SOLUTION 
//CODE

#include <iostream>
#include <cstring>
using namespace std;

//function to swap two integers by reference using a temporary variable
void swap(int *x,int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

//bubble sorts a character array in descending order
void sort(char arr[], int n)
{
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
  {
      if(arr[i]<arr[j])
        swap(arr[i],arr[j]);
  }
}

//takes a character array and rearranges it so that the last element of the array is odd
void evenise(char arr[],int n)
{
  //i=n-2 because index starts from 0 and the function is only called when the last element is ODD, so we start 
  //from the (n-2)th element in the array 
  for(int i=n-2;i>=0;i--)
    //if element at index n-1 is odd, swap with element at index i
    if(arr[n-1]%2 !=0)
    {
      swap(arr[n-1],arr[i]);   
    }
}

int main() 
{
  int i,j,test;
  cin>>test;
 
  char num[10];
  for(i=0;i<test;i++)
  {
    
    cin>>num;

    //stores the length of the character array
    int l = int(strlen(num));
    
    sort(num,l);

    int count=0;

   //loop to check if each element is even
   for(int k=0;k<l;k++)
    {   
     if(num[k]%2 != 0)
       count++;
    }

    //if the last element is odd, evenise it
    if(count!=l)
      evenise(num,l);

    //print final array
    for(j=0;j<l;j++)
    {   
      cout<<num[j];
    }
    
    cout<<endl;
  }
	return 0;
}
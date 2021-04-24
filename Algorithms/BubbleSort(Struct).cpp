#include <iostream>
using namespace std;

//Structure for employee with name and id
struct employee
{
  string name;
  int id;
};

//Bubble Sort function declaration with structure
void bubbleSort(employee e[], int n);

int main()
{
  //Scan number of employees
  int n;
  cin >> n;
  
  //Array of employees (array of Structures)
  employee e[n];
  
  //Scan employee names and ids
  for(int i=0; i<n; i++)
  {
    cin >> e[i].name >> e[i].id;
  }
  
  //Sort structure
  bubbleSort(e, n);
  
  //Print final result of sorted structure
  cout << "After sorting" << endl << "Name ID" << endl;
  for(int i=0; i<n; i++)
  {
    cout << e[i].name << " " << e[i].id << endl;
  }
  
  return 0;
}

//BubbleSort structure
void bubbleSort(employee e[], int n)
{
  bool done = false;
  while(!done)
  {
    done = true;
    //Temp employee struct
    employee temp;
    for(int i=0; i<n-1; i++)
    {
      //Swap elements (name and id)if theyre not alphabetically arranged
      if(e[i].name.compare(e[i+1].name)>0)
      {
        temp = e[i]; 
        e[i] = e[i+1];
        e[i+1] = temp;  
        done = false;
      }
    }
  }
}
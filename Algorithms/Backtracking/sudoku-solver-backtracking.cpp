#include <iostream>
using namespace std;

//SUDOKU GRID -> Unsolved
int grid[9][9] = {{5,3,0,0,7,0,0,0,0},
                  {6,0,0,1,9,5,0,0,0},
                  {0,9,8,0,0,0,0,6,0},
                  {8,0,0,0,6,0,0,0,3},
                  {4,0,0,8,0,3,0,0,1},
                  {7,0,0,0,2,0,0,0,6},
                  {0,6,0,0,0,0,2,8,0},
                  {0,0,0,4,1,9,0,0,5},
                  {0,0,0,0,8,0,0,7,9}};

//Function declarations for the 3 functions needed for the SUDOKU SOLVER
bool possible(int x, int y, int n);
bool solve(int x, int y);
void printGrid();

int main()
{
    //Prints unsolved grid
    cout << "UNSOLVED GRID" << endl;
    printGrid();

    //If solved then print solved grid
    //Starts solving from the top left corner
    if(solve(0,0))
    {
        cout << "SOLVED GRID" << endl;
        printGrid();
    }
    //No solutions possible
    else
        cout << "No Solution" << endl;

    return 0;
}

//Prints a 2x2 grid of numbers
void printGrid()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

//Checks if a particular number fits in the grid
//Returns false if the number already exists in the same row, column or 3x3 square
bool possible(int x, int y, int n)
{
    //Checks if the number already exists in a particular row
    for(int i=0; i<9; i++)
    {
        if(grid[x][i]==n)
            return false;
    }

    //Checks if the number already exists in a particular column
    for(int i=0; i<9; i++)
    {
        if(grid[i][y]==n)
            return false;
    }

    //a,b are the coordinates of the top left corner of the 3x3 square
    //It calculates the value of a and b based on the value of x and y
    //For x=0,1,2 a=0 for x=3,4,5 a=3 for x=6,7,8 a=6 and same for b so as to get the correct starting point of each 3x3 square
    int a = (x/3)*3;
    int b = (y/3)*3;

    //Checks if the number exists in the 3x3 squares in the SUDOKU grid
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            //If number exists then return false
            if(grid[a+i][b+j]==n)
                return false;
        }
    }
    //If the number doesn't exist in any of the above mentioned locations then return true -> NUMBER CAN BE INSERTED INTO GRID
    return true;
}

//SOLVES THE SUDOKU GRID
bool solve(int x, int y)
{
    //After Final Row and Final Column are done -> It returns true to exit the solve function
    //Bottom right corner element
    if(x==8 && y==9)
    {
        return true;
    }

    //If the column goes to 9 it means it needs to go to the 0th column in the next row
    if(y==9)
    {
        //Row increments and column set back to 0
        x++;
        y=0;
    }

    //If the element in the grid is not a 0
    if(grid[x][y]>0 && grid[x][y]<=9)
    {
        //Recursively solve the grid for the element in the next column
        return solve(x, y+1);
    }

    //IF THE ELEMENT IN THE GRID IS A 0
    //For values of n from 1 to 9
    for(int n=1; n<10; n++)
    {
        //Checks if n can be inserted into the grid
        if(possible(x, y, n))
        {
            //Insert n into the grid at that position
            grid[x][y]=n;
            //Checks the next possibilities hence solving recursively
            if(solve(x, y+1))
            {
                return true;
            }
        }
        //If n cant be inserted it sets the current value to 0 and back tracks to the last point where a decision can be changed
        grid[x][y]=0;
    }
    return false;
}
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//This is the vector that keeps track of the cost of each path from source to destination that we find
//Thus if there are 5 possible paths from S to D this vector will store 5 costs (One for each path)
vector<int> path_cost;

//Number of rows and columns R,C and Counter 'cnt' to count the number of possible paths
int R=3, C=3, cnt=0;

//Function to traverse the grid to calculate all the possible paths and their costs by going from source to destination in as many ways as possible
void traverse_path(vector<vector<int>> isValid, int cost[][3], int curr_row, int curr_col, vector<int> path = {})
{
    //If the node we are currently at is out of the grid(Row/Column Values are illegal) or is not traversable(cost=-1) or has already been traversed in the current traversal
    if (curr_row<0 or curr_row>=R or curr_col<0 or curr_col>=C or isValid[curr_row][curr_col]==1 || cost[curr_row][curr_col]==-1)
    //Return with no action
    return;

    //If the destination node is reached (0,C-1) -> top right corner of grid
    if(curr_row==0 and curr_col==C-1)
    {
        //Insert cost of destination
        path.push_back(cost[curr_row][curr_col]);

        //For each path traversed from Source to Destination the total cost is initialized to 0
        //Thus every time we reach the destination in a particular way we save that path and calculate its cost before moving to find the next possible path
        int total_cost=0;

        //The cost of that particular path is printed for each location in the traversal from source to destination for that path
        cout << "PATH " << cnt << " -> ";
        for(int i=0; i<path.size(); i++)
        {
            cout << path[i];
            if(i!=path.size()-1)
                cout << " + ";
            //Compute total cost for that path
            total_cost+=path[i];
        }
        cout << " = " << total_cost << endl;

        //Push the total cost for this particular path to the main path_cost vector which stores the costs for each path
        path_cost.push_back(total_cost);

        //Increment counter to move to next path
        cnt++;
        return;
    }

    //Set the current node as traversed in a particular path
    isValid[curr_row][curr_col]=1;
    /*cout << "ISVALID: " << endl;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout << isValid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    //Insert the cost of the node that was traversed to reach the destination in the path vector which will then be summed up to get cost of that path
    path.push_back(cost[curr_row][curr_col]);

    //Recursive call to visit all the neighbors of the current node
    traverse_path(isValid, cost, curr_row, curr_col+1, path);
    traverse_path(isValid, cost, curr_row+1, curr_col, path);
    traverse_path(isValid, cost, curr_row-1, curr_col, path);
    traverse_path(isValid, cost, curr_row, curr_col-1, path);

    //Pop the value of the last node cost if we don't reach the end
    path.pop_back();
    //Reset the isValid value for the current node for other paths to be formed
    isValid[curr_row][curr_col]=0;
}

int main()
{
    //Integer matrix representing the grid we have to traverse-> 0=Traversable 1=Not Traversable
    int mat[3][3] = {{0,0,0},
                     {0,0,0},
                     {0,0,0}};

    //Cost matrix represents the cost of each location -> If the location cant be traversed then cost is set to -1, other cells set to cost of traversing that location
    int cost[3][3] = {{1,2,1},
                      {6,3,7},
                      {1,4,1}};

    //Prints The Grid
    cout << "Grid is: " << endl;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    //Prints the Cost Matrix
    cout << endl << "Cost is: " << endl;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //isValid 2D Vector Initialized to 0 with size same as grid using 2D vector constructor - To verify if a path is valid
    //It will also have RxC dimensions and all values will be set to 0 -> All paths are valid
    vector<vector<int>> isValid(R, vector<int> (C, 0));

    //We start traversing from R-1,0 which is the bottom left corner of the grid
    traverse_path(isValid, cost, R-1, 0);

    //If the main path_cost vector is empty then no path is feasible and thus no solution exists
    if(path_cost.size()==0)
        cout << "No Solution" << endl;
    else
    {
        //We calculate the minimum value in the vector which is the value of the least_cost_path from source to destination
        int least_cost_path = *min_element(path_cost.begin(), path_cost.end());
        //Print Output
        cout << "Minimum Cost From Source to Destination is " << least_cost_path << endl;
    }

    return 0;
}

#include<iostream>
#include<iterator>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    //Number of rows and columns
    int R=5, C=7;
    //Character matrix representing the grid
    char mat[5][7] = {{'S', '.', '.', '#', '.', '.', '.',},
                      {'.', '#', '.', '.', '.', '#', '.',},
                      {'.', '#', '.', '.', '.', '.', '.',},
                      {'.', '.', '#', '#', '.', '#', '.',},
                      {'#', '.', '#', '.', '.', '#', 'E',}};


    //Prints the matrix grid
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //Direction vectors -> used later to check for the neighbors of the particular node ((i,j+1), (i+1, j), (i, j-1), (i-1, j))
    int dr[4] = {-1, +1, 0, 0};
    int dc[4] = {0, 0, +1, -1};

    //'S' Symbol row and column value -> Where we start the bfs to find the shortest path
    int sr=0, sc=0;

    //Queues for row and column values of each node in the grid
    //We use two queues instead of one so that we can easily work with 2 dimensions (R,C)
    queue<int> rq;
    queue<int> cq;

    //Counts number of moves to reach the 'E' symbol -> How many moves it takes to reach the endpoint
    //Initially 0 moves
    int move_cnt=0;

    //Nodes left in layer = 1 as we are starting with the 'S' Symbol
    int nodes_left_in_layer = 1;
    //Nodes in next layer represent the neighboring nodes for the "nodes left in layer"
    int nodes_in_next_layer = 0;

    //Variable to check if the 'E' symbol has been reached during BFS
    bool reached_end = false;
    //Boolean visited array to check which nodes have been visited and which nodes haven't
    //Initially all nodes set to false as none have been visited
    bool visited[5][7] = {false};

    //We start the BFS by pushing the row and column value of the start node into their respective queues
    //Thus same as pushing 1 node in 1 queue
    //VALUES WILL BE POPPED AND PUSHED FROM BOTH QUEUES AT THE SAME TIME
    rq.push(sr);
    cq.push(sc);
    //We set the visited value for the current node to be true
    visited[sr][sc]=true;

    while(!rq.empty()) //cq.empty() will also do as both queues are enqueued and dequeued at the same time thus sizes remain constant
    {
        //We store the row and column value of the current node
        int curr_row = rq.front();
        int curr_col = cq.front();
        //Printing all accepted squares on the grid
        //cout << mat[curr_row][curr_col] << " at (" << curr_row << ", " << curr_col << ") ---> ";

        //We then pop the row and column values from their respective queues (same as removing the current node from the queue)
        rq.pop();
        cq.pop();
        //If the current node in the grid is 'E'
        if(mat[curr_row][curr_col]=='E')
        {
            //We have reached the end so we break out of the array
            reached_end=true;
            break;
        }

        //Otherwise we explore the neighbors
        //We can do this using a function if we use global variables, queues and grid
        for(int i=0; i<4; i++)
        {
            //Find the value of the neighboring node's row and column
            int rr = curr_row + dr[i];
            int cc = curr_col + dc[i];
            //cout << endl << "(" << rr << ", " << cc << ")" << endl;

            //If the value is out of bounds (off the grid)
            if((rr < 0 or cc < 0) or (rr >= R or cc >= C))
            {
                //Ignore the value and move to check next neighbor
                //cout << "NOT ACCEPTED" <<  endl;
                continue;
            }

            //If the node has already been visited
            if(visited[rr][cc])
            {
                //Ignore the value and move to check next neighbor
                //cout << "NOT ACCEPTED" <<  endl;
                continue;
            }

            //If the node is a '#' it cant be traversed
            if(mat[rr][cc]=='#')
            {
                //Ignore the value and move to check next neighbor
                //cout << "NOT ACCEPTED" <<  endl;
                continue;
            }

            //If the row and column value is legal
            //cout << "ACCEPTED" << endl;
            //We push the value of row and column for that node into its respective queues
            rq.push(rr);
            cq.push(cc);
            visited[rr][cc]=true;
            //Since there is a legal neighbor which we can explore -> We increment the nodes in next layer
            nodes_in_next_layer++;
            //cout << "NODES IN NEXT LAYER " << nodes_in_next_layer << endl;
        }

        //After exploring all neighbors of a node we decrement the nodes left in layer which represents the current set of nodes we are exploring
        nodes_left_in_layer--;
        //If we have explored all the nodes in the current layer
        if(nodes_left_in_layer==0)
        {
            //We update the nodes in the current layer to be the nodes in the next layer -> we explore their neighbors
            nodes_left_in_layer = nodes_in_next_layer;
            //We set the nodes in next layer to 0 as it will then again be updated for the current nodes
            nodes_in_next_layer = 0;
            //We then increment the number of moves to the end by 1
            move_cnt++;
        }
    }

    //After going through the entire graph using BFS if we do reach the end
    //We print the number of moves we reach the end in
    if(reached_end)
        cout << "Reached the endpoint in " << move_cnt << " moves" << endl;
    //If we cant reach the end
    else
        cout << "Cant reach endpoint";

    return 0;
}

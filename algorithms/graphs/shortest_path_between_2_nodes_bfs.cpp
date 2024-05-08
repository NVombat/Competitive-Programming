#include<iostream>
#include<bits/stdc++.h>
#include<iterator>
#include<vector>
#include<queue>
using namespace std;

//Function Prototypes
void addUndirectedEdge(vector<int> graph[], int u, int v);
void addDirectedEdge(vector<int> graph[], int u, int v);
void bfs(vector<int> graph[], int curr_node, int end_node, int n);
vector<int> reconstruct_path(int s, int e, int prev[]);

int main()
{
    //Takes User input for vertices and edges of the graph
    /*//Number of vertexes
    int n;
    cout << "Enter Number Of Vertexes: " << endl;
    cin >> n;

    //Adjacency List Representation
    vector<int> graph[n];

    int option, u, v, start, end_node;
    do
    {
        //Menu Driven Program
        cout << endl << "Enter Choice For Operation: 0 to Exit: " << endl;
        cout << "1. Add Edge For Undirected Graph" << endl;
        cout << "2. Add Edge For Directed Graph" << endl;
        cout << "3. BFS Traversal Result" << endl;

        //Users Choice
        cin >> option;
        switch(option)
        {
        case 0:
            cout << "Quitting" << endl;
            break;

        case 1:
            cout << "Enter Two Vertexes U and V Between Which You Want An Edge: " << endl;
            cin >> u >> v;
            addUndirectedEdge(graph, u, v);
            break;

        case 2:
            cout << "Enter Two Vertexes U and V Between Which You Want An Edge: Edge Will Be Directed From U to V (U->V): " << endl;
            cin >> u >> v;
            addDirectedEdge(graph, u, v);
            break;

        case 3:
            cout << "Enter Node You Want To Start BFS From and end BFS on: " << endl;
            cin >> start >> end_node;
            bfs(graph, start, end_node, n);
            break;

        default:
            cout << "Enter Valid Choice!" << endl;
            break;
        }
    }while(option!=0);*/

    //Number of vertexes
    int n = 13;
    //Adjacency List Representation
    vector<int> graph[n];

    //Edges of the graph
    addUndirectedEdge(graph, 0, 9);
    addUndirectedEdge(graph, 0, 7);
    addUndirectedEdge(graph, 0, 11);
    addUndirectedEdge(graph, 7, 11);
    addUndirectedEdge(graph, 9, 8);
    addUndirectedEdge(graph, 9, 10);
    addUndirectedEdge(graph, 10, 1);
    addUndirectedEdge(graph, 1, 8);
    addUndirectedEdge(graph, 8, 12);
    addUndirectedEdge(graph, 12, 2);
    addUndirectedEdge(graph, 2, 3);
    addUndirectedEdge(graph, 3, 7);
    addUndirectedEdge(graph, 3, 4);
    addUndirectedEdge(graph, 7, 6);
    addUndirectedEdge(graph, 6, 5);

    //Call BFS function and hence find shortest path between 2 nodes
    bfs(graph, 0, 2, n);
    return 0;
}

//Adds Edges for an undirected graph
void addUndirectedEdge(vector<int> graph[], int u, int v)
{
    //Here v is pushed into u's list and u is pushed into v's list
    //Thus making the edge undirected as u points to v and v points to u as well
    graph[u].push_back(v);
    graph[v].push_back(u);
}

//Adds Edges for a directed graph
void addDirectedEdge(vector<int> graph[], int u, int v)
{
    //Here v is pushed into u's list
    //Thus making the edge directed as u points towards v
    graph[u].push_back(v);
}

//Performs BFS on the graph starting from the given node
void bfs(vector<int> graph[], int curr_node, int end_node, int n)
{
    //Stores starting node for reconstructing shortest path for start to end node
    int s = curr_node;

    //Creates a queue
    queue<int> q;

    //Boolean Visited array to check which nodes have been visited
    bool visited[n];
    for(int i=0; i<n; i++)
    {
        //Initially all nodes set to false - None have been visited
        visited[i] = false;
    }

    //Current node has been visited
    visited[curr_node] = true;

    //Recon array keeps track of node that comes after node "i" so we can reconstruct path
    //Recon[i] == j ----> i comes after j
    //Initially array set to NULL
    int recon[n] = {0};

    //Push node into queue
    q.push(curr_node);

    //Create an iterator to go through the graph
    vector<int>::iterator itr;

    cout << "BFS Traversal: ";
    //Run while queue isnt empty
    while(!q.empty())
    {
        //Print current node (which is front node in queue)
        curr_node = q.front();
        cout << curr_node << "->";
        //Remove node from queue
        q.pop();

        //Traverse the list from beginning to end
        for(itr = graph[curr_node].begin(); itr!=graph[curr_node].end(); ++itr)
        {
            //If node has not been visited
            if(!visited[*itr])
            {
                //Set node to be visited
                visited[*itr] = true;
                //Push node into queue
                q.push(*itr);
                //This indicates that in the recon array -> node *itr came after node curr_node thus becoming its parent
                recon[*itr] = curr_node;
                //cout << *itr << " comes after " << curr_node << endl;
            }
        }
    }

    // recon[1] == 8 ----> 1 comes after 8
    // recon[y] == x ----> y comes after x

    cout << endl;
    /*for(int i=0; i<n; i++)
    {
        cout << recon[i] << "-->";
    }
    cout << endl;*/

    //Vector contains the shortest path from start_node to end_node
    vector<int> path;
    //Call the reconstruct path function using recon array
    path = reconstruct_path(s, end_node, recon);
    //Print the shortest path from node s to e
    cout << "Shortest Path between Node " << s << " and Node " << end_node << ": " << s;
    for(auto it = path.begin(); it!=path.end(); ++it)
    {
        cout << "-->" << *it;
    }
    //If path vector is empty -> No path between node s and e -> Disjoint graph
}

//Calculates the shortest path between 2 nodes s and e using recon array and returns path in vector
vector<int> reconstruct_path(int s, int e, int recon[])
{
    //Vector stores path
    vector<int> path;
    //Reconstruct path backwards from e
    //We initially set recon array to all 0 values -> that was to make sure the for loop stops at the correct location
    //We start at e and find the next node by checking recon array as recon[x]==y says that x comes after y
    for(int node=e; node!=0; node=recon[node])
    {
        path.push_back(node);
    }

    //We then reverse the path so that path starts at s and ends at e
    reverse(path.begin(), path.end());
    //We then return the path
    return path;
}

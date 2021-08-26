#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//Function Prototypes
void addDirectedEdge(vector<int> graph[], int u, int v);
void addUndirectedEdge(vector<int> graph[], int u, int v);
void dfs(vector<int> graph[], int curr_node, int n);
void check(vector<int> graph[], bool visited[], int curr_node);

int main()
{
    //Number Of Vertexes
    int n;
    cout << "Enter Number Of Vertexes: " << endl;
    cin >> n;

    //Adjacency List Representation
    vector<int> graph[n];

    int option, u, v, start;
    do
    {
        //Menu Driven Program
        cout << endl << "Enter Choice For Operation: 0 to Exit: " << endl;
        cout << "1. Add Edge For Undirected Graph" << endl;
        cout << "2. Add Edge For Directed Graph" << endl;
        cout << "3. DFS Traversal Result" << endl;

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
            cout << "Enter Node You Want To Start DFS From: " << endl;
            cin >> start;
            dfs(graph, start, n);
            break;

        default:
            cout << "Enter Valid Choice!" << endl;
            break;
        }
    }while(option!=0);

    return 0;
    /*//Number of Nodes
    int n = 4;

    //Array of Vectors
    vector<int> graph[n];

    //Adding Edges To Graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    dfs(graph, 2, n);*/
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

//Performs DFS from the CURR_NODE given in the function call
void dfs(vector<int> graph[], int curr_node, int n)
{
    //Visited Bool Array stores TRUE or FALSE for each node if its been visited or not
    //Size of Array is the same as the number of vertexes
    bool visited[n];
    for(int i=0; i<n; i++)
    {
        //Initialize to FALSE as none of the vertexes have been visited
        visited[i] = false;
    }

    //Call check function to perform DFS
    check(graph, visited, curr_node);
}

//Updates Visited Array and prints out the DFS traversal from the current node chosen
void check(vector<int> graph[], bool visited[], int curr_node)
{
    //Sets the curr_node to be visited by updating the array to True
    visited[curr_node] = true;
    //Prints curr_node as it has been visited
    cout << curr_node << "->";

    //Get an Iterator to iterate the list
    vector<int>::iterator itr;
    //Start from the list with the current node and go till the end of the list
    for(itr = graph[curr_node].begin(); itr!=graph[curr_node].end(); ++itr)
    {
        //If the node has not been visited
        if(!visited[*itr])
        {
            //Recursively call the check function on the next node
            check(graph, visited, *itr);
        }
    }
}
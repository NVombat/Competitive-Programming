#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//Function Prototypes
void addDirectedEdge(vector<int> graph[], int u, int v);
void addUndirectedEdge(vector<int> graph[], int u, int v);
void find_components(vector<int> graph[], int components[], int n, int cnt);
void dfs(vector<int> graph[], bool visited[], int components[], int curr_node, int cnt);

int main()
{
    //Allows User to enter number and type of vertices and connections
    /*//Number Of Vertexes
    int n;
    cout << "Enter Number Of Vertexes: " << endl;
    cin >> n;

    //Counter to count the different number of connected components
    cnt = 0;
    //Array stores the integer value of which component each vertex belongs to
    int components[n];

    //Adjacency List Representation
    vector<int> graph[n];

    int option, u, v;
    do
    {
        //Menu Driven Program
        cout << endl << "Enter Choice For Operation: 0 to Exit: " << endl;
        cout << "1. Add Edge For Undirected Graph" << endl;
        cout << "2. Add Edge For Directed Graph" << endl;
        cout << "3. DFS Traversal" << endl;

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
            cout << "Starting DFS Traversal " << endl;
            find_components(graph, components, n, cnt);
            break;

        default:
            cout << "Enter Valid Choice!" << endl;
            break;
        }
    }while(option!=0);

    return 0;*/

    //Creates graph with given number of vertices and edges
    //Number of Nodes
    int n = 18;
    //Counter to count the different number of connected components
    int cnt = 0;
    //Array stores the integer value of which component each vertex belongs to
    int components[n];

    //Array of Vectors
    vector<int> graph[n];

    //Adding Edges To Graph -> Numbered edges
    addUndirectedEdge(graph, 6, 7);
    addUndirectedEdge(graph, 6, 11);
    addUndirectedEdge(graph, 7, 11);
    addUndirectedEdge(graph, 12, 12);
    addUndirectedEdge(graph, 9, 2);
    addUndirectedEdge(graph, 3, 9);
    addUndirectedEdge(graph, 9, 15);
    addUndirectedEdge(graph, 15, 2);
    addUndirectedEdge(graph, 15, 10);
    addDirectedEdge(graph, 1, 5);
    addDirectedEdge(graph, 5, 16);
    addDirectedEdge(graph, 5, 17);
    addDirectedEdge(graph, 4, 0);
    addDirectedEdge(graph, 0, 8);
    addDirectedEdge(graph, 8, 4);
    addDirectedEdge(graph, 8, 14);
    addDirectedEdge(graph, 14, 13);
    addDirectedEdge(graph, 13, 0);
    addDirectedEdge(graph, 14, 0);

    //Call the function to find components of the graph and then perform dfs
    find_components(graph, components, n, cnt);

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

//Function to find the connected components in a graph
void find_components(vector<int> graph[], int components[], int n, int cnt)
{
    //Visited Bool Array stores TRUE or FALSE for each node if its been visited or not
    //Size of Array is the same as the number of vertexes
    bool visited[n];
    for(int i=0; i<n; i++)
    {
        //Initialize to FALSE as none of the vertexes have been visited
        visited[i] = false;
    }

    //For each non visited node
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            //increment cnt (firstly to count number of connected components and also to distinguish each set of connected components with its own unique count value)
            cnt++;
            //Call dfs function to perform DFS
            dfs(graph, visited, components, i, cnt);
        }
    }

    //Print components array and the value of count
    cout << endl << "COMPONENTS ARRAY" << endl;
    for(int i=0; i<n; i++)
    {
        cout << "Node " << i << "--->" << components[i] << endl;
    }
    cout << "Number of components: " << cnt;
}

//Updates Visited Array, Components Array and prints out the DFS traversal from the first node
void dfs(vector<int> graph[], bool visited[], int components[], int curr_node, int cnt)
{
    //Sets the curr_node to be visited by updating the array to True
    visited[curr_node] = true;
    //Set the value of the current node in the components array to be the value of count
    components[curr_node] = cnt;
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
            dfs(graph, visited, components, *itr, cnt);
        }
    }
}

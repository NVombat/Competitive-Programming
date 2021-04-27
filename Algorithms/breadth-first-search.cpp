#include<iostream>
#include<iterator>
#include<vector>
#include<queue>
using namespace std;

//Function Prototypes
void addUndirectedEdge(vector<int> graph[], int u, int v);
void addDirectedEdge(vector<int> graph[], int u, int v);
void bfs(vector<int> graph[], int curr_node, int n);

int main()
{
    //Number of vertexes
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
            cout << "Enter Node You Want To Start BFS From: " << endl;
            cin >> start;
            bfs(graph, start, n);
            break;

        default:
            cout << "Enter Valid Choice!" << endl;
            break;
        }
    }while(option!=0);

    /*addDirectedEdge(graph, 0, 1);
    addDirectedEdge(graph, 0, 2);
    addDirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 2, 0);
    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 3, 3);

    bfs(graph, 2, n);*/
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
void bfs(vector<int> graph[], int curr_node, int n)
{
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

    //Push node into queue
    q.push(curr_node);
    //Create an iterator to go through the graph
    vector<int>::iterator itr;

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
            }
        }
    }
}
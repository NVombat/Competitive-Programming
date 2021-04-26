#include <iostream>
using namespace std;

//Node structure represents element in queue -> Has data and pointer to next node
struct node
{
    int data;
    struct node *next;
};

//Nodes to represent front and rear of queue -> set to NULL as queue is empty
struct node *front = NULL;
struct node *rear = NULL;

//Checks if queue is empty
bool isEmpty()
{
    //If rear and front are NULL then queue is empty
    if(rear==NULL and front==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Adds node element with data 'val' to queue
void enqueue(int val)
{
    //Allocates memory for new node and sets data to val
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = val;

    //If queue is empty
    if(isEmpty())
    {
        //New node is the only element in the queue thus is becomes the front and the rear
        front = rear = new_node;
        return;
    }

    //If elements are there in the queue
    else
    {
        //The node is appended after the rear node and the rear node is set to the new node
        rear->next = new_node;
        rear = new_node;
        return;
    }
}

//Removes first element from queue
int dequeue()
{
    //If queue is empty then it goes into underflow state
    if(isEmpty())
    {
        return 1;
    }

    //Node temp points to the front node(first node in queue)
    node *temp = front;
    //Value to be removed is stored in dVal -> data value of front node
    int dVal = temp->data;
    //The next node after the current front node is made to be the front node
    front = front->next;
    //The current front node is unlinked from the LL
    temp->next = NULL;

    //If the new front node is NULL then that means the queue is empty hence it sets rear to null as well
    if(front==NULL)
    {
        rear=NULL;
    }

    //Frees the front node -> removes it from queue
    free(temp);
    //Returns dVal -> data of front node that was removed
    return dVal;
}

//Displays elements of the Queue
void display()
{
    //Starts from the front node and traverses the queue
    cout << "Queue elements are: " << endl;
    node *temp = front;
    while(temp!=rear->next)
    {
        //Prints out data of each element in queue
        cout << "->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    //Number of elements in the queue
    int n;
    cout << "Enter Number of elements in Queue: ";
    cin >> n;

    //Enter those elements
    cout << "Enter the elements you want in the queue: ";
    //Scan elements into array
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        //Enqueue each element into queue
        enqueue(arr[i]);
    }

    display();

    int x = dequeue();
    int y = dequeue();

    cout << "DEQUEUED:" << x << endl;
    cout << "DEQUEUED:" << y << endl;

    display();

    return 0;
}
#include <iostream>
#include <stdbool.h>
using namespace std;

//Node Structure is the element of the Linked List which behaves as a stack
//Each node has a data value and a pointer to the next node
struct node
{
    int data;
    struct node *next;
};

//TOP node represents the topmost element of the stack
struct node *top = NULL;

//Push function pushes data value d into stack from the top
void push(int d)
{
    //Allocates memory for new node and sets data to d
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = d;
    //New node points to the current top node
    //Then the new node becomes the top node hence the top node is now the second element in the stack
    new_node->next = top;
    top = new_node;
}

//Checks if the Stack is empty
bool isEmpty()
{
    //If top is null then LL doesn't exist
    if(top==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Returns the topmost value of the stack
int peek()
{
    //If stack isnt empty it returns the data of the topmost value of the stack
    if(!isEmpty())
    {
        return top->data;
    }
    else
    {
        return 1;
    }
}

//Removes the topmost element from the stack
int pop()
{
    //If empty then element cant be removed
    if(isEmpty())
    {
        cout << "Stack is in Underflow State" << endl;
        return 1;
    }
    else
    {
        //Else the Node after the top element becomes the top element and the current top element is removed
        node *temp = top;
        //The popped value is stored
        int popped = temp->data;
        top = top->next;
        temp->next = NULL;
        //Topmost element is freed
        free(temp);
        return popped;
    }
}

//Displays Stack Elements
void display()
{
    //If stack is empty then exit
    if(isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return;
    }
    else
    {
        //Traverse stack and print out data element by element
        node *temp = top;
        while(temp!=NULL)
        {
            cout << "->" << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
}

//Prints Stack in reverse order
void printReverse(node *top)
{
    //If top is NULL print error message
    if(top==NULL)
    {
        return;
    }

    //Recursively go till the end of the stack and then print the values backwards
    printReverse(top->next);
    cout << "->" << top->data;
}

int main()
{
    //Size of stack
    int size;
    cout << "Enter size of Stack: ";
    cin >> size;

    //Scans elements of stack into array and then pushes them into stack(LL)
    int arr[size];
    cout << "Enter Elements to enter in Stack: ";
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
        push(arr[i]);
    }

    //Displays the stack in two different manners
    display();
    printReverse(top);
    cout << endl;

    //Pops value from stack and displays the value
    int x = pop();
    cout << "Popped Value : " << x << endl;

    //Displays the stack
    display();

    //Peeks value from stack and displays value
    int y = peek();
    cout << "Peek Value : " << y << endl;

    return 0;
}
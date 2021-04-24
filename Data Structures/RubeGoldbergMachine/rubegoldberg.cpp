#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Common Node Structure - Has data members and a parametrized constructor to initialize values
//For Tree, Queue, Stack & Linked List
struct node
{
    //Data members and NEXT pointer for LL, stack & queue and LEFT, RIGHT pointer for tree
    string fname;
    string lname;
    int age;
    int year;
    node *next;
    node *left;
    node *right;

    //Parametrized constructor
    node(string fnam, string lnam, int a, int yr)
    {
        fname = fnam;
        lname = lnam;
        age = a;
        year = yr;
        next = NULL;
        left = NULL;
        right = NULL;
    }
};

//Tree Data Structure
struct Tree
{
    //Root node
    node *root;

    //Constructor sets root to NULL when tree is created
    Tree()
    {
        root = NULL;
    }

    //Checks if tree is empty
    bool isTreeEmpty()
    {
        //Empty if root is NULL
        if(root==NULL)
            return true;
        else
            return false;
    }

    //Inserts node to make a BST -> Based on age data of each node
    void insertNode(node *new_node)
    {
        //If tree is empty then new node becomes the root node
        if(isTreeEmpty())
        {
            root = new_node;
            return;
        }
        else
        {
            //Traverse tree till the end using temp node -> temp represents the current node
            node *temp = root;
            while(temp!=NULL)
            {
                //If new node data is the same as temp node data then return -> no duplicates
                if(new_node->age == temp->age)
                {
                   cout << "Value already exists, Insert another node" << endl;
                   return;
                }

                //If new node is smaller then temp and temp is a leaf node
                else if((new_node->age < temp->age) && (temp->left == NULL))
                {
                    //Append new node on the left of temp
                    temp->left = new_node;
                    break;
                }

                //If new node is smaller then temp and temp is not a leaf node
                else if(new_node->age < temp->age)
                {
                    //Traverse to the next left node
                    temp = temp->left;
                }

                //If new node is larger then temp and temp is a leaf node
                else if((new_node->age > temp->age) && (temp->right == NULL))
                {
                    //Append new node on the right of temp
                    temp->right = new_node;
                    break;
                }

                //If new node is larger then temp and temp is a not leaf node
                else
                {
                    //Traverse to the next right node
                    temp = temp->right;
                }
            }
        }
    }

    //PreOrder DFS -> NODE LEFT RIGHT
    void printPreOrder(node *temp)
    {
        //If n is NULL then return
        if(temp==NULL)
            return;
        //Print data out in order NLR using recursion
        cout << "(First Name: " << temp->fname << ", Last Name: " << temp->lname << ", Age: " << temp->age << ", Year: " << temp->year << ") ---> " << endl;
        printPreOrder(temp->left);
        printPreOrder(temp->right);
    }

    //InOrder DFS -> LEFT NODE RIGHT
    void printInOrder(node *temp)
    {
        if(temp==NULL)
            return;
        //Print data out in order LNR using recursion
        printInOrder(temp->left);
        cout << "(First Name: " << temp->fname << ", Last Name: " << temp->lname << ", Age: " << temp->age << ", Year: " << temp->year << ") ---> " << endl;
        printInOrder(temp->right);
    }

    //PostOrder DFS -> LEFT RIGHT NODE
    void printPostOrder(node *temp)
    {
        if(temp==NULL)
            return;
        //Print data out in order LRN using recursion
        printPostOrder(temp->left);
        printPostOrder(temp->right);
        cout << "(First Name: " << temp->fname << ", Last Name: " << temp->lname << ", Age: " << temp->age << ", Year: " << temp->year << ") ---> " << endl;
    }
};

//Queue Data Structure
struct Queue
{
    //Front and Rear nodes of queue
    node *front, *rear;

    //Constructor sets values of front and rear to NULL as queue is empty when we create it
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    //Checks if queue is empty
    bool isQueueEmpty()
    {
        //Empty if front and rear are NULL
        if(front==NULL && rear==NULL)
            return true;
        else
            return false;
    }

    //Enqueues Node into queue
    void enqueue(node *temp)
    {
        //If the queue is empty then front and rear both point to the new node
        if(isQueueEmpty())
        {
            front = rear = temp;
            return;
        }

        //Add new node at end of queue and change rear to point to new node
        rear->next = temp;
        rear = temp;
    }

    //Dequeues Node from queue
    node* dequeue()
    {
        //If queue is empty print out UNDERFLOW
        if(isQueueEmpty())
        {
            cout << "UNDERFLOW" << endl;
            return NULL;
        }

        //Element to be dequeued is stored in temp and front pointer is moved to the next node
        node *temp = front;
        front = front->next;

        //If front is NULL after above operation it implies queue is empty and so rear is also changed to NULL
        if(front==NULL)
        {
            rear=NULL;
        }

        //Return Dequeued Element
        return temp;
    }

    //Displays Queue Data
    void displayQueue()
    {
        //If queue empty
        if(isQueueEmpty())
        {
            cout << "Queue Empty!" << endl;
            return;
        }
        else
        {
            //Traverse Queue element by element and print the data members
            node *temp = front;
            while(temp!=NULL)
            {
                cout << "(First Name: " << temp->fname << ", Last Name: " << temp->lname << ", Age: " << temp->age << ", Year: " << temp->year << ") ---> " << endl;
                temp = temp->next;
            }
        }
    }

    //Displays Single Node In The Queue
    void displayQueueNode(node *temp)
    {
        cout << "(First Name: " << temp->fname << ", Last Name: " << temp->lname << ", Age: " << temp->age << ", Year: " << temp->year << ") ---> " << endl;
    }

    //Empties Queue & Frees The Memory For The Elements
    void emptyQueue()
    {
        //Dequeues Elements Till Queue Is Empty
        while(!isQueueEmpty())
        {
            node *temp = dequeue();
            //Frees Elements
            free(temp);
        }
        //Free Front & Rear Nodes
        free(front);
        free(rear);
        return;
    }
};

//Stack Data Structure
struct Stack
{
    //Top node -> represents the topmost node in the stack
    node *top;

    //Constructor sets top node to NULL when stack is created
    Stack()
    {
        top = NULL;
    }

    //Checks if stack is empty
    bool isStackEmpty()
    {
        //Empty is top is NULL
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //Pushes Node into stack
    void push(node* new_node)
    {
        //Pushes node to the top of the stack and then makes the new node the new TOP node
        new_node->next = top;
        top = new_node;
        return;
    }

    //Pops top node from stack
    node *pop()
    {
        //If stack is empty -> UNDERFLOW
        if(isStackEmpty())
        {
            cout << "Underflow" << endl;
            return top;
        }

        else
        {
            //Store top node in temp and then move the top node to the next node
            node *temp = top;
            top = top->next;
            //Unlink the old top node from the stack
            temp->next = NULL;
            //Return popped node
            return temp;
        }
    }

    //Display Stack data
    void displayStack()
    {
        //If stack is empty
        if(isStackEmpty())
        {
            cout << "Stack Empty!" << endl;
            return;
        }
        else
        {
            //Traverse stack element by element and display node data
            node *temp = top;
            while(temp!=NULL)
            {
                cout << "(First Name: " << temp->fname << ", Last Name: " << temp->lname << ", Age: " << temp->age << ", Year: " << temp->year << ") ---> " << endl;
                temp = temp->next;
            }
        }
    }

    //Empty the stack
    void emptyStack()
    {
        //Till stack is not empty
        while(!isStackEmpty())
        {
            //Pop each node and free memory for that node
            node *temp = pop();
            free(temp);
        }

        //Free top memory
        free(top);
        return;
    }
};

//Linked List Data Structure
struct LinkedList
{
    //Head node
    node *head;

    //Constructor sets head to NULL when LL is created
    LinkedList()
    {
        head = NULL;
    }

    //Checks if LL is Empty
    bool isLLEmpty()
    {
        //Empty if head is NULL
        if(head==NULL)
            return true;
        else
            return false;
    }

    //Inserts Node into LL
    void insertNode(node *new_node)
    {
        //If LL is empty
        if(isLLEmpty())
        {
            //Insert new node as the head node
            head = new_node;
            return;
        }

        else
        {
            //Traverse till the end of the LL
            node *temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            //Append new node at the end of the LL
            temp->next = new_node;
            return;
        }
    }

    //Gets the tail node of the LL -> The last node
    node *getTail(node *currptr)
    {
        //Traverse till the end
        while(currptr!=NULL && currptr->next!=NULL)
            currptr = currptr->next;

        //Return last node(tail)
        return currptr;
    }

    node *Partition(node *head, node *end, node **NewHead, node **NewEnd)
    {
        node *pivot = end;
        node *prev = NULL, *cur = head, *tail = pivot;

        while(cur!=pivot)
        {
            if(cur->age < pivot->age)
            {
                if((*NewHead) == NULL)
                    (*NewHead) = cur;

                prev = cur;
                cur = cur->next;
            }
            else
            {
                if(prev)
                {
                    prev->next = cur->next;
                }
                node *temp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = temp;
            }
        }
        if((*NewHead) == NULL)
            (*NewHead) = pivot;

        (*NewEnd) = tail;
        return pivot;
    }

    node *quickSortRecur(node *head, node *end)
    {
        if(!head || head==end)
            return head;

        node *newHead = NULL, *newEnd = NULL;

        node *pivot = Partition(head, end, &newHead, &newEnd);

        if(newHead != pivot)
        {
            node *temp = newHead;
            while(temp->next!=pivot)
                temp = temp->next;
            temp->next = NULL;

            newHead = quickSortRecur(newHead, temp);

            temp = getTail(newHead);
            temp->next = pivot;
        }

        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }

    //QuickSort Function Call
    void quickSort(node **head)
    {
        //Sorts LL from head to end using quick sort
        *head = quickSortRecur(*head, getTail(*head));
        return;
    }

    //Inserts Nodes from tree into LL using InOrder Traversal
    void insertInorder(node *temp)
    {
        if(temp==NULL)
            return;
        //Insert data in order LNR using recursion
        insertInorder(temp->left);
        //Calls LL Insert Node function to insert the node
        insertNode(temp);
        insertInorder(temp->right);
    }

    //Display LL data
    void displayLinkedList()
    {
        //If LL is empty
        if(isLLEmpty())
        {
            cout << "Linked List Empty!" << endl;
            return;
        }
        else
        {
            //Traverse LL element by element and output node data for each node
            node *temp = head;
            while(temp!=NULL)
            {
                cout << "(First Name: " << temp->fname << ", Last Name: " << temp->lname << ", Age: " << temp->age << ", Year: " << temp->year << ") ---> " << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    //Data Structures
    Queue q1, q2;
    Stack s1;
    LinkedList l1;
    Tree t1;

    int cnt; //Keeps Track of total number of entries

    //Opens Given File
    fstream newfile;
    newfile.open("rubegoldberg.txt", ios::in);

    //If file is open
    if(newfile.is_open())
    {
        //Read each line into a string
        string text;
        while(getline(newfile, text))
        {
            //cout << text << endl; //Print string
            //Splits each line using a delimiter
            stringstream linestream(text);
            string fname, lname, age;
            int year;

            //Stores the different parts of the string in different variables
            getline(linestream, fname, ',');
            getline(linestream, lname, ',');
            getline(linestream, age, ','); //Stores age as a string
            linestream >> year;

            //Converts age back to integer
            int new_age = stoi(age);

            //Prints out the variables to check
            //cout << fname << lname << " " << new_age << " " << year << endl;

            //Put the scanned data into a node
            node *new_node = new node(fname, lname, new_age, year);
            cnt++; //Increments Counter

            //Enqueue Node
            q1.enqueue(new_node);
        }
        //Close File
        newfile.close();
    }

    //q1.displayQueue();
    //cout << endl;

    cout << "QUEUE: " << endl;
    //Dequeue From q1 and Enqueue to q2 then Display
    while(!q1.isQueueEmpty())
    {
        node *temp = q1.dequeue();
        q1.displayQueueNode(temp);
        q2.enqueue(temp);
    }

    //cout << endl;
    //q2.displayQueue();

    //Dequeue from q2 and push into s1
    while(!q2.isQueueEmpty())
    {
        s1.push(q2.dequeue());
    }

    //cout << endl;
    //s1.displayStack();

    //Pop from s1 and enqueue back into q1
    while(!s1.isStackEmpty())
    {
        q1.enqueue(s1.pop());
    }

    //cout << endl;
    //q1.displayQueue();
    cout << endl;

    cout << "REVERSE QUEUE: " << endl;
    //Dequeue from q1 and enqueue to q2 then display
    while(!q1.isQueueEmpty())
    {
        node *temp = q1.dequeue();
        q1.displayQueueNode(temp);
        q2.enqueue(temp);
    }

    //cout << endl;
    //q2.displayQueue();
    //Free the memory for q1 and s1
    q1.emptyQueue();
    s1.emptyStack();
    cout << endl;

    //Dequeue first node and keep separate -> ROOT of tree
    node *temp = q2.dequeue();
    //NEXT pointer not needed anymore
    temp->next = NULL;
    //Insert into tree
    t1.insertNode(temp);

    //Dequeue q2 and insert nodes into tree
    while(!q2.isQueueEmpty())
    {
        node *temp1 = q2.dequeue();
        temp1->next = NULL;
        t1.insertNode(temp1);
    }

    //Print PreOrder, InOrder, PostOrder Traversals
    cout << "PREORDER TRAVERSAL: " << endl;
    t1.printPreOrder(temp);
    cout << endl;
    cout << "POSTORDER TRAVERSAL: " << endl;
    t1.printPostOrder(temp);
    cout << endl;
    cout << "INORDER TRAVERSAL: " << endl;
    t1.printInOrder(temp);
    cout << endl;

    //Free memory for q2
    q2.emptyQueue();

    //Insert using InOrder Traversal into LL from Tree
    l1.insertInorder(temp);
    //Display LL
    cout << "INORDER INSERTION OF LINKED LIST: " << endl;
    l1.displayLinkedList();
    cout << endl;

    //QS for UnOrdered TREE
    //l1.quickSort(); //Inserting InOrder Already Sorts the LL thus QS is not necessary at this stage
    //l1.displayLinkedList();

    //variables to store User Input
    int option, age, year;
    string fname, lname;

    do
    {
        //Menu to ask for user choice
        cout << "Enter Option: 0 to exit: " << endl;
        cout << "1. To insert a node" << endl;
        cin >> option;

        switch(option)
        {
        case 0:
            cout << "Exiting User Input" << endl;
            break;

        case 1:
            //Asks user for node data and then inserts into LL
            cout << "Enter First and Last name and age and year of birth: " << endl;
            cin >> fname >> lname >> age >> year;
            node *new_node = new node(fname, lname, age, year);
            cnt++;//Increments counter
            l1.insertNode(new_node);
            break;
        }
    }while(option!=0); //Run till user quits the program

    cout << endl << "FINAL SORTED LINKED LIST" << endl;
    //Finally Sorts LL and then displays the sorted LL
    l1.quickSort(&l1.head);
    l1.displayLinkedList();

    return 0;
}
#include <iostream>
using namespace std;

//Class Node - Has Key, Data and pointer to next node
class Node
{
public:
    int key;
    int data;
    Node* next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

//Class Singly Linked List
class SinglyLinkedList
{
public:
    Node* head;

    //Sets head node to null - constructor
    SinglyLinkedList()
    {
        head = NULL;
    }

    //Sets head node to be the node in the parameter of the constructor
    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    //Checks if node exists using key value
    Node* nodeExists(int k)
    {
        Node* temp = NULL;
        Node* ptr = head;

        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    //Appends Node at the end of the list
    void appendNode(Node *n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout << "Node with key value " << n->key << " already exists" << endl;
            cout << "Append another node with different key value" << endl;
        }
        else
        {
            if(head==NULL)
            {
                head = n;
                cout << "Node Appended" << endl;
            }
            else
            {
                Node* ptr = head;
                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node Appended" << endl;
            }
        }
    }

    //Prepends Node at the beginning of the list
    void prependNode(Node *n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout << "Node with key value " << n->key << " already exists" << endl;
            cout << "Prepend another node with different key value" << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node Prepended" << endl;
        }
    }

    //Inserts node in the middle of the list after a node with key value k
    void insertNode(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if(ptr==NULL)
        {
            cout << "No node exists with key value " << k << endl;
        }
        else
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout << "Node with key value " << n->key << " already exists" << endl;
                cout << "Insert another node with different key value" << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node Inserted" << endl;
            }
        }
    }

    //Deletes node with key value k
    void deleteNode(int k)
    {
        if(head==NULL)
        {
            cout << "Singly Linked List Already Empty" << endl;
        }
        else if(head!=NULL)
        {
            if(head->key==k)
            {
                head = head->next;
                cout << "Node Unlinked from Singly Linked List" << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while(currentptr!=NULL)
                {
                    if(currentptr->key==k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if(temp!=NULL)
                {
                    prevptr->next = temp->next;
                    cout << "Node Unlinked" << endl;
                }
                else
                {
                    cout << "Node with key value doesnt exist" << endl;
                }
            }
        }
    }

    //Updates data of node with key value k
    void updateNode(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if(ptr!=NULL)
        {
            ptr->data = d;
            cout << "Data updated successfully" << endl;
        }
        else
        {
            cout << "Node doesnt exist" << endl;
        }
    }

    //Prints final Linked List
    void printList()
    {
        if(head==NULL)
        {
            cout << "No nodes in singly linked list" << endl;
        }
        else
        {
            cout << "Singly Linked List Values: " << endl;
            Node *temp = head;
            while(temp!=NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") --> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    SinglyLinkedList s;
    int option, key1, data1, k1;

    do
    {
        cout << "Select Operation: 0 to exit" << endl;
        cout << "1. AppendNode()" << endl;
        cout << "2. PrependNode()" << endl;
        cout << "3. InsertNode()" << endl;
        cout << "4. DeleteNode()" << endl;
        cout << "5. UpdateNode()" << endl;
        cout << "6. PrintList()" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin >> option;
        Node *n1 = new Node();

        switch(option)
        {
            case 0:
                break;

            case 1:
                cout << "AppendNode() Operation: " << endl;
                cout << "Enter Key and Data of node to be appended: " << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;
                s.appendNode(n1);
                break;

            case 2:
                cout << "PrependNode() Operation: " << endl;
                cout << "Enter Key and Data of node to be prepended" << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;
                s.prependNode(n1);
                break;

            case 3:
                cout << "InsertNode() Operation: " << endl;
                cout << "Enter Key of existing node after which insertion will take place: " << endl;
                cin >> k1;
                cout << "Enter Key and Data of new node: " << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;
                s.insertNode(k1, n1);
                break;

            case 4:
                cout << "DeleteNode() Operation: " << endl;
                cout << "Enter Key of node to be Deleted: " << endl;
                cin >> k1;
                s.deleteNode(k1);
                break;

            case 5:
                cout << "UpdateNode() Operation: " << endl;
                cout << "Enter Key of node to be Updated and New Data: " << endl;
                cin >> key1;
                cin >> data1;
                s.updateNode(key1, data1);
                break;
            case 6:
                s.printList();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option Choice" << endl;
        }
    }
    while(option!=0);

    return 0;
}
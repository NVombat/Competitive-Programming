#include <iostream>
using namespace std;

//Node Class
class Node
{
public:
    //Data members of a Node
    int key;
    int data;
    Node *prev;
    Node *next;

    //Constructor sets values to 0 and NULL
    Node()
    {
        key = 0;
        data = 0;
        prev = NULL;
        next = NULL;
    }

    //Parametrized constructor sets key to 'k' and data to 'd'
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

//DLL class
class DoublyLinkedList
{
public:
    //Head Node in DLL
    Node *head;

    //Default constructor sets head to NULL
    DoublyLinkedList()
    {
        head = NULL;
    }

    //Parametrized constructor sets head to Node n
    DoublyLinkedList(Node *n)
    {
        head = n;
    }

    //Checks if Node with key value k already exists
    Node* nodeExists(int k)
    {
        Node *temp = NULL;
        //Traverses DLL till the end
        Node *ptr = head;
        while(ptr!=NULL)
        {
            //If node has key value 'k'
            if(ptr->key == k)
            {
                //Set temp to ptr
                temp = ptr;
            }
            ptr = ptr->next;
        }
        //Returns temp -> if NULL then element with key 'k' isnt in DLL else node with key already exists
        return temp;
    }

    //Appends node at the end of DLL
    void appendNode(Node *n)
    {
        //Checks if node already exists with this key value in DLL
        if(nodeExists(n->key)!=NULL)
        {
            cout << "Node already exits with key: " << n->key << ". Append another node with different key value" << endl;
            return;
        }
        else
        {
            //If head is NULL then DLL is empty
            if(head==NULL)
            {
                //New node becomes the head node
                head = n;
                cout << "Node appended as head node" << endl;
            }
            else
            {
                //Traverses till the end of the DLL
                Node *ptr = head;
                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                //Appends the node at the end
                ptr->next = n;
                n->prev = ptr;
                cout << "Node appended" << endl;
            }
        }
    }

    //Prepends Node at the beginning of the DLL
    void prependNode(Node *n)
    {
        //Checks if node with this key value already exists in DLL
        if(nodeExists(n->key)!=NULL)
        {
            cout << "Node already exits with key: " << n->key << ". Append another node with different key value" << endl;
            return;
        }
        else
        {
            //If head is NULL then DLL is empty hence the new node 'n' becomes the head node
            if(head==NULL)
            {
                head = n;
                cout << "Node prepended" << endl;
                return;
            }
            else
            {
                //The current head prev is made to point to the new node and the new node next is made to point to the current head
                head->prev = n;
                n->next = head;
                //New node 'n' is made the new head of the DLL hence prepending the node
                head = n;
                cout << "Node prepended" << endl;
                return;
            }
        }
    }

    //Inserts node n into DLL after node with key 'k'
    void insertNode(int k, Node *n)
    {
        //Checks if node exists
        Node *ptr = nodeExists(k);
        if(ptr==NULL)
        {
            cout << "No node exits with key value: " << k << endl;
            return;
        }
        else
        {
            //Checks if there is already a node with the key value of the node we are going to insert
            if(nodeExists(n->key)!=NULL)
            {
                cout << "Node already exits with key: " << n->key << ". Append another node with different key value" << endl;
                return;
            }
            else
            {
                //nextNode points to the node after ptr
                Node *nextNode = ptr->next;
                //Inserting Node at the end of DLL
                if(nextNode==NULL)
                {
                    ptr->next = n;
                    n->prev = ptr;
                    cout << "Node inserted at the end" << endl;
                    return;
                }
                //Inserting node in between
                else
                {
                    n->next = nextNode;
                    nextNode->prev = n;
                    n->prev = ptr;
                    ptr->next =  n;
                    cout << "Node inserted in between" << endl;
                    return;
                }
            }
        }
    }

    //Deleting node with key value k
    void deleteNode(int k)
    {
        //Checks if node with key value 'k' exists
        Node *ptr = nodeExists(k);
        if(ptr==NULL)
        {
            cout << "No node exits with key value: " << k << endl;
            return;
        }
        else
        {
            //If head node is the one to be deleted
            if(head->key==k)
            {
                head = head->next;
                //head->next->prev = NULL
                return;
            }
            else
            {
                Node *nextNode = ptr->next;
                Node *prevNode = ptr->prev;
                //Deleting at End
                if(nextNode==NULL)
                {
                    prevNode->next = NULL;
                    cout << "Node deleted at the end" << endl;
                }
                //Deleting in between
                else
                {
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    cout << "Node deleted in between" << endl;
                }
            }
        }
    }

    //Update Data of a node
    void updateNode(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if(ptr!=NULL)
        {
            ptr->data = d;
            cout << "Data updated" << endl;
        }
        else
        {
            cout << "Node with key value " << k << " doesnt exist" << endl;
        }
    }

    //Print DLL
    void printList()
    {
        if(head==NULL)
        {
            cout << "DLL is empty" << endl;
        }
        else
        {
            cout << "DLL Values Are: " << endl;
            Node *temp = head;
            while(temp!=NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") <---> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    DoublyLinkedList d;
    int option;
    int key1, data1, k;

    //Menu driven DLL operations
    do
    {
        cout << "Enter operation to be performed: Enter 0 to exit: " << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNode()" << endl;
        cout << "4. deleteNode()" << endl;
        cout << "5. updateNode()" << endl;
        cout << "6. printList()" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin >> option;
        Node *n1 = new Node();

        switch(option)
        {
        case 0:
            break;

        case 1:
            cout << "Append Node Operation:" << endl;
            cout << "Enter key and data value of node to be appended: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            d.appendNode(n1);
            break;

        case 2:
            cout << "Prepend Node Operation:" << endl;
            cout << "Enter key and data value of node to be prepended: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            d.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node Operation:" << endl;
            cout << "Enter key of node after which you want to insert this node: " << endl;
            cin >> k;
            cout << "Enter key and data value of new node to be inserted: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            d.insertNode(k, n1);
            break;

        case 4:
            cout << "Delete Node Operation:" << endl;
            cout << "Enter key of node to be deleted: " << endl;
            cin >> k;
            d.deleteNode(k);
            break;

        case 5:
            cout << "Update Node Operation:" << endl;
            cout << "Enter key and NEW data value of node to be updated: " << endl;
            cin >> key1;
            cin >> data1;
            d.updateNode(key1, data1);
            break;

        case 6:
            d.printList();
            break;

        case 7:
            system("cls");
            break;

        default:
            cout << "Enter valid option!" << endl;
        }
    }while(option!=0);

    return 0;
}
#include <iostream>
using namespace std;

//Node structure with data and pointer to next node
struct Node
{
  int data;
  struct Node *next;
};

//Create function creates a linked list using head node and data as parameters
void create(Node **head, int d)
{
  //Allocates memory for new node
  Node *new_node = (Node*)malloc(sizeof(Node));
  //Sets new node data to d and pointer value to next node as NULL
  new_node->data = d;
  new_node->next = NULL;

  //If head node is NULL then sets new node as the head node
  if(*head == NULL)
    *head = new_node;
  else
  {
    //Creates a node pointer ptr to point to the head of the node
    Node *ptr = *head;
    //Traverses node till the end
    while(ptr->next!=NULL)
    {
      ptr = ptr->next;
    }
    //Appends element to the end of the list
    ptr->next = new_node;
  }
}

//printList function prints LL
void printList(Node *head)
{
  //Creates a node pointer ptr which points to the head of the list
  Node *ptr = head;
  cout << "Linked List : ";
  //Traverses LL one by one
  while(ptr!=NULL)
  {
    //Prints data value of nodes one by one
    cout << "->" << ptr->data;
    ptr = ptr->next;
  }
}

//deleteNode function takes head node and d(data value of node to be deleted) as parameters
void deleteNode(Node *head, int d)
{
  //If head node is NULL exit function as the LL doesnt exist
  if(head == NULL)
    return;
  else
  {
    //Check is a flag to check if node to be deleted is found or not
    bool check = false;
    Node *prevptr = head;
    Node *currptr = prevptr->next;

    //Traverses LL
    while(currptr!=NULL)
    {
      //If node to be deleted is the head node
      if(head->data==d)
      {
        //Checks is true
        check = true;
        //Head data becomes the data of the node after the head node - Both the first two node have same data
        head->data = head->next->data;
        //cout << "Head data is : " << head->data << endl;
        //Creates two of the same node in the front
        Node *temp = head->next;
        //both nodes should point to node 3 as both nodes are the same thus first node will point to third node
        head->next = head->next->next;
        //Frees first node
        free(temp);
        //cout << head->data << " : is the new head data after deletion of head node" << endl;
        //prevptr is set to the new head and currptr is incremented to next node
        prevptr = head;
        currptr = prevptr->next;
        //Eg -> 1 2 3 4 5
        //Step 1 -> 2 2 3 4 5
        //Step 2 -> Make first '2' point to the '3' thus now both the first two elements point to '3'
        //Free the first node thus LL becomes 2 3 4 5
      }

      else
      {
        //If currptr is the node to be deleted and it isnt the last node in the LL
        if(currptr->data==d && currptr->next!=NULL)
        {
          check = true;
          //prevptr points to the node after currptr thus unlinking the node to be deleted
          prevptr->next = currptr->next;
          //temp stores currptr and then currptr is incremented to point to the next node
          Node *temp = currptr;
          currptr = currptr->next;
          //The node to be deleted is freed after making it point to NULL (unlinked from LL)
          temp->next = NULL;
          free(temp);
        }

        //If currptr is the node to be deleted and it is the last node in the LL
        else if(currptr->data==d && currptr->next==NULL)
        {
          check = true;
          //prevptr then points to NULL thus unlinking the currptr from LL and making prevptr the last element in the LL
          prevptr->next = NULL;
          //Currptr is set to NULL and then the memory is freed
          currptr = NULL;
          free(currptr);
        }

        else
        {
          //Increment currptr and prevptr to move to the next nodes
          prevptr=prevptr->next;
          currptr=currptr->next;
        }
      }
    }
    //If check stays false that means the node to be deleted is not in the linked list
    if(check==false)
    {
        //Output error message and return
        cout << "Invalid Node!" << endl;
        return;
    }
  }
}

int main()
{
  //Scan number of elements in LL
  int n;
  cout << "Enter number of elements in LL: " << endl;
  cin >> n;

  //Set head node to be NULL
  Node *head = NULL;

  //Scan elements into array
  cout << "Enter the elements of the LL: " << endl;
  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
    //Call create function to append each element into the LL
    create(&head, arr[i]);
  }

  printList(head);
  cout << endl;

  //Scans node data for node that has to be deleted
  int d;
  cout << "Enter element to be deleted: " << endl;
  cin >> d;

  //Calls deleteNode function to delete all nodes with data value d
  deleteNode(head, d);

  //Calls printList function to print final LL
  printList(head);

  return 0;
}
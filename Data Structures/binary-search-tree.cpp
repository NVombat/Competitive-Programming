#include <iostream>
#define SPACE 10
using namespace std;

//Struct for creating a tree node
/*struct tnode
{
    //Has data and pointers to two child nodes
    int data;
    struct tnode* left;
    struct tnode* right;
};
//Create the root node and set it to NULL
struct tnode* root = NULL;*/

//Node class
class node
{
public:
    //Data and pointers to left and right node
    int data;
    node *left;
    node *right;

    //Default constructor sets data to 0 and pointers to NULL
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    //Parametrized constructor sets node data to val
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//Binary Search Tree Class
class BST
{
public:
    //Root Node
    node *root;

    //Default constructor sets root node to NULL as tree is empty initially
    BST()
    {
        root = NULL;
    }

    //Checks if tree is empty
    bool isEmpty()
    {
        //Empty is root node is NULL
        if(root==NULL)
            return true;
        else
            return false;
    }

    //Inserts node in respective position based on value
    void insertNode(node *new_node)
    {
        //If tree is empty then new node becomes the root node
        if(isEmpty())
        {
            root = new_node;
            cout << "Node inserted as root node" << endl;
        }
        else
        {
            //Traverse tree till the end using temp node -> temp represents the current node
            node* temp = root;
            while(temp!=NULL)
            {
                //If new node data is the same as temp node data then return -> no duplicates
                if(new_node->data == temp->data)
                {
                   cout << "Value already exists, Insert another node" << endl;
                   return;
                }

                //If new node is smaller then temp and temp is a leaf node
                else if((new_node->data < temp->data) && (temp->left == NULL))
                {
                    //Append new node on the left of temp
                    temp->left = new_node;
                    cout << "Node inserted to the left" << endl;
                    break;
                }

                //If new node is smaller then temp and temp is not a leaf node
                else if(new_node->data < temp->data)
                {
                    //Traverse to the next left node
                    temp = temp->left;
                }

                //If new node is larger then temp and temp is a leaf node
                else if((new_node->data > temp->data) && (temp->right == NULL))
                {
                    //Append new node on the right of temp
                    temp->right = new_node;
                    cout << "Node inserted to the right" << endl;
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

    //Recursively inserts a node into the tree -> new_node
    node* recursiveInsert(node *root, node *new_node)
    {
        if(root==NULL)
            return new_node;

        if(new_node->data<root->data)
            root->left = recursiveInsert(root->left, new_node);
        else
            root->right = recursiveInsert(root->right, new_node);
    }

    //Recursively searches for a node in the tree with the data->val
    void recursiveSearch(node *root, int val)
    {
        //If root -> or any successive nodes after that are NULL it means that we have searched till the leaf for that particular node
        //And that node is not present in the tree -> Hence print "NOT FOUND"
        if(root==NULL)
        {
            cout << "Node not found in tree" << endl;
            return;
        }
        //If root -> or any successive nodes after that are the value we are looking for -> node is found in tree
        if(root->data==val)
        {
            cout << "Node found in tree" << endl;
            return;
        }
        //If value we are looking for is smaller than the current node -> recursively search the left subtree of that node
        else if(val<root->data)
            recursiveSearch(root->left, val);
        //If value we are looking for is larger than the current node -> recursively search the right subtree of that node
        else if(val>root->data)
            recursiveSearch(root->right, val);
    }

    //Uses Loops for search -> not recursion
    node* iterativeSearch(int val)
    {
        //Check is root node is NULL -> tree is empty
        if(root==NULL)
            return root;
        else
        {
            //Traverse Tree till the end or till we find the node we are looking for
            node *temp = root;
            while(temp!=NULL)
            {
                //If node has value we are looking for then return node
                if(val==temp->data)
                    return temp;
                //If val is smaller then go to the left child
                else if(val<temp->data)
                    temp = temp->left;
                //If val is larger then go to right child
                else
                    temp = temp->right;
            }
            //Return null if node is not there in BST
            return NULL;
        }
    }

    //Deleted node with data 'val' from BST
    node* deleteNode(node *n, int val)
    {
        //If node is NULL then return NULL
        if(n==NULL)
        {
            return n;
        }

        //If value to be deleted is smaller than root
        else if(val < n->data)
        {
            //Traverse Left Subtree recursively till we reach node to be deleted
            n->left = deleteNode(n->left, val);
        }

        //If value to be deleted is larger than root
        else if(val > n->data)
        {
            //Traverse right subtree recursively till we reach node to be deleted
            n->right = deleteNode(n->right, val);
        }

        //When we reach the node -> AT NODE TO BE DELETED
        else
        {
            //Deletes leaf node or node with 1 child(left or right)
            //If left child is NULL
            if(n->left==NULL)
            {
                //Stores the value of the right child of the node to be deleted -> so that linking of child nodes can be done and nodes are not lost
                node *temp = n->right;
                //Deletes Node
                delete n;
                //Connects right child to parent node by returning the right child which will get linked in the recursive call
                return temp;
            }

            //If right child is NULL
            else if(n->right==NULL)
            {
                //Stores the value of the left child of the node to be deleted -> so that linking of child nodes can be done and nodes are not lost
                node *temp = n->left;
                //Deletes Node
                delete n;
                //Connects left child to parent node by returning the left child which will get linked in the recursive call
                return temp;
            }

            //Deletes node with 2 children
            else
            {
                //For finding Min value from the right subtree and replacing the root with that node
                node *temp = minValueNode(n->right);
                //Replace root with the min value thus deleting the old root
                n->data = temp->data;
                //Traverse the tree on the right to find and delete the value that was used as the new root
                n->right = deleteNode(n->right, temp->data);

                /*//For finding Max value from the left subtree and replacing the root with that node
                node *temp - maxValueNode(n->left);
                //Replace root with the max value thus deleting the old root
                n->value = temp->value;
                //Traverse the tree on the left to find and delete the value that was used as the new root
                n->left = deleteNode(n->left, temp->value)*/
            }
        }
        return n;
    }

    //Finds the Minimum Value Node
    //We use it when we need to delete a node with 2 children -> The node to be deleted needs to replaced
    //To keep the tree balanced we can replace it with the maxValueNode from the Left Subtree or minValueNode from the Right Subtree
    //Max in the left subtree will be smaller than all the elements in the right subtree yet it will be larger than all elements in the left subtree
    //Min in the right subtree will be larger than all the elements in the left subtree yet it will be smaller than all elements in the right subtree
    //This helps the BST retain its property of having smaller elements on the left and larger elements on the right
    node* minValueNode(node *n)
    {
        //Traverses the tree till the leaf node (only going to the left branches as we are looking for a minimum)
        node *currptr = n;
        //Traverses till the leaf node
        while(currptr->left!=NULL)
        {
            currptr = currptr->left;
        }
        //Returns minValueNode in the particular Tree(from wherever it was called in the particular delete function)
        return currptr;
    }

    //Finds the Maximum Value Node
    node* maxValueNode(node *n)
    {
        //Traverses the tree till the leaf node (only going to the right branches as we are looking for a maximum)
        node *currptr = n;
        //Traverses till the leaf node
        while(currptr->right!=NULL)
        {
            currptr = currptr->right;
        }
        //Returns maxValueNode in the particular Tree(from wherever it was called in the particular delete function)
        return currptr;
    }

    //Calculates Height of Tree
    int height(node *n)
    {
        //If node is null then return -1
        if(n==NULL)
            return -1;
        else
        {
            //Calculates height of left and right branches of tree
            int left_height = height(n->left);
            int right_height = height(n->right);
            //Then returns longest branch with max edges
            if(left_height>right_height)
                return (left_height+1);
            else
                return (right_height+1);
        }
    }

    //Calculates Height of Tree
    int tree_height(node *n)
    {
        //If node is null then return -1
        if(n==NULL)
            return -1;
        //If the node is a leaf node then height is 0 (leaf nodes have height of 0)
        if(isLeaf(n))
            return 0;
        //Return the height of the longer sub-tree and add one as the root node counts as level 0
        //The height of any sub-tree is the height of its longer sub-tree + 1
        return(max(tree_height(n->left), tree_height(n->right)) + 1);
    }

    //Calculates Number of leaf nodes in the tree
    int leafNodeCount(node *n)
    {
        //If node is NULL then there is no node hence return 0
        if(n==NULL)
            return 0;
        //If node left and right pointers are NULL then that node is a leaf node hence return 1
        if(n->left==NULL and n->right==NULL)
            return 1;
        //Recursively find the leaf nodes in the left and right branches of the BST
        else
            return (leafNodeCount(n->left) + leafNodeCount(n->right));
    }

    //Checks if a particular node is a leaf node or not
    bool isLeaf(node *n)
    {
        //If the node has no children then it is a leaf node
        //If left and right pointers are NULL
        if(n->left==NULL and n->right==NULL)
            return true;
        else
            return false;
    }

    //Calculates the sum of all leaf nodes and returns the sum recursively
    int leafSum(node *n)
    {
        //If the node is NULL return 0 as there is no sum
        if(n==NULL)
            return 0;
        //If the node is a leaf node then return the value of that node
        if(isLeaf(n))
            return n->data;
        //Else recursively call the leaf sum function on total for the left and right pointers of each node
        int sum = 0;
        sum += leafSum(n->left);
        sum += leafSum(n->right);

        //Return the sum
        return sum;
    }

    //Prints values of nodes on each level from left to right recursively
    void printGivenLevel(node *n, int level)
    {
        //If node is NULL the return
        if(n==NULL)
            return;
        //If level is 0 there is only 1 node at that point so print that node
        else if(level==0)
            cout << n->data << " ";
        else
        {
            //Access each level recursively
            printGivenLevel(n->left, level-1);
            printGivenLevel(n->right, level-1);
        }
    }

    //LevelOrder BFS -> Level By Level Traversal (left to right)
    void printLevelOrder(node *n)
    {
        //Calculates height of tree
        int h = height(n);

        //Runs for each level and prints each level one by one
        for(int i=0; i<=h; i++)
        {
            printGivenLevel(n, i);
        }
    }

    //Reverse Inorder Traversal
    //RIGHT NODE LEFT
    void print2D(node *n, int space)
    {
        if(n==NULL)
            return;
        else
        {
            space += SPACE;
            print2D(n->right, space);
            cout << endl;
            for(int i=SPACE; i<space; i++)
            {
                cout << " ";
            }
            cout << n->data << endl;;
            print2D(n->left, space);
        }
    }

    //PreOrder DFS -> NODE LEFT RIGHT
    void printPreorder(node *n)
    {
        //If n is NULL then return
        if(n==NULL)
            return;
        //Print data out in order NLR using recursion
        cout << n->data << " ";
        printPreorder(n->left);
        printPreorder(n->right);
    }

    //InOrder DFS -> LEFT NODE RIGHT
    void printInOrder(node *n)
    {
        if(n==NULL)
            return;
        //Print data out in order LNR using recursion
        printInOrder(n->left);
        cout << n->data << " ";
        printInOrder(n->right);
    }

    //PostOrder DFS -> LEFT RIGHT NODE
    void printPostOrder(node *n)
    {
        if(n==NULL)
            return;
        //Print data out in order LRN using recursion
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->data << " ";
    }
};

int main()
{
    //Create Binary Search Tree Object
    BST obj;
    int option, val;

    do
    {
        //Menu to choose which operation to perform
        cout << "Enter operation to be performed: Enter 0 to exit: " << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Printing and Traversal of BST" << endl;
        cout << "5. Height Of Tree" << endl;
        cout << "6. Number Of Leaf Nodes" << endl;
        cout << "7. Sum Of All Leaf Nodes" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. EXIT" << endl;

        //Scan option and create a new node dynamically in the heap memory
        cin >> option;
        node *new_node = new node();

        switch(option)
        {
        //Exit Program
        case 0:
            break;

        case 1:
            cout << "Insert Operation" << endl;
            cout << "Enter value of node to be inserted into BST" << endl;
            cin >> val;
            new_node->data = val;
            obj.insertNode(new_node);
            cout << endl;
            break;

        case 2:
            cout << "Search Operation" << endl;
            cout << "Enter value of node to search in BST" << endl;
            cin >> val;
            //For Iterative Search
            /*new_node = obj.iterativeSearch(val);
            if(new_node!=NULL)
            {
                cout << new_node->data << endl;
                cout << "Value Found" << endl;
            }
            else
            {
                cout << "Value not Found" << endl;
            }*/
            //For Recursive Search
            obj.recursiveSearch(obj.root, val);
            break;

        case 3:
            cout << "Delete Operation" << endl;
            cout << "Enter node data to be deleted: " << endl;
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if(new_node!=NULL)
            {
                obj.deleteNode(obj.root, val);
                cout << "Node Deleted" << endl;
            }
            else
            {
                cout << "Node not found in BST -> Enter another node to be deleted" << endl;
            }
            break;

        case 4:
            cout << "Print and Traverse Operation:" << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            cout << "PreOrder Traversal(DFS):" << endl;
            obj.printPreorder(obj.root);
            cout << endl;
            cout << "InOrder Traversal(DFS):" << endl;
            obj.printInOrder(obj.root);
            cout << endl;
            cout << "PostOrder Traversal(DFS):" << endl;
            obj.printPostOrder(obj.root);
            cout << endl;
            cout << "LevelOrder Traversal(BFS):" << endl;
            obj.printLevelOrder(obj.root);
            cout << endl;
            break;

        case 5:
            cout << "Tree Height" << endl;
            cout << "Height of tree is: " << obj.height(obj.root) << endl;
            cout << "Height of tree is: " << obj.tree_height(obj.root) << endl;
            break;

        case 6:
            cout << "Number of Leaf Nodes: " << endl;
            cout << obj.leafNodeCount(obj.root) << endl;
            break;

        case 7:
            cout << "Sum of All Leaf Nodes: " << endl;
            cout << obj.leafSum(obj.root) << endl;
            break;

        case 8:
            system("cls");
            break;

        default:
            cout << "Enter valid operation" << endl;
        }

    }while(option!=0);

    return 0;
}

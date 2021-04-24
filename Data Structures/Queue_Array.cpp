#include <iostream>
#define MAX 5
using namespace std;

//Queue Class
class Queue
{
private:
    int frnt; //Front of queue
    int rear; //Rear of queue
    int arr[MAX]; //Array to hold queue elements

public:
    //Constructor
    Queue()
    {
        //Sets front and rear to -1(When queue is instantiated it is empty and front and rear represent indexes of the elements)
        frnt = -1;
        rear = -1;
        //Sets all elements in queue to 0 - Initialisation
        for(int i=0; i<MAX; i++)
        {
            arr[i] = 0;
        }
    }

    //Checks if queue is empty
    bool isEmpty()
    {
        //If front and rear are both -1 then index of elements is -1 which doesnt exist thus empty
        if(frnt == -1 && rear == -1)
            return true;
        else
            return false;
    }

    //Checks if queue is full
    bool isFull()
    {
        //If the rear index is MAX-1(last element is present) then queue is full
        if(rear == MAX-1)
            return true;
        else
            return false;
    }

    //Enqueues val into queue
    void enqueue(int val)
    {
        //If queue is full it exits function
        if(isFull())
        {
            cout << "Queue is Full!" << endl;
            return;
        }

        //If its empty then enqueues it to the first element and thus both rear and front are 0
        else if(isEmpty())
        {
            rear = 0;
            frnt = 0;
            //Arr[0] becomes val -> first value in array
            arr[rear] = val;
        }

        //If it isnt empty then rear is incremented (front stays 0 after the first element)
        //After that rear becomes the index at which val is enqueued
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    //Dequeues element from queue
    int dequeue()
    {
        int x;
        //If queue is empty then it exits the function
        if(isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return 1;
        }

        //If front is rear -> then only one element in queue
        else if(frnt == rear)
        {
            //Thus x is set to that element
            x = arr[frnt];
            //The front element(only element) is set to 0
            arr[frnt] = 0;
            //Rear and front are set to -1 to represent an empty queue
            rear = -1;
            frnt = -1;
            //Value of x is returned
            return x;
        }

        //If more than one element in queue
        else
        {
            //x is set to the element to be dequeued(first element) - FIFO
            x = arr[frnt];
            //The element at that index is set to 0 and then the front element is set to be the next element
            arr[frnt] = 0;
            frnt++;
            //Value of x is returned
            return x;
        }
    }

    //Returns number of elements in the queue
    int queueCount()
    {
        return (rear-frnt+1);
    }

    //Displays Queue elements
    void display()
    {
        cout << "Queue Values are: " << endl;
        //Loops over queue printing out all the elements
        for(int i=0; i<MAX; i++)
        {
            cout << arr[i] << "<-";
        }
        cout << endl;
    }
};

int main()
{
    //Instantiates queue
    Queue q1;
    int option, value;

    //Menu driven program with options for operations
    do
    {
        cout << endl << "What operation do you want to perform: Enter 0 to exit: " << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin >> option;
        switch(option)
        {
        case 0:
            break;

        case 1:
            cout << "Enqueue Operation: " << endl;
            cout << "Enter item to Enqueue: " << endl;
            cin >> value;
            q1.enqueue(value);
            break;

        case 2:
            cout << "Dequeue Operation: " << endl;
            cout << "Dequeued value is: " << q1.dequeue() << endl;
            break;

        case 3:
            if(q1.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;

        case 4:
            if(q1.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is not Full" << endl;
            break;

        case 5:
            cout << "Count Operation called" << endl;
            cout << "Count of items in Queue: " << q1.queueCount() << endl;
            break;

        case 6:
            cout << "Display Function Called: " << endl;
            q1.display();
            break;

        case 7:
            system("cls");
            break;

        default:
            cout << "Enter Valid Option" << endl;
        }
    }while(option!=0);

    return 0;
}
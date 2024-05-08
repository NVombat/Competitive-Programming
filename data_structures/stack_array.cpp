//Stack Implementation using Classes and Arrays
#include <iostream>
#include <stdbool.h>
#include <string>
using namespace std;

//Stack class
class Stack
{
private:
    //Top represents the index of the topmost element in the stack
    int top;
    int arr[5]; //arr[n] for n elements -> stores the elements of the stack
public:
    //Constructor
    Stack()
    {
        //When stack object is instantiated it will be empty hence index of topmost element is -1 as there is no topmost element
        top = -1;
        //Initializes all elements in stack to 0
        for(int i=0; i<5; i++)
        {
            arr[i] = 0;
        }
    }

    //Checks if stack is empty
    bool isEmpty()
    {
        //If index of topmost element is -1 then stack is empty
        if(top==-1)
            return true;
        else
            return false;
    }

    //Checks if stack is full
    bool isFull()
    {
        //Index of topmost element will be n-1 for n elements hence if index of topmost element is n-1 then stack is full
        if(top==4) //If stack has n elements then top will have n-1 elements as top starts at -1
            return true;
        else
            return false;
    }

    //Pushes value into stack
    void push(int val)
    {
        //If stack is full then value cant be pushed as stack overflow will be caused
        if(isFull())
            cout << "Stack Overflow" << endl;
        else
        {
            //Increment the value of top as the new element index will be one higher than what it was for the previous element
            top++;
            //Set the element at that index in the array to be the value
            //Since it is a stack it will be the topmost element anyway
            arr[top] = val;
        }
    }

    //Removes element from stack
    int pop()
    {
        //If stack is empty then it will go in underflow state
        if(isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            //Value to be popped is the topmost element which is stores at the "top" index
            int popValue = arr[top];
            //Set value of top element to be 0
            arr[top] = 0;
            //Decrement top to be the previous index hence making the previous element the topmost element
            top--;
            //Return the popped value
            return popValue;
        }
    }

    //Returns number of elements in the stack
    int stackCount()
    {
        return(top+1);
    }

    //Returns element at a particular position in the stack
    int peek(int pos)
    {
        //If empty then output error and return
        if(isEmpty())
        {
            cout << "Stack Empty" << endl;
            return 0;
        }
        else
        {
            //Return the element in the array at that "pos"ition
            return arr[pos];
        }
    }

    //Updates value at specific position in stack
    void change(int pos, int val)
    {
        //Element at "pos"ition is changed to value
        arr[pos] = val;
        cout << "Value changed at location" << endl;
    }

    //Outputs the value of the stack - array elements
    void display()
    {
        cout << "Values of Stack are: " << endl;
        for(int i=4; i>=0; i--) //i = n-1 for n elements
        {
            cout << arr[i] << "-->";
        }
    }
};

int main()
{
    //Creates stack object
    Stack s1;
    int option, position, value;

    //Do while loop for a menu driven program to run stack operations
    do
    {
        cout << "Select Operation to be performed, Enter 0 to Exit: " << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. stackCount()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl << endl;

        //Scan option and use switch case to run each option
        cin >> option;

        switch(option)
        {
        case 0:
            break;

        case 1:
            cout << "Enter Item to push in stack: " << endl;
            cin >> value;
            s1.push(value);
            break;

        case 2:
            cout << "Pop function called -> Popped value: " << s1.pop() << endl;
            break;

        case 3:
            if(s1.isEmpty())
                cout << "Stack is Empty!" << endl;
            else
                cout << "Stack is not Empty!" << endl;
            break;

        case 4:
            if(s1.isFull())
                cout << "Stack is Full!" << endl;
            else
                cout << "Stack is not Full!" << endl;
            break;

        case 5:
            cout << "Enter position of item to peek: " << endl;
            cin >> position;
            cout << "Peek Function called -> Value at position " << position << " is : " << s1.peek(position) << endl;
            break;

        case 6:
            cout << "Count function called -> Number of items in Stack are: " << s1.stackCount() << endl;
            break;

        case 7:
            cout << "Change function called -> " << endl;
            cout << "Enter position of item you want to change : ";
            cin >> position;
            cout << endl;
            cout << "Enter value of item you want to change : ";
            cin >> value;
            s1.change(position, value);
            break;

        case 8:
            cout << "Display Function Called -> " << endl;
            s1.display();
            break;

        case 9:
            system("cls");
            break;

        default:
            cout << "Enter a valid option number" << endl;
        }

        //Keep running until useer enters 0
    }while(option!=0);

    return 0;
}
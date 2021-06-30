#include <iostream>
using namespace std;
int stack[100];
int x = 100 , top = -1;

void push(int value) 
{
    if (top >= x - 1)
    {
        cout << " STACK OVERFLOW " << endl;
    }
        
    else 
    {
        top++;
        stack[top] = value;
    }
}


void pop() 
{
    if (top < -1)
    {
        cout << " STACK UNDERFLOW " << endl;
    }
        
    else 
    {
        cout << stack[top] << endl;
        top--;
    }
}


void print() 
{
    if (top >= 0) 
    {
        cout << "THE ELEMENTS IN THE STACK ARE: "<<endl;
        for (int i = top; i >= 0; i--)
        {
            pop();
        }
        cout << endl;
    }
    else
    {
        cout << "STACK IS EMPTY";
    }
        
}


int main() 
{

    int c, val;

    cout << "1) Push " << endl;
    cout << "2) Pop " << endl;
    cout << "3) Print " << endl;
    cout << "4) Exit" << endl;

    do 
    {
    
        cout << "Enter choice: " << endl;
        cin >> c;
        
        switch (c) 
        {
        case 1: 
        {
            cout << "Enter value you want to push:" << endl;
            cin >> val;
            push(val);
            break;
        }
        case 2: 
        {
            cout << "THE POPPED ELEMENT IS: ";
            pop();
            break;
        }
        case 3: 
        {
            print();
            break;
        }
        case 4: 
        {
            cout << "Exit" << endl;
            break;
        }
        default: 
        {
            cout << "Invalid, choose again" << endl;
        }
        
        }
    } while (c != 4);

    return 0;
}
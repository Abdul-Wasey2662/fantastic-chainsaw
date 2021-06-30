#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class stack
{

private:
	node* temp, * top;
	int x, c;

public:
	stack()
	{
		cout << "Enter limit for stack : ";
		cin >> x;
		c = 1;
		temp = top = NULL;
	}


	void push()
	{
		if (top == NULL)
		{
			top = new node;
			cout << "Enter value to be pushed: ";
			cin >> top->data;
			top->next = NULL;
			c++;
			return;
		}
		if (c > x)
		{
			cout << "--STACK OVERFLOW--" << endl;
			return;
		}
		else
		{
			temp = new node;
			cout << "Enter value: ";
			cin >> temp->data;
			temp->next = top;
			top = temp;
			c++;
			return;
		}
	}


	void pop()
	{
		if (top == NULL)
		{
			cout << "--STACK UNDERFLOW--" << endl;
			return;
		}
		temp = top;
		top = top->next;
		cout << "The popped element is: " << temp->data << endl;
		delete temp;
		temp == NULL;
		return;
	}

	void display()
	{	
		if (top == NULL)
			cout << "STACK IS EMPTY";
		else 
		{
			temp = top;
			cout << "Stack elements are: ";
			while (temp != NULL) 
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		cout << endl;
	}
};

int main()
{
	
	stack obj;
	int ch = 0;
	do
	{
		cout << "---------------------------------" << endl;
		cout << "| 1.push 2.pop 3.display 4.Exit |" << endl;
		cout << "---------------------------------" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			obj.push();
			break;
		case 2:
			obj.pop();
			break;
		case 3:
			obj.display();
			break;
		case 4:
			cout << "Exited" << endl;
			break;

		}

	} while (ch != 4);

	return 0;
}
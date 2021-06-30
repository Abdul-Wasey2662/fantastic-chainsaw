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
	~stack(){}
	
	void push()
	{
		if (top == NULL)
		{
			top = new node;
			cout << "emter value : ";
			cin >> top->data;
			top->next = NULL;
			c++;
			return;
		}
		if (c > x)
		{
			cout << "--stack overflow--" << endl;
			return;
		}
		else
		{
			temp = new node;
			cout << "emter value : ";
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
			cout << "--Stack underflow--" << endl;
			return;
		}
		temp = top;
		top = top->next;
		delete temp;
		temp == NULL;
		return;
	}

	void val_top()
	{
		if (top == NULL)
		{
			cout << "--Stack is empty--" << endl;
			return;
		}
		cout << "top is : " << top->data << endl;
		return;
	}
};

int main()
{
	stack s;
	int a=0;
	char x = 'y';
	while (x == 'y')
	{
		cout << "1.push 2.pop 3.top" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			s.push();
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.val_top();
			break;
		}
		cout << "do u want to perform another operation? (y/n) ";
		cin >> x;
	}
}
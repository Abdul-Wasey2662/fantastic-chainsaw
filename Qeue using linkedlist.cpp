#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class qeue
{
private:
	node* rear, * front, * temp;
	int c, x;
public:
	qeue()
	{
		cout << "enter limit for qeue : ";
		cin >> x;
		rear = front = NULL;
		c = 0;
	}
	void enqeue()
	{
		if (c >= x)
		{
			cout << "--Qeue overflow--" << endl;
		}
		else
		{
			if (rear == NULL)
			{
				rear = new node;
				cout << "enter value : ";
				cin >> rear->data;
				rear->next = NULL;
				front = rear;
				c++;
				return;
			}
			rear->next = new node;
			rear = rear->next;
			rear->next = NULL;
			cout << "enter value : ";
			cin >> rear->data;
			c++;
			return;
		}
	}

	void deqeue()
	{
		if (c <= 0)
		{
			cout << "--Qeue is empty--" << endl;
			return;
		}
		else
		{
			temp = front;
			front = front->next;
			delete temp;
			temp = NULL;
			c--;
			return;
		}
	}

	void return_val()
	{
		if (c <= 0)
		{
			cout << "--Qeue underflow--" << endl;
			return;
		}
		else
		{
			cout << front->data << endl;
			return;
		}
	}

};

int main()
{
	qeue q;
	int a;
	char x = 'y';
	while (x == 'y')
	{
		cout << "1.enqeue 2.deqeue 3.front value" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			q.enqeue();
			break;
		case 2:
			q.deqeue();
			break;
		case 3:
			q.return_val();
			break;
		}
		cout << "do u want to perform another operation? (y/n) ";
		cin >> x;
	}
}
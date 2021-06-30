#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class SLL
{
private:
	node* head, * temp, * temp1;
public:
	SLL()
	{
		head = temp = temp1 = NULL;
	}
	void print()
	{
		if (head == NULL)
		{
			cout << "--LINKED LIST IS EMPTY--" << endl;
			return;
		}
		temp = head;
		cout << "-- your linked list is --" << endl;
		while (temp != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << endl;
	}
	void add()
	{
		if (head == NULL)
		{
			head = new node;
			cout << "Enter value for first node : ";
			cin >> head->data;
			head->next = NULL;
			print();
			return;
		}
		temp = head;
		cout << "do u want to add 1.node after a node 2.before head node : (1/2) ";
		int a;
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1:
		{
			cout << "Enter the value after which u want to add a new node : ";
			int x;
			cin >> x;
			while (temp != NULL)
			{
				if (x == temp->data)
				{
					temp1 = new node;
					cout << "Enter value for new node : ";
					cin >> temp1->data;
					cout << endl;
					temp1->next = temp->next;
					temp->next = temp1;
					print();
					return;
				}
				temp = temp->next;
			}
			break;
		}
		case 2:
		{
			temp = new node;
			cout << "Enter value for new node before head : ";
			cin >> temp->data;
			cout << endl;
			temp->next = head;
			head = temp;
			print();
			return;
		}
		break;
		}

	}
	void del()
	{
		if (head == NULL)
		{
			cout << "--LINKED LIST IS EMPTY--" << endl;
			return;
		}
		cout << "Enter the node which u want to delete : ";
		int x;
		cin >> x;
		temp = head;
		while (temp != NULL)
		{
			if (x == head->data)
			{
				if (head->next == NULL)
				{
					delete head;
					head = NULL;
					print();
					return;
				}
				temp1 = head;
				head = temp1->next;
				delete temp1;
				cout << "--node deleted--" << endl;
				temp1 = NULL;
				print();
				return;
			}
			if (temp->next->data == x)
			{
				temp1 = temp->next;
				temp->next = temp1->next;
				delete temp1;
				temp1 = NULL;
				cout << "--node deleted--" << endl;
				print();
				return;
			}
			
			temp = temp->next;
		}
	}
};

int main()
{
	SLL obj;
	int a;
	char x = 'y';
	while (x == 'y')
	{
		cout << "1.add 2.Delete 3.Print" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			obj.add();
			break;
		case 2:
			obj.del();
			break;
		case 3:
			obj.print();
			break;
		}
		cout << "do u want to perform another operation? (y/n) ";
		cin >> x;
	}
}
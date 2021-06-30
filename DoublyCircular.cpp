#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};

class DLL
{
private:
	node* head, * temp, * temp1;

public:
	DLL()
	{
		head = temp = temp1 = NULL;
	}


	void Print()
	{
		if (head == NULL)
		{
			cout << "**LINKED LIST IS EMPTY**" << endl;
			return;
		}
		temp = head;
		cout << "YOUR DOUBLLY LINKED LIST IS === " ;
		while (temp != NULL)
		{
			cout << temp->data << " <-> ";
			temp = temp->next;
		}
		cout << endl;
	}


	void Insertion()
	{
		if (head == NULL)
		{
			head = new node;
			cout << "Enter the value for first node : ";
			cin >> head->data;
			head->next = NULL;
			head->prev = NULL;
			Print();
			return;
		}
		temp = head;
		cout << "Do u want to add node:" << endl;
		cout<<"	1.after a node " <<endl;
		cout<<"	2.before head node " <<endl;
		int a;
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1:
		{
			cout << "Enter the value after which you want to add a new node: ";
			int x;
			cin >> x;
			temp = head;
			while (temp != NULL)
			{
				if (x == temp->data)
				{
					if (temp->next == NULL)
					{
						temp1 = new node;
						cout << "Enter value for new node: ";
						cin >> temp1->data;
						cout << endl;
						temp->next = temp1;
						temp1->next = NULL;
						temp1->prev = temp;
						Print();
						return;
					}
					temp1 = new node;
					cout << "Enter value for new node: ";
					cin >> temp1->data;
					cout << endl;
					temp1->next = temp->next;
					temp->next = temp1;
					temp1->prev = temp;
					if (temp->next != NULL)
					{
						temp1->next->prev = temp1;
					}
					Print();
					return;
				}
				temp = temp->next;
			}
			break;
		}
		case 2:
		{
			temp = new node;
			cout << "Enter value for new node before head: ";
			cin >> temp->data;
			cout << endl;
			temp->next = head;
			head->prev = temp;
			temp->prev = NULL;
			head = temp;
			Print();
			return;
		}
		break;
		}

	}
	
	
	void Deletion()
	{
		if (head == NULL)
		{
			cout << "**LINKED LIST IS EMPTY**" << endl;
			return;
		}
		
		cout << "Enter the node which you want to delete: ";
		int x;
		cin >> x;
		temp = head;
		if (x == head->data)
		{
			temp1 = head;
			head = temp1->next;
			delete temp1;
			cout << "**NODE DELETED**" << endl;
			temp1 = NULL;
			Print();
			return;
		}
		else
		{
			while (temp != NULL)
			{

				if (temp->data == x)
				{
					temp1 = temp->prev;
					temp->prev->next = temp->next;
					if (temp->next != NULL)
					{
						temp->next->prev = temp1;
					}
					delete temp;
					temp = temp1;
					cout << "**NODE DELETED**" << endl;
					Print();
					return;
				}
				temp = temp->next;
			}
		}
	}
};


int main()
{
	
	DLL obj;
	int x;
	char ch = 'y';
	do
	{
		
		cout << "1.Insertion 2.Deletion 3.Print" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
			obj.Insertion();
			break;
		case 2:
			obj.Deletion();
			break;
		case 3:
			obj.Print();
			break;
		}
		cout << "Do you want to perform another operation ? (y/n) ";
		cin >> ch;

	} while (ch=='y');

	system("pause");
	return 0;

}
#include<iostream>
using namespace std;

int arr[100];
int s = 100;
int front = -1, rear = -1;

void enque()
{
	int value;
	cout << "Enter the value to insert in queue: " << endl;
	cin >> value;
	if (rear == s - 1)
	{
		cout << "***QUEUE OVERFLOW***" << endl;
	}

	else
	{
		if (front == -1)
		{
			front = 0;
		}
		rear++;
		arr[rear] = value;
	}
}

void deque()
{
	if (front == -1 || front > rear)
	{
		cout << "***QUEUE UNDERFLOW***" << endl;;
		return;
	}

	else
	{
		cout << "Element deleted is: " << arr[front] << endl;
		front++;;
	}
}

void display()
{
	if (front == -1 &&  rear==-1)
	{
		cout << "***QUEUE IS EMPTY***" << endl;
	}

	else
	{
		cout << "Elements in queue are: " << endl;
		for (int i = front; i <= rear; i++)
		{
			cout << arr[i] << " " << endl;
		}
	}
}

int main()
{
	int ch;
	cout << "1) Enqueue" << endl;
	cout << "2) Dequeue" << endl;
	cout << "3) Display" << endl;
	cout << "4) Exit" << endl;
	do 
	{
		cout << "Enter choice: " << endl;
		cin >> ch;

		if (ch == 1)
		{
			enque();
		}

		else if (ch == 2)
		{
			deque();
		}

		else if (ch == 3)
		{
			display();
		}

		else if (ch == 4)
		{
			cout << " EXIT " << endl;
		}

		else
		{
			cout << " Invalid choice, Enter correct number " << endl;
		}

	} while (ch != 4);
	return 0;
}
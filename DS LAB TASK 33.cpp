#include <iostream>
using namespace std;

	struct node
	{
		int data;
		node* next;
	};

	class LinkedList
	{
	private:
		node* head;
		node* tail;
	
	public:
		
		LinkedList()
		{
			head = NULL;
			tail = NULL;
		}



		void Sucessor()
		{

			struct node* temp1 = head;
			int maximum = INT_MIN;
			
			if (head == NULL)
			{
			
				cout << "LIST HAS NO NUMBERS" << endl;
			
			}
			
			
			while (head != NULL)
			{
			
				if (maximum < head->data)
				{
				
					maximum = head->data;
				
				}

				head = head->next;
			
			}
			
			
			cout << " ENTER A NUMBER FROM THE ABOVE LIST: " << endl;
			int x;
			cin >> x;
			
			
			if (x == maximum)
			{
				cout << " THE MAX NUMBER IS: " << maximum << endl; 
			}


			if (x != maximum)
			{

				x = head->data;
				while (temp1 != NULL)
				{
				
					x = temp1->data;
					while (x + 1)
					{

						if (x + 1 == temp1->data)
						{
						
							break;
						
						}
					
					}
				
				}
				
				temp1 = temp1->next;
				cout << x << endl;

			}

		}


		void AddNode(int a)
		{
		
			
			node* temp2 = new node;
			temp2->data = a;
			temp2->next = NULL;

			if (head == NULL)
			{
			
				head = temp2;
				tail = temp2;
			
			}
			
			else
			{
			
				tail->next = temp2;
				tail = tail->next;
			
			}
		
		}
		void print()
		{
			
			cout << "LINKED LIST IS AS FOLLOWS:"<<endl;
			node* temp = new node;
			temp = head;
		
			while (temp != NULL)
			{
			
				cout << temp->data << "\t";
				temp = temp->next;
			
			}
		
		
		}

	};

	int main()
	{
	
		struct node* head = NULL;
		
		LinkedList obj;
		
		obj.AddNode(11);
		obj.AddNode(20);
		obj.AddNode(36);
		obj.AddNode(40);
		obj.AddNode(52);
		obj.AddNode(64);
		obj.AddNode(75);
		obj.AddNode(80);
		obj.print();
		cout << endl;
		obj.Sucessor();
	
		
		return 0;

	}
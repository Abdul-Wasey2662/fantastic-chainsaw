#include<iostream>
using namespace std;
struct node
{
	
	int data;
	node* next;

};


class SinglyRingList
{

private:
	node* head;

public:

	SinglyRingList() :head(NULL){}

	node* create_node(int value)
	{
		
		node* data = new node();
		data->data = value;
		data->next = NULL;
		return data;
	
	}


	node* get_tail()
	{

		node* iterate = head;
		if (head->next=head)
		{
			return head;
		}

		while (iterate->next!=head)
		{
			iterate = iterate->next;
		}
	   
		return iterate;

	}


	void add_node_to_tail(int value) 
	{
		
		if (head==NULL)
		{
			head = create_node(value);
			head->next = head;
			return;
		}

		node* tail = get_tail();
		node* link_node = create_node(value);
		link_node->next = tail->next;
		tail->next = link_node;

	}

    
	node* search_node(int key)
	{
		node* iterate = head;
		while (iterate->data!=key)
		{
			iterate = iterate->next;
		}

	}


	void add_node_at_value(int val, int key)
	{
		
		node* key_node = search_node(key);
		node* link_node = create_node(val);
		link_node->next = key_node->next;
		key_node->next = link_node;

	}


	node* get_prev(node* random_node)


	void delete_node(int key)
	{
		
		node* tail = get_tail();
		node* del_node = search_node(key);
		node* prev = get_prev(del_node);
		if (head->data==key)
		{
			tail->next = head->next;
			node* del = head;
			head = head->next;
			delete del;
			del = NULL;
		}

		else if (del_node->next==head)
		{
			prev->next = del_node->next;
			delete del_node;
			del_node = NULL;
		}

		else
		{
			prev->next
		}


	}


	void print()
	{
		
		node* iterate = head;
		do
		{
			cout << iterate->data << "";
			iterate = iterate->next;
		} while (iterate!=head);
		cout << endl;

	}


};


int main()
{

	SinglyRingList obj;
	obj.add_node_to_tail(5);
	obj.add_node_to_tail(6);
	obj.add_node_to_tail(7);
	
	obj.print();


	system("pause");
	return 0;
}
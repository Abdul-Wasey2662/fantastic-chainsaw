/*
ARRAY BASED LIST
*/
#include<iostream>
#include<string>
using  namespace std;

class list 
{
private:
	int* arr; //will be used to initialize an empty list and will always point to the first position.
	int size; //total capcity of the list
	int len; //number of current elements in the list
	int* current; //pointer to point the current position
	int* temp; //can be used for temporary works
public:

	//Constructor for initializing List
	//You can initialize size to any value
	list() 
	{
		size = 4;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 123;
			cout << arr[i] << "  " << endl;
		}
		current = arr;
		len = 0;
		current = NULL;
		temp = NULL;
	
		cout << "End of list" << endl;
	}


	//overloaded constructor
	//user will pass decided the size of the list
	list(int userSize) 
	{
		cout << "Enter the size of list: ";
		cin >> userSize;
		arr = new int[userSize];
		for (int i = 0; i < userSize; i++)
		{
			cin >> arr[i];
		}
		current = arr;
		cout << endl;
		cout << "user defined list is: " << endl;
		for (int j = 0; j < userSize; j++)
		{
			cout << arr[j] << " " << endl;
		}
		len = 0;
		current = NULL;
		temp = NULL;
		cout << "End of list" << endl;
	}

	//Deep Copy Constructor
	//write code to create a new list and copy elements of the list passed in the parameter
	list(list& othrList) 
	{


	}


	//Clear Or Empty the List
	void clear() 
	{
		current = arr;
		for (int i = 0; i < size; i++)
		{
			arr[i] = NULL;
		}
	}


	//Insert a Value at Specific Position
	void insert(int value, int pos) 
	{
		if (size < len)
		{
			if (pos == 0)
			{
				current = arr;
				if (current==arr)
				{
					*current == value;
					size++;
				}
			
			}
			else if (pos == size)
			{
				if (size == 0)
				{
					*current = value;
					size ++ ;
					current++ ;
				}
			}
			else
			{
				current = arr + size;
				pos = size - pos;
				while (pos != 0)
				{
					current--;
					*(current + 1) = *current;
					pos -= 1;
				}
				*current = value;
				size += 1;
			}
		}


	}

	//Insert the given value in the list at the next available position
	void insert(int value) 
	{
		current = arr;
		for (int i = 0; i <= size ; i++) 
		{

			if (*current == size ) 
			{
				*current = value;
			}
			current++;
			size++;
		
		}
	}


	//Remove a value at specific position
	void remove(int pos) 
	{
		current = arr;
		for (int i = 0; i <= pos; i++)
		{
			current++;
			if (i=pos)
			{
				delete current;
			}
		}
		size--;
	}



	//Get value stored at a specific position
	int get(int pos) 
	{
		current = arr;
		int x;
		if (current == NULL) 
		{
			return 0;
		}

		for (int i = 0; i <= size; i++) 
		{
			if (i == pos) 
			{
				x = *current;
			}
			current++;
		}
		return x;
	}

	//Update Existing value at a position
	void update(int value, int pos) 
	{
		current = arr;
		for (int i = 0; i <= size; i++)
		{

			if (i == pos)
			{
				*current = value;
			}
		
			current++;
		}

	}


	//Find a value in the list
	bool find(int value) 
	{
		current = arr;
		while (current != arr + size)
		{
			if (*current == value)
			{
				return true;
				cout << value << " FOUND" << endl;
			}
			current++;
		}

		return false;
	}


	//Return Current Length of the list
	int length() 
	{
		return len;
		cout << "The length of the list is: " << len << endl;
	}


	//Move to starting position of the list
	void start() 
	{
		current = arr;
	}

	//Move to the end of the list
	void end() 
	{
		current = arr + size;
	}


	//checks whehter the list is completely filled or not
	bool isFull() 
	{
		if (size==len)
		{
			return true;
			cout << "LIST IS FILLED" << endl;
		}
		return false;
	}

	//checks whehter the list is completely empty or not    
	bool isEmpty() 
	{
		current = arr;
		if (current==NULL)
		{
			return true;
			cout << "LIST IS EMPTY" << endl;
		}
		return false;
	}

};

void main() 
{
	list obj;
	list(5);
	obj.find(3);
	obj.get(2);
	obj.insert(4);
	obj.update(1,5);
	obj.isEmpty();
	obj.isFull();


	system("pause");
}
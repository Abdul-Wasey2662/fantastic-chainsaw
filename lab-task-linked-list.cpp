#include<iostream>
using namespace std;


struct node 
{
    int value;
    node* next;
};

class LinkedList 
{
private:
    node* head, * temp, * temp2 , *tail; //head will always point to first element, temp and temp2 will be used for moving and adding new nodes in the list

public:
    LinkedList() 
    {
        head = NULL;
        temp = NULL;
        temp2 = NULL;
    }

    //you can take value using user input within function or by passing value to the add function using a parameter
    //assuming you will use user input within function
    void add(int data) 
    {

        //code for checking whether the first element exists or not
        //if 1st element doesn't exists, write code to create 1st element
        //first element will always be pointed by head pointer
      
        
    
        //if first element already exsist, move the temp pointer to the last element

        node* temp = new node;
        temp->value = data;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }

        if (temp->next != NULL) 
        {

        }

        //create a new node
        //assign it a value
        //make it's next pointer null
        //the newly created node will be poined by the next pointer of last node
        //your code goes here

    }

    //function to add a new value after an existing value
    //you can take value using user input within function or by passing value to the add function using a parameter
    //assuming you will use user input within function
    void addAfterSomeValue(int pos, int val)
    { //val parameter is for the value after which we want to add another value
        node* curr = new node;
        temp = head;

        for (int i = 0; i < pos; i++)
        {
            temp2 = temp;
            temp = temp->next;
        }
        curr->value = val;
        temp2->next = curr;
        curr->next = temp;
        //write code to find the value after which you want to add the new value
        //create a new node,assign it value
        //assign the address of the next pointer of the node which is pointed by temp to the next pointer of newly created node 
        //assign the address of newly created node to the next pointer of node pointed by temp
        //your code goes here

    }

    void del_1st(int val)
    {//val contains the value to be deleted, if the value exists multiple times in the list, then delete it's first occurence
        
        temp = head;

        //check whether the list is empty or not, if list is empty, prompt a message and return
        if (head==NULL)
        {
            cout << "Your list is empty";
            return;
        }

        //cout << "Enter the node which u want to delete : ";
        //cin >> val;
        temp = head;
        while (temp->next != NULL)
        {
            if (val == head->value)
            {
                if (head->next == NULL)
                {
                    delete head;
                    head = NULL;
                    return;
                }
                temp2 = head;
                head = temp2->next;
                delete temp2;
                cout << "\\Node deleted//" << endl;
                temp2 = NULL;
                return;
            }
            if (temp->next->value == val)
            {
                temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                temp2 = NULL;
                cout << "\\Node deleted//" << endl;
                return;
            }
            
            temp = temp->next;
        }


        //write code to find the node having the desired value,if first element doesn't containws the desired value
        //hint: you need to check value of each next node while staying on the previous node
        //once node with desired value is found, first make arrangement for next pointer
        //delete the node with the value
        //return
        //your code goes here
        cout << "\\Node not found//" << endl;

        return;
    }//function end

    void print() 
    { 
        
        //function to print all the values of the list
        temp = head;
        cout << "YOUR LINKED LIST IS: " << endl;

        while (temp != NULL) 
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
        
    }
};




void main() 
{

    LinkedList obj;

    obj.add(1);//1
    obj.add(2);//2
    obj.add(3);//3
    obj.add(4);//4
    obj.add(3);//3
    obj.print();

   cout << "After Value.." << endl;
    obj.addAfterSomeValue(3,5);//3
    cout << "\n\n\n\n\n";
    obj.print();

    cout << "\nDelete" << endl;

   obj.del_1st(1);
    cout << endl;
    obj.print();
    obj.del_1st(3);
    cout << endl;
    obj.print();
    obj.del_1st(6);
    cout << endl;
    obj.print();

    system("pause");
}
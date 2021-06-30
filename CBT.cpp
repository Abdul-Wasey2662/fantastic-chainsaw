#include<iostream>
#include<string>
#include<math.h>
using namespace std;
struct node 
{
    int data;
    node* left, * right;
};

class CBT 
{
    node* root;

public:

    CBT()
    {
        root = NULL;
    }

    node* getNode()
    {
        return root;
    }

    node* newNode(int key)
    {
        node* temp1 = new node;
        temp1->data = key;
        temp1->left = temp1->right = NULL;

        return temp1;
    }



    void Inseration(node* temp, int data)
    {
        node* ptr1;
        ptr1 = newNode(data);
        if (root == NULL)
        {
            root = ptr1;
            return;
        }
        else
        {



            int height =  (temp->left);
            int exceptNode = pow(2, height) - 1;
            int leftTreeCount = countNumNodes(temp->left);
            int rightTreeCount = countNumNodes(temp->right);

            if (leftTreeCount == rightTreeCount)
            {
                Inseration(temp->left, data);
            }
            else if (exceptNode != leftTreeCount)
            {
                if (temp->left == NULL)
                {
                    temp->left = ptr1;
                    return;
                }
                else
                {
                    Inseration(temp->left, data);

                }
            }
            else if (temp->right == NULL)
            {
                temp->right = ptr1;
                return;
            }
           
            else if (exceptNode != leftTreeCount)
            {
                
                if (temp->left == NULL)
                {
                    temp->left = ptr1;
                    return;
                }
                
                else
                {
                    Inseration(temp->right, data);
                }

            }



        }
    }

    void display(node* root) 
    {
        if (root == NULL)
        {
            return;
        }
        
        display(root->left);
        
        cout << root->data << " ";
        
        display(root->right);
    }





};

int main()
{
    CBT obj;
    node* r = NULL;
    obj.Inseration(obj.getNode(), 2);
    obj.Inseration(obj.getNode(), 4);
    obj.Inseration(obj.getNode(), 3);
    obj.Inseration(obj.getNode(), 5);
    obj.Inseration(obj.getNode(), 6);
    obj.Inseration(obj.getNode(), 8);
    obj.Inseration(obj.getNode(), 9);
    obj.display(obj.getNode());

    return 0;
}
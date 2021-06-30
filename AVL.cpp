#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node* left;
    struct node* right;
    int ht;
}*root;


class AVL_TREE 
{

public:

    AVL_TREE()
    {
        root = NULL;
    }

    int height(node*t)
    {
        int h = 0;
        if (t != NULL) 
        {
            int l_height = height(t->left);
            int r_height = height(t->right);
            int max_height = max(l_height, r_height);
            h = max_height + 1;
        }
        
        return h;
    }

    int difference(node* t)
    {
        int l_height = height(t->left);
        int r_height = height(t->right);
        int b_factor = l_height - r_height;
        return b_factor;
    }

    node* RightRight_rotation(node* parent)
    {
        node* t;
        t = parent->right;
        parent->right = t->left;
        t->left = parent;
        cout << "Right-Right Rotation";
        return t;
    }

    node* LeftLeft_rotation(node* parent)
    {
        node* t;
        t = parent->left;
        parent->left = t->right;
        t->right = parent;
        cout << "Left-Left Rotation";
        return t;
    }


    node* LeftRight_rotation(node* parent)
    {
        node* t;
        t = parent->left;
        parent->left = RightRight_rotation(t);
        cout << "Left-Right Rotation";
        return LeftLeft_rotation(parent);
    }


    node* RightLeft_rotation(node* parent)
    {
        node* t;
        t = parent->right;
        parent->right = LeftLeft_rotation(t);
        cout << "Right-Left Rotation";
        return RightRight_rotation(parent);
    }


    node* balance(node* t)
    {
        int bal_factor = difference(t);
        if (bal_factor > 1) 
        {
            if (difference(t->left) > 0)
                t = LeftLeft_rotation(t);
            else
                t = LeftRight_rotation(t);
        }
        
        else if (bal_factor < -1) 
        {
            if (difference(t->right) > 0)
                t = RightLeft_rotation(t);
            else
                t = RightRight_rotation(t);
        }
        
        return t;
    }


    node* insert(node* r , int v)
    {
        if (r == NULL) 
        {
            r = new node;
            r->data = v;
            r->left = NULL;
            r->right = NULL;
            return r;
        }
        
        else if (v < r->data) 
        {
            r->left = insert(r->left, v);
            r = balance(r);
        }
        
        else if (v >= r->data) 
        {
            r->right = insert(r->right, v);
            r = balance(r);
        } 
        
        return r;
    }




    node* Delete(node* T, int x)
    {
        node* p;

        if (T == NULL)
        {
            return NULL;
        }
        else
            if (x > T->data)
            {
                T->right = Delete(T->right, x);
                if (difference(T) == 2)
                    if (difference(T->left) >= 0)
                        T = LeftLeft_rotation(T);
                    else
                        T = LeftRight_rotation(T);
            }
            else
                if (x < T->data)
                {
                    T->left = Delete(T->left, x);
                    if (difference(T) == -2)
                        if (difference(T->right) <= 0)
                            T = RightRight_rotation(T);
                        else
                            T = RightLeft_rotation(T);
                }
                else
                {
                    if (T->right != NULL)
                    {
                        p = T->right;

                        while (p->left != NULL)
                            p = p->left;

                        T->data = p->data;
                        T->right = Delete(T->right, p->data);

                        if (difference(T) == 2)
                            if (difference(T->left) >= 0)
                                T = LeftLeft_rotation(T);
                            else
                                T = LeftRight_rotation(T); \
                    }
                    else
                        return(T->left);
                }
        T->ht = height(T);
        return(T);
    }





    void show(node* p, int l)
    {
        int i;
        if (p != NULL) 
        {
            show(p->right, l + 1);
            cout << " ";
            if (p == root)
                cout << "Root --> ";
            for (i = 0; i < l && p != root; i++)
                cout << " ";
            cout << p->data;
            show(p->left, l + 1);
        }
    }


    void inorder(node* t)
    {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

};


int main() 
{
    int choice, i;
    AVL_TREE obj;
    while (1) {
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.Show Balanced AVL Tree" << endl;
        cout << "3.InOrder traversal" << endl;
        cout << "4.Deletion" << endl;
        cout << "5.Exit" << endl;

        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice) 
        {
        case 1:
            cout << "Enter value: ";
            cin >> i;
            root = obj.insert(root, i);
            break;
        
        case 2:
            if (root == NULL) 
            {
                cout << "***TREE IS EMPTY***" << endl;
                continue;
            }
            
            cout << "Balanced AVL Tree:" << endl;
            obj.show(root, 1);
            cout << endl;
            break;
        
        case 3:
            if (root == NULL)
            {
                cout << "***TREE IS EMPTY***" << endl;
                continue;
            }

            cout << endl;
            cout << "Inorder Traversal:" << endl;
            obj.inorder(root);
            cout << endl;
            break;


        case 4:

            if (root == NULL)
            {
                cout << "***TREE IS EMPTY***" << endl;
                continue;
            }

            cout << "Enter a element to be deleted : ";
            cin >> i;
            root = obj.Delete(root, i);
            cout <<"*** "<< i <<" deleted ***" << endl;
            cout << endl;
            break;

        case 5:

            exit(1);
            cout << "Exited." << endl;
            break;
        

        default:
            cout << "Invalid Choice" << endl;
        
        }
    }
    
    return 0;
}
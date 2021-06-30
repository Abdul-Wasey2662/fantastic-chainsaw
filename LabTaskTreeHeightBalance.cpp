#include<iostream>
#define SPACE 10
using namespace std;

class TreeNode 
{

public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode() 
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    
    TreeNode(int v) 
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST 
{
public:
    TreeNode* root;
    BST() 
    {
        root = NULL;
    }
    bool isTreeEmpty() 
    {
        if (root == NULL) 
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    void insertNode(TreeNode* new_node) 
    {
        if (root == NULL) 
        {
            root = new_node;
            cout << "Value Inserted as root!" << endl;
        }
        
        else {
            TreeNode* temp = root;
            while (temp != NULL) 
            {
                if (new_node->value == temp->value) 
                {
                    cout << "Value Already exists," <<
                        "Insert another value!" << endl;
                
                    return;
                }
                else if ((new_node->value < temp->value) && (temp->left == NULL)) 
                {
                    temp->left = new_node;
                    cout << "Value Inserted to the left!" << endl;
                    break;
                }
                
                else if (new_node->value < temp->value) 
                {
                    temp = temp->left;
                }
                
                else if ((new_node->value > temp->value) && (temp->right == NULL)) 
                {
                    temp->right = new_node;
                    cout << "Value Inserted to the right!" << endl;
                    break;
                }

                else 
                {
                    temp = temp->right;
                }
            }
        }
    }


    TreeNode* insertRecursive(TreeNode* r, TreeNode* new_node)
    {
        if (r == NULL)
        {
            r = new_node;
            cout << "Insertion successful" << endl;
            return r;
        }

        if (new_node->value < r->value)
        {
            r->left = insertRecursive(r->left, new_node);
        }
    
        else if (new_node->value > r->value)
        {
            r->right = insertRecursive(r->right, new_node);
        }
       
        else
        {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }
        
        return r;
    }


    void printPreorder(TreeNode* r) //(Node, Left, Right) 
    {
        if (r == NULL)
            return;
        cout << r->value << " ";
        printPreorder(r->left);
        printPreorder(r->right);
    }

    void printInorder(TreeNode* r) //  (Left, Node, Right)
    {
        if (r == NULL)
            return;
        printInorder(r->left);
        cout << r->value << " ";
        printInorder(r->right);
    }
  
    void printPostorder(TreeNode* r) //(Left, Right, Node)
    {
        if (r == NULL)
            return;
        printPostorder(r->left);
        printPostorder(r->right);
        cout << r->value << " ";
    }

    TreeNode* iterativeSearch(int v) 
    {
        if (root == NULL) 
        {
            return root;
        }
        
        else 
        {
            TreeNode* temp = root;
            while (temp != NULL) 
            {
                if (v == temp->value) 
                {
                    return temp;
                }
                else if (v < temp->value) 
                {
                    temp = temp->left;
                }
                else 
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }



    bool checkBalance(TreeNode* root, int* height) 
    {
        // Check for emptiness
        int leftHeight = 0, rightHeight = 0;
        int l = 0, r = 0;

        if (root == NULL) 
        {
            *height = 0;
            return 1;
        }

        l = checkBalance(root->left, &leftHeight);
        r = checkBalance(root->right, &rightHeight);

        *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

        if (std::abs(leftHeight - rightHeight >= 2))
        {
            return 0;
        }
        
        else
        {
            return l && r;
        }
    
    }



    int height(TreeNode* r) 
    {
        if (r == NULL)
            return -1;
      
        else 
        {
            int lheight = height(r->left);
            int rheight = height(r->right);

            if (lheight > rheight)
                return (lheight + 1);
            else return (rheight + 1);
        }
    
    }


    TreeNode* minValueNode(TreeNode* node) 
    {
        TreeNode* current = node;
        while (current->left != NULL) 
        {
            current = current->left;
        }
        return current;
    }

    TreeNode* deleteNode(TreeNode* r, int v) 
    {
        if (r == NULL) 
        {
            return NULL;
        }
        
        else if (v < r->value) 
        {
            r->left = deleteNode(r->left, v);
        }
        
        else if (v > r->value) 
        {
            r->right = deleteNode(r->right, v);
        }
        
        else 
        {
          
            if (r->left == NULL) 
            {
                TreeNode* temp = r->right;
                delete r;
                return temp;
            }
            
            else if (r->right == NULL) 
            {
                TreeNode* temp = r->left;
                delete r;
                return temp;
            }
          
            else 
            {
                TreeNode* temp = minValueNode(r->right);
                r->value = temp->value;
                r->right = deleteNode(r->right, temp->value);
            }
        }
        return r;
    }

};

int main() 
{
    int height = 0;
    BST obj;
    int option, val;

    do 
    {
        cout << "What operation do you want to perform? " << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Print/Traversal BST values" << endl;
        cout << "4. Height of Tree" << endl;
        cout << "5. Balance Tree" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        TreeNode* new_node = new TreeNode();

        switch (option) 
        {
        
        case 0:
            break;
        
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
            cin >> val;
            new_node->value = val;
            obj.root = obj.insertRecursive(obj.root, new_node);
            //obj.insertNode(new_node);
            cout << endl;
            break;

        case 2:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node != NULL) {
                obj.deleteNode(obj.root, val);
                cout << "Value Deleted" << endl;
            }
            else {
                cout << "Value NOT found" << endl;
            }
            break;
        
        case 3:
           // cout << "PRE-ORDER: ";
           // obj.printPreorder(obj.root);
           // cout << endl;
            cout << "IN-ORDER: ";
            obj.printInorder(obj.root);
            cout << endl;
           // cout << "POST-ORDER: ";
           // obj.printPostorder(obj.root);
           // cout << endl;
            break;

        case 4:
            cout << "TREE HEIGHT" << endl;
            cout << "Height : " << obj.height(obj.root) << endl;
            break;

        case 5:
            cout << "TREE BALANCE" << endl;
            if (obj.checkBalance(obj.root, &height))
            {
                cout << "**The tree is balanced**";
                cout << endl;
            }   
            else
            { 
                cout << "**The tree is not balanced**";
                cout << endl;
            }
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);
   
    system("pause");
    return 0;
}
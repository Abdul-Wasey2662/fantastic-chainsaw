#include<iostream>
using namespace std;
struct node
{
	int info;
	node* left;
	node* right;
};

class searchTree
{
public:
	searchTree();
	node* root;
	int num;
	void options();
	void inOrder(node *);
	void searchBTree(node*);

private:
	node* temp;
};

searchTree::searchTree()
{
	root = temp = NULL;
}

///////////////////////////////////////////////////

void searchTree::searchBTree(node* temp)
{
	if (root==NULL)
	{
		temp = new node;
		temp->info = num;
		temp->left = NULL;
		temp->right = NULL;
		root = temp;
		return;
	}

	if (temp->info==num)
	{
		cout << "Number is already present" << endl;
		return;
	}

	if (temp->info > num)
	{
		if (temp->left != NULL)
		{
			searchBTree(temp->left);
			return;
		}

		else
		{
			temp->left = new node;
			temp->left->info = num;
			temp->left->left = NULL;
			temp->left->right = NULL;
			return;
		}

	}

	if (temp->info < num)
	{
		if (temp->right != NULL)
		{
			searchBTree(temp->right);
			return;
		}
	
		else
		{
			temp->right = new node;
			temp->right->info = num;
			temp->right->left = NULL;
			temp->right->right = NULL;
			return;
		}

	}

}//end of function

/////////////////////////////////////////////////

void searchTree::options()
{
	cout << "*********SELECT OPTIONS*********" << endl;
	cout << "1. Insertion of node in BST" << endl;
	cout << "2. Print the BST" << endl;
	cout<<"3. Quitting the program"<<endl;
}

/////////////////////////////////////////////////

void searchTree::inOrder(node* temp)
{
	if (root==NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}

	if (temp->left!=NULL)
	{
		inOrder(temp->left);
		cout << temp->info<<" ";
	}

	if (temp->right!=NULL)
	{
		inOrder(temp->right);
		return ;
	}

}

/////////////////////////////////////////////////

int main()
{
	char ch;
	searchTree obj;

	while (4)
	{
		obj.options();
		ch = getchar();
		switch (ch)
		{
		case '1':

			cout<< "Ent	er number to add in tree:" <<endl;
			cin >> obj.num;
			obj.searchBTree(obj.root);
			break;

		case '2':

			obj.inOrder(obj.root);
			break;

		case'3':

			exit(0);
			break;

		default:
			exit(0);
			break;
		}//end ofswitch

	}//end of while




	system("pause");
	return 0;
}//end of main
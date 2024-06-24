/*
Name: Saanvi Agrawal
Class: Balasooriya Summer 2023
Assignment: Homework 4 Part 1
Description: Implementing different BST algorithms
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
public:
	class node
	{
	public:
		node* left;
		node* right;
		node* parent;
		int key;
		string data;
	};

	
public:
	node* root;
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
    void INSERT(int);
    void POSTORDER_TRAVERSAL(node*);
    void PREORDER_TRAVERSAL(node*);
	void INORDER_TRAVERSAL(node*);
    node* FIND_MIN(node*);
    void REMOVE_MIN();
    node* SUCCESSOR(node*);
    void DELETE(int);
	
    /*
        a) Insert
        b) Post Order Traversal
        c) Pre Order Traversal
        d) In Order Traversal
        e) Find Min
        f) Remove Min
        g) Successor (see slides for the algorithm)
        h) Delete
    */
};

//a) Insert
void BinarySearchTree::INSERT(int d)
{
	// This implements the algorithm in page 261 of the textbook
	node* z = new node();
	z->key = d;
	z->left = NULL;
	z->right = NULL;

	node* y = NULL;
	node* x = root;
	node* parent = NULL;

	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	parent = y;
	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
    //z->y = y
		
}

//b) Post Order Traversal
void BinarySearchTree::POSTORDER_TRAVERSAL(node* x)
{
    if (x != NULL)
    {
        if (x->left) POSTORDER_TRAVERSAL(x->left);
        if (x->right) POSTORDER_TRAVERSAL(x->right);
        	cout << " " << x->key << " ";
    }
}

//c) Pre Order Traversal
void BinarySearchTree::PREORDER_TRAVERSAL(node* x)
{
    if (x != NULL)
    {
        cout << " " << x->key << " ";
        if (x->left) PREORDER_TRAVERSAL(x->left);
        if (x->right) PREORDER_TRAVERSAL(x->right);
    }
}

//d) In Order Traversal
void BinarySearchTree::INORDER_TRAVERSAL(node* x)
{
	if (x != NULL)
	{
		if (x->left) INORDER_TRAVERSAL(x->left);
		cout << " " << x->key << " ";
		if (x->right) INORDER_TRAVERSAL(x->right);
	}
}

//e) Find Min
BinarySearchTree::node* BinarySearchTree::FIND_MIN(node* x)
{
    if(x == nullptr){
        return nullptr;
    }

    while (x->left != NULL)
    {
        x = x->left;
    }
    return x;
}

//f) Remove Min
void BinarySearchTree::REMOVE_MIN()
{
    if (root == nullptr)
        return;

    node* minNode = FIND_MIN(root);

    if (minNode == nullptr)
        return;

    //Case 1
    if(minNode == root){
        if(root->right != nullptr){
            root = root->right;
            root->parent = nullptr;
        }
        else if (root->left != nullptr){
            root = root->left;
            root->parent = nullptr;
        }
        else{
            root = nullptr;
        }
        delete minNode;
    }   
    //Case 2
    else
    {
        if(minNode->right != nullptr){
            minNode->parent->left = minNode->right;
            minNode->right->parent = minNode->parent;
        }
        else if (minNode->left != nullptr){
            minNode->parent->left = minNode->left;
            minNode->left->parent = minNode->parent;
        }
        else{
            minNode->parent->left = nullptr;
        }
        delete minNode;

    }

}

//g) Successor
BinarySearchTree::node* BinarySearchTree::SUCCESSOR(node* x)
{
    if (x == nullptr)
        return nullptr;

    if (x->right != NULL)
    {
        return FIND_MIN(x->right);
    }

    node* y = x->parent;
    while (y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

//h) Delete
void BinarySearchTree::DELETE(int key)
{
    node* x = root;
    while (x != nullptr && x->key != key)
    {
        if(key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    if(x == nullptr)
        return;
    
    if(x->left == nullptr){
        if(x == root){
            root = x->right;
        }
        else if(x == x->parent->left){
            x->parent->left = x->right;
        }
        else
        {
            x->parent->right = x->right;
        }
        
        if(x->right != nullptr)
        {
            x->right->parent = x->parent;
        }

        delete x;
    }    

    //Case 2
    else if(x->right == nullptr){
        if(x == root){
            root = x->left;
        }
        else if(x == x->parent->left){
            x->parent->left = x->left;
        }
        else{
            x->parent->right = x->left;
        }
    if(x->left != nullptr){
        x->left->parent = x->parent;
    }

    delete x;
    }

    //Case 3
    else
    {
        x->key = SUCCESSOR(x)->key;
        DELETE(SUCCESSOR(x)->key);
    }
}

//main
int main()
{
	BinarySearchTree bst;
	int choice, key;
	while (true)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Example " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insertion " << endl;
		cout << " 2. Pre-Order Traversal " << endl;
        cout << " 3. Post-Order Traversal " << endl;
        cout << " 4. In-Order Traversal " << endl;
        cout << " 5. Find Min " << endl;
        cout << " 6. Remove Min " << endl;
        cout << " 7. Successor " << endl;
        cout << " 8. Delete a Node " << endl;
        cout << " 9. Exit " << endl;
        cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << " Enter key (int value) to be inserted : ";
			cin >> key;
			bst.INSERT(key);
			break;
		case 2: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.PREORDER_TRAVERSAL(bst.root);
			break;
        case 3: cout << endl;
			cout << " Post-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.POSTORDER_TRAVERSAL(bst.root);
			break;
        case 4: cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.INORDER_TRAVERSAL(bst.root);
			break;
        case 5: cout << endl;
			cout << " Finding Minimum Value " << endl;
			cout << " -------------------" << endl;
            if (bst.FIND_MIN(bst.root) != NULL){
                cout << "The tree's minimum value is: " << bst.FIND_MIN(bst.root)->key << endl;
            }
            else{
                cout << "The tree's minimum value does not exist (empty)" << endl;
            }
			break;
        case 6: cout << endl;
			cout << " Removing Minimum Value " << endl;
			cout << " -------------------" << endl;
            if(bst.isEmpty()){
                cout << " Binary Tree is empty " << endl;
            }
            else{
                bst.REMOVE_MIN();
                cout << " Minimum Value is removed " << endl;
            }
			break;
        case 7: cout << endl;
			cout << " Finding Successor " << endl;
			cout << " -------------------" << endl;
            cout << " Enter key (int value) to find its successor: ";
            cin >> key;
            {
                BinarySearchTree::node* n = bst.root;
                while (n != NULL && n->key != key)
                {
                    if (key < n->key){
                        n = n->left;
                    }
                    else{
                        n = n->right;
                    }
                }
                if (bst.SUCCESSOR(n) != NULL){
                    cout << " Successor of " << key << " is: " << bst.SUCCESSOR(n)->key << endl;
                }
                else{
                    cout << " No successor has been found for " << key << endl;
                }
            }
			break;
        case 8: cout << endl;
			cout << " Deleting a Node " << endl;
			cout << " -------------------" << endl;
			cout << " Enter key (int value) to delete: ";
            cin >> key;
            if(bst.isEmpty()){
                cout << "Tree is empty" << endl;
            }
            else{
                bst.DELETE(key);
                cout << " Node with key " << key << " deleted." << endl;
            }
			break;
		case 9: 
            system("pause");
			return 0;
			break;
		default:
			cout << "Invalid choice";
		}
	}
}
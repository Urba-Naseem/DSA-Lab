#include <iostream>
using namespace std;

// Definition of the Tree Node
class Tree {
public:
    int data;
    Tree* left;
    Tree* right;

    Tree()
	{
	    data=0;
		left=NULL;
		right=NULL;	
	}	
	//parameterized constructor
	Tree(int value)
	{
	    data=value;
		left=NULL;
		right=NULL;	
	}	


// Function to insert a node in the BST
   Tree* Insert(Tree* root, int value) {
    if (root == NULL)
        return new Tree(value);
    
    if (value < root->data)
        root->left = Insert(root->left, value);
    else
        root->right = Insert(root->right, value);
    
    return root;
}

// In-order traversal
void InOrder(Tree* root) {
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

// Pre-order traversal
void PreOrder(Tree* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// Post-order traversal
void PostOrder(Tree* root) {
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
};
int main() 
{
	Tree t;
    Tree *root=NULL;
    root=t.Insert(root,12);
    root=t.Insert(root,7);
    root=t.Insert(root,9);
    root=t.Insert(root,10);
    root=t.Insert(root,22);
    root=t.Insert(root,24);
    root=t.Insert(root,30);
    root=t.Insert(root,18);
    root=t.Insert(root,3);
    root=t.Insert(root,14);
    root=t.Insert(root,20);
    cout << "In-order Traversal: ";
    t.InOrder(root);
    cout << "\nPre-order Traversal: ";
    t.PreOrder(root);
    cout << "\nPost-order Traversal: ";
    t.PostOrder(root);
    cout << endl;

    return 0;
}
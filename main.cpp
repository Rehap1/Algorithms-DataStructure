// C++ program for implementation of Insertion Sort
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <list>
using namespace std;

class TreeNode
{
public:
    int val_;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int val)
    {
        val_ = val;
    }
};

///Return True/False
bool search(TreeNode* root, int target)
{
    if(!root)
    {
        return false;
    }

    if(target > root->val_ )
    {
        return search(root->right, target);
    }
    else if(target < root->val_)
    {
        return search(root->left, target);
    }
    else
    {
        return true;
    }
}


///Return the rest of the tree
TreeNode* searchBST(TreeNode* root, int val)
{

    if (!root )
    {
        return root;
    }

    if (val > root->val_)
    {
        return searchBST(root->right, val);
    }
    else if (val < root->val_)
    {
        return searchBST(root->left, val);
    }
    else
    {
        return root;
    }
}

/// Insert a new node and return the root of the tree.
TreeNode* insert(TreeNode* root, int val)
{
    if (!root)
    {
        return new TreeNode(val);
    }

    if (val > root->val_)
    {
        root->right = insert(root->right, val);
    }
    else if (val < root->val_)
    {
        root->left = insert(root->left, val);
    }
    return root;
}

/// Return the minimum value node of the BST.
TreeNode* MinValNode(TreeNode* root)
{
    TreeNode* curr = root;
    while(curr && curr->left)
    {
        curr = curr->left;
    }
    return curr;
}

/// Remove a node and return the root of the tree.
TreeNode* removeNode(TreeNode* root, int val)
{
    if(!root)
    {
        return nullptr;
    }
    if(val > root->val_)
    {
        root->right = removeNode(root->right, val);
    }
    else if(val < root->val_)
    {
        root->left = removeNode(root->left, val);
    }
    else
    {
        if(!root->left)
        {
            return root->right;
        }
        else if (!root->right)
        {
            return root->left;
        }
        else
        {
            TreeNode* minNode = MinValNode(root->right);
            root->val_ = minNode->val_;
            root->right = removeNode(root->right, minNode->val_);
        }
    }

    return root;
}

///Traversal
void inorder(TreeNode* root)
{
    if(!root)
    {
        return;
    }
    inorder(root->left);
    cout<<root->val_<<" ";
    inorder(root->right);


}


// Driver method
int main()
{
    TreeNode* root = nullptr;

    vector<int> values =  {50, 30, 70, 20, 40, 60, 80};
    for(int v : values)
    {
        root = insert(root, v);
    }

    cout<<"Initial BST (inorder)"<<endl;
    inorder(root);
    cout<<endl;

    ///Test Search
    cout<< "Searching 40: "<<(search(root, 90)? "Found" : "Not Found" )<<endl;
    cout<< "Searching 20: "<<(search(root, 20)? "Found" : "Not Found" )<<endl;

    /// Test searchBST
    TreeNode* subTree = searchBST(root, 30);
    cout<<"Subtree rooted at 30 (inorder): ";
    inorder(subTree);
    cout<<endl;

    /// Test minimum value node
    cout<<"Minimum value in Tree: "<<MinValNode(root)->val_<<endl;

    cout << "Deleting 20 (node with one child)...\n";
    root = removeNode(root, 20);
    inorder(root);
    cout<<endl;



    cout << "Deleting 30 (node with one child)...\n";
    root = removeNode(root, 30);
    inorder(root);
    cout<<endl;


    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
using namespace std;
typedef enum {RED, BLACK} nodecolor ;
struct node
{
    node * left;
    node * right;
    node * parent;
    node * nil;
    node * root;
    int data;
    nodecolor color;
};
//void LeftRotate(node* &tree, node* x);
void RightRotate(node* &tree, node* y);
node* createNode(int data)
{
	node *newNode = new node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->nil = NULL;
	newNode->root = NULL;
	newNode->parent = NULL;
	newNode->color = BLACK;
	return newNode;
}
node *root=NULL;
int choice;
void treeDisplay(node * &tree)
{
	if(tree == NULL)
		return;
	treeDisplay(tree->left);
	cout<<tree->data<<"\t";
	treeDisplay(tree->right);
}
void InsertFixUp(node * &tree, node *z)
{
    //node *nil=tree->nil;
    node *y;
    while (z->parent!= NULL && z->parent->color==RED)
    {
        if(z->parent==z->parent->parent->left)
        {
            y=z->parent->parent->right;
            if(y!=NULL && y->color==RED)
            {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;
                z=z->parent->parent;
            }
            else if(z==z->parent->right)
            {
                z=z->parent;
                //LeftRotate(tree,z);
            }
            if(z->parent!=NULL)
            {
                z->parent->color=BLACK;
                if(z->parent->parent != NULL)
                    z->parent->parent->color=RED;
                RightRotate(tree,z->parent->parent);
            }
        }
        else
        {
             y=z->parent->parent->left;
            if(y!=NULL && y->color==RED)
            {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;
                z=z->parent->parent;
            }
            else if(z==z->parent->left)
            {
                z=z->parent;
                RightRotate(tree,z);
            }
            if(z->parent!=NULL)
            {
                z->parent->color=BLACK;
                if(z->parent->parent!=NULL)
                    z->parent->parent->color=RED;
                //LeftRotate(tree,z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}
void Insert(node * &tree, node *&z)
{
    //node* nil=tree->nil;
    //node* root=tree->root;
    if(tree == NULL)
    {
        tree = new node();
        tree = z;
        tree->root = z;
        return;
    }
    node *y;
    node *x;
    y=tree->nil;
    x=tree->root;
    while(x!=tree->nil)
    {
        y=x;
        if((z->data)<(x->data))
            x=x->left;
        else
            x=x->right;
    }
    z->parent = y;
    if(y==tree->nil)
        z=tree->root;
    else if((z->data)<(y->data))
        y->left = z;
    else
        y->right = z;
    z->left=tree->nil;
    z->right=tree->nil;
    z->color=RED;
    InsertFixUp(tree,z);
}
int getHeight(node * &tree)
{
    if(tree == NULL)
        return 0;
    return 1+max(getHeight(tree->left),getHeight(tree->right));
}

int main() {
	node *tree = NULL;
	for(int i = 5;i>0;i--)
	{
		if(tree == NULL)
        {
             node *newNode = new node();
             newNode = createNode(i);
             tree = newNode;
             tree->root = newNode;
        }
        else
        {
			 node *newNode = new node();
             newNode = createNode(i);
             Insert(tree,newNode);
        }
	}
	//treeDisplay(tree);
    cout<<getHeight(tree->root);
    return 0;
}

void RightRotate(node* &tree, node* y){
    node* helper = y->left;
    y->left = helper->right;
    if(helper->right != tree->nil)
        helper->right->parent = y;
        helper->parent = y->parent;
    if(y->parent == tree->nil)
        tree->root = helper;
    else
        y->parent->left = helper;

    helper->right = y;
    y->parent = helper;
}
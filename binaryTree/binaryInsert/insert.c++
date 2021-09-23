#include<iostream>

using namespace std;

typedef struct node{
    struct node *left;
    struct node *right;
    int data;
}node;

node* insert(node* root, int data);
node* root = NULL;
node* createNode(int data);

int main(){    
    root = insert(root, 4);
    root = insert(root, 4);
    root = insert(root, 6);
    return 0;
}

node* insert(node *root, int data){
    if(root == NULL) root =  createNode(data);
    else if(root->data < data) root->right = insert(root->right, data); 
    else root->left = insert(root->left, data); 
    return root;
}

node* createNode(int data){
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
#include<iostream>

using namespace std;

typedef struct node{
    struct node *left;
    struct node *right;
    int data;
}node;

int height(node *root);
node* insert(node* root, int data);
node* root = NULL;
node* createNode(int data);

int main(){    
    root = insert(root, 4);
    root = insert(root, 4);
    root = insert(root, 4);
    root = insert(root, 4);
    cout << height(root);
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

int height(node *root){
    /*
    - Height returns the number of edges 
    (edges or the pointer, not the nodes) from node to leaf
    - Calls the height through running it with recursive call
    and determining the larger branch with max func.
    - The +1 after max compare is the incrementor that is
    responsible for determining the height of the specific branch.
    - The return -1 sets the height of the NULL node or leaf to 0
    when added or counted by the +1 incrementor at max compare
    */
    if(root == NULL) return -1;
    return max(height(root->left), height(root->right)) + 1; 
}
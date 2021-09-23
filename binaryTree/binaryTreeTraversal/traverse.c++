#include<iostream>

using namespace std;

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
} node;

node* root = NULL;

int height(node *root);
node* insert(node* root, int data);
node* createNode(int data);
void depthFirst(node *root);

int main(){
    system("cls");
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 6);
    depthFirst(root);
}

node* createNode(int data){
    node *temp = new node();
    temp->data = data;
    temp->left = temp->left = NULL;
    return temp;
}

node* insert(node *root, int data){
    if(root == NULL) root = createNode(data);
    else if(root->data < data) root->right = insert(root->right, data);
    else root->left = insert(root->left, data);
    return root;
}

void depthFirst(node *root){
    if(root == NULL) return;
    //pucha mema lang tlaga to men gulat ako eto na itotopic bigla
    // Preorder : DLR
    // Inorder : DLDR >> gives you sorted list of
    // Postorder : LRD
    depthFirst(root->left);
    depthFirst(root->right);
    cout << root->data << endl;
}
#include<iostream>

using namespace std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;



node *newNode(int data){
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node *insert(node *root, int data){
    if(root == NULL) root = newNode(data);
    else if(root->data >= data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

node *search(node *root, int data){
    if(root == NULL) return NULL;
    if(root->data == data) return root;
    else if(root->data > data) search(root->left, data);
    else search(root->right, data);
}

int lowest(node *root){
    int save;
    while(root->left != NULL) root = root->left;
    save =  root->data;
    delete root;
    return save;
}

int highest(node *root){
    int save;
    while(root->right != NULL) root = root->right;
    save =  root->data;
    delete root;
    return save;
}

void deleteNode(node *root, int data){
    node *temp = search(root, data);
    if(temp->left == NULL && temp->right == NULL){
        delete temp;
        return;
    }else if(temp->left == NULL) temp->data = lowest(temp->right);
    else temp->data = highest(temp->left);
}

int main(){
    system("cls");
    node *root = NULL;
    root = insert(root, 15);
    insert(root, 20);
    insert(root, 17);
    insert(root, 25);
    insert(root, 10);
    insert(root, 5);
    insert(root, 8);
    deleteNode(root, 8);
    cout << root->left->left->right->left->data;
}

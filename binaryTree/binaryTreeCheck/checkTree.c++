#include<iostream>
#include<queue>
#include<limits.h>

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
void breadthFirst();
void depthFirst(node *root);
bool filter(node *root, int max, int min);
bool checkBST();
bool myCheckBST();
void inorderCheck(node *root);
queue<int>checklist;

int main(){
    system("cls");
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 6);
    cout << endl << myCheckBST();
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


bool filter(node *root, int max, int min){
    if(root == NULL) return true;
    if(root->data < max && root->data >= min 
    && filter(root->left, root->data, INT_MIN) 
    && filter(root->right, INT_MAX, root->data)) 
        return true;
    else return false;
}

bool checkBST(){
    return filter(root, INT_MAX, INT_MIN);
}

bool myCheckBST(){
    if(root == NULL) return true;
    inorderCheck(root);
    int save = checklist.front();
    checklist.pop();
    while(!checklist.empty()){
        if(checklist.front() < save) return false;
        save = checklist.front();
        checklist.pop();
    }
    return true;
}

void inorderCheck(node *root){
    if(root == NULL) return;
    inorderCheck(root->left);
    checklist.emplace(root->data);
    inorderCheck(root->right);
}


#include<iostream>

using namespace std;

typedef struct node{
    struct node *left;
    struct node *right;
    int data;
}node;

void insert(int data);
bool search(int data);
void largestNum();
void lowestNum();
node *head = NULL;

int main(){
    insert(5);
    insert(2);
    insert(9);
    insert(1);
    insert(4);
    if(search(0)) cout << "Found!" << endl;
    else cout << "Nawp" << endl;
    largestNum();
    lowestNum();
    return 0;
}

void insert(int data){
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    node *temp2 = head;
    do{
        if(temp->data <= temp2->data){
            if(temp2->left == NULL) temp2->left = temp;
            temp2 = temp2->left;
        }else{
            if(temp2->right == NULL) temp2->right = temp;
            temp2 = temp2->right;
        }
    }while(temp2 != temp);

    while(temp2 != NULL)
        if(temp->data <= temp2->data) temp2 = temp2->left;
        else temp2 = temp2->right;
    temp2 = temp;
}

bool search(int data){
    node *temp = head;
    while(temp != NULL)
        if(data < temp->data) temp = temp->left;
        else if(data > temp->data) temp = temp->right;
        else return true;
    return false;
}

void largestNum(){
    if(head == NULL) return;
    node *temp = head;
    while(temp->right != NULL) temp = temp->right;
    cout << temp->data << endl;  
}

void lowestNum(){
    if(head == NULL) return;
    node *temp = head;
    while(temp->left != NULL) temp = temp->left;
    cout << temp->data << endl;  
}
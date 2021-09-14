#include <iostream>
using namespace std;
typedef struct node{
    int num;
    struct node *next;
}node;

node *head = NULL;
void push(int x);
void deleteNode(int position);
void print();

int main(){
    int num, position;
    while(1){
        cout << "Input Num: ", cin >> num; 
        if(num == 0) break;
        push(num);
    }
    cout << "Input Position: ", cin >> position;
    deleteNode(position);
    print();
}

void push(int x){
    node *lastNode = new node();
    node *temp = head;
    lastNode->num = x;
    lastNode->next = NULL;
    if(head == NULL){
        head = lastNode;
        return;
    }
    while(temp->next != NULL)temp = temp->next;
    temp->next = lastNode;
}

void deleteNode(int position){
    node *temp = head;
    if(position == 1){
        head = head->next;
        free(temp);
        return;
    }
    for(int i = 1; i < position-1; i++) temp = temp->next;
    node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void print(){
    node *temp = head;
    while(temp != NULL){
        cout << temp->num << endl;
        temp = temp->next;
    }
}
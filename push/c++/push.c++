#include <iostream>
using namespace std;
typedef struct node{
    int num;
    struct node *next;
}node;

node *head = NULL;
void push(int x);
void print();

int main(){
    int num;
    while(1){
        cout << "Input Num: ", cin >> num; 
        if(num == 0) break;
        push(num);
    }
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

void print(){
    node *temp = head;
    while(temp != NULL){
        cout << temp->num << endl;
        temp = temp->next;
    }
}
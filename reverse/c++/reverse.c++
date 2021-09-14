#include <iostream>
using namespace std;
typedef struct node{
    int num;
    struct node *next;
}node;

node *head = NULL;
void push(int x);
void recursiveReversePrint(node *temp);
void recursivePrint(node *temp);
void print();
void reverse();

int main(){
    int num;
    while(1){
        cout << "Input Num: ", cin >> num;
        if(num == 0) break;
        push(num);
    }
    reverse();
    print();
    // // Recursive Listing
    // recursiveReversePrint(head); //This reverse does not change the pointer at all. Reverse print only.
    // recursivePrint(head);
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

void reverse(){
    node *next, *previous = NULL, *current = head;
    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

void recursivePrint(node *temp){
    if(temp == NULL) return;
    printf("%d\n", temp->num);
    recursivePrint(temp->next);
}

void recursiveReversePrint(node *temp){
    if(temp == NULL) return;
    recursiveReversePrint(temp->next);
    printf("%d\n", temp->num);
}

void print(){
    node *temp = head;
    while(temp != NULL){
        cout << temp->num << endl;
        temp = temp->next;
    }
}
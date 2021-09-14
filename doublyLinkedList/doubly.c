#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head = NULL;

void shift(int data);
void push(int data);
void replace(int position, int data);
void reverse();
void print(node *temp);
void printReverse();
int positionOf(int data);
node unshift();
node pop();

int main(){
    int num;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print(head);
}

void shift(int data){
    node *temp = (node *)malloc(sizeof(node *));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;
    if(head != NULL) head->prev = temp;
    head = temp;
}

void push(int data){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    if(head == NULL){
        temp->next = head;
        temp->prev = NULL;
        head = temp;
        return;
    }
    node *temp2 = head;
    while(temp2->next != NULL) temp2 = temp2->next;
    temp->prev = temp2;
    temp->next = NULL;
    temp2->next = temp;
}

void print(node *temp){
    if(temp == NULL) return;
    printf("%d\n", temp->data);
    print(temp->next);
}




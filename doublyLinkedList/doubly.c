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
void printReverse(node *temp);
int positionOf(int data);
int unshift();
int pop();

int main(){
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

void reverse(){
    node *temp = head, *next = NULL;
    while(1){
        next = temp->next;
        temp->next = temp->prev;
        temp->prev = next;
        if(next == NULL) break; 
        temp = next;
    }
    head = temp;
}

void replace(int position, int data){
    node *temp = head;
    for(int i = 1; temp!= NULL; i++)
        if(i == position){
            temp->data = data;
            return;
        } 
        else temp = temp->next;
    printf("\nInvalid Position!\n");
}

void print(node *temp){
    if(temp == NULL) return;
    printf("%d\n", temp->data);
    print(temp->next);
}

void printReverse(node *temp){
    if(temp == NULL) return;
    printReverse(temp->next);
    printf("%d\n", temp->data);
}

int positionOf(int data){
    node *temp = head;
    for(int i = 1; temp!= NULL; i++)
        if(temp->data == data) return i;
        else temp = temp->next;
    printf("\n%d is not in the list\n", data);
    return 0;
}

int unshift(){
    node *temp = head;
    int data = head->data;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return data;
}

int pop(){
    node *temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->prev = NULL;
    int data = temp->data;
    free(temp);
    return data;
}


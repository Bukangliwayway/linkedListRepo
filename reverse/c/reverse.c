#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    int num;
    struct node *next;
}node;

node *head = NULL;
void push(int x);
void reverse();
void print();

int main(){
    int num;
    while(1){
        printf("Input Num: ");
        scanf("%d", &num);
        if(num == 0) break;
        push(num);
    }
    reverse();
    print();
}

void push(int x){
    node *new = (node *)malloc(sizeof(node*));
    node *temp = head;
    new->num = x;
    new->next = NULL;
    if(head == NULL){
        head = new;
        return;
    }
    while(temp->next != NULL)temp = temp->next;
    temp->next = new;
}

void reverse(){
    node* next, *current = head, *prev = NULL;
    while(current != NULL){
        next = current->next; // Stores current next node to the next node
        current->next = prev; // Stores current next node as previous
        prev = current; // Moves previous to its next node or the current node itself
        current = next; // Moves current to its next node
    }    
    head = prev; // Set Prev as the Head
}

void print(){
    node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}

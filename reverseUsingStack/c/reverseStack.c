#include <stdlib.h>
#include <stdio.h>

// This has nothing to do with stack, as stack is only recognized on c++ 
// where it uses object. Where stack is an object as well  

typedef struct node{
    int data;
    struct node *next;
} node;

node *head = NULL;
void push(int x);
void reverse();
void print(node *temp);

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    reverse(head);
    print(head);
}

void push(int x){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

// Still not sure bout this. As setting head to null neglect the rule of freeing the next nodes.
// I could free it one by one but its a waste of time.
void reverse(){ 
    node *temp = head;
    head = NULL;     
    while(temp != NULL){
        push(temp->data);
        temp = temp->next;
    } 
}

void print(node *temp){
    if(temp == NULL) return;
    printf("%d ", temp->data);
    print(temp->next);
}
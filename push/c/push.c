#include <stdlib.h>
#include <stdio.h>
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
        printf("Input Num: ");
        scanf("%d", &num);
        if(num == 0) break;
        push(num);
    }
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

void print(){
    node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}
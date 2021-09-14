#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    int num;
    struct node *next;
}node;

node *head = NULL;
void push(int x);
void delete(int position);
void print();

int main(){
    int num, position;
    while(1){
        printf("Input Num: ");
        scanf("%d", &num);
        if(num == 0) break;
        push(num);
    }
    printf("Input Position: ");
    scanf("%d", &position);
    delete(position);
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

void delete(int position){
    node *temp = head;
    if(position == 1){
        head = head->next;
        free(temp); // Deletes the Head
        return;
    }
    for(int i = 1; i != position-1; i++)temp = temp->next;
    node*temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2); // Deletes the current node from heap 
}

void print(){
    node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}
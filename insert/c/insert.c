#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    int num;
    struct node *next;
}node;

node *head = NULL;
void insert(int x);
void print();
int main(){
    int num;
    do{
        printf("Input Num: ");
        scanf("%d", &num);
        insert(num);
    }while(num != 0);
    print();
}
void insert(int x){
    node *temp = (node *)malloc(sizeof(node *));
    temp->num = x;
    temp->next = head;
    head = temp;
}
void print(){
    node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}
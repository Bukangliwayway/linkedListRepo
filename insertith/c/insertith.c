#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    int num;
    struct node *next;
}node;

node *head = NULL;
void insertith(int x, int position);
void print();
int main(){
    int num, position;
    while(1){
        printf("Input Num: ");
        scanf("%d", &num);
        if(num == 0) break;
        printf("Input Position: ");
        scanf("%d", &position);
        insertith(num, position);
    }
    print();
}
void insertith(int x, int position){
    node *runNode = (node *)malloc(sizeof(node *));
    node *temp = head;
    runNode->num = x;
    // //Guard Clause
    // int count;
    // for(count = 1; temp != NULL; count++) temp = temp->next;
    // if(position > count){
    //     cout << "Invalid Position\n";
    //     return;
    // }
    // temp = head;

    if(position == 1){
        runNode->next = head;
        head = runNode;
        return;
    }
    for(int i = 1; i < position-1; i++)temp = temp->next;
    runNode->next = temp->next;
    temp->next = runNode;
}

void print(){
    node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}
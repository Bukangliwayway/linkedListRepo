#include<iostream>
#include<stack>

    //Stack has 4 functions:
    //.push(data type)  //Adds new data into list/stack
    //.pop()            //Clear the top of the stack
    //.empty()          //Check if the stack still has top
    //.top()            //Return the top of the stack

using namespace std;

typedef struct node{
    int data;
    struct node *next;
}node;

void push(int x);
void print();
void reverse();

node *head = NULL;

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    reverse();
    print();
}

void print(){
    node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void push(int x){
    node *temp = new node();
    temp->next = head;
    temp->data = x;
    head = temp;
}

void reverse(){
    stack<node *> list;             // Declaration of stack list
    node *temp = head;
    while(temp != NULL){
        list.push(temp);            // Add temp node pointer to the stack
        temp = temp->next;
    }
    temp = list.top();              // Set temp equal to the top or the 1st element of the stack 
    head = temp;
    list.pop();                     // Delete the first element of the stack
    while(!list.empty()){
        temp->next = list.top();    // Save the next element of stack to the next node 
        list.pop();                 // Then pop the saved stack element
        temp = temp->next;
    }
    temp->next = NULL; //Set the last node's next to NULL to indicate as the end for printing
}
#include<iostream>
using namespace std;

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
        cout << "Input Num: ", cin >> num;
        insert(num);
    }while(num != 0);
    print();
}

void insert(int x){
    node *temp = new node();
    temp->num = x;
    temp->next = head;
    head = temp;
}

void print(){
    node *temp = head;
    while(temp != NULL){
        cout << temp->num << endl;
        temp = temp->next;
    }
}


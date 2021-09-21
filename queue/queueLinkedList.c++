#include<iostream>

using namespace std;

typedef struct node{
    int num;
    struct node *next;
}node;

void printList();
void push(int num);
int pop();

node *front;
node *rear;

int main(){
    system("cls");
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    cout << pop() << endl;
    cout << pop() << endl;
    printList();
}

void printList(){
    node *temp = front;
    while(front != NULL){
        cout << front->num << " ";
        front = front->next;
    }
}

void push(int num){
    node *temp = new node();
    temp->num = num;
    temp->next = NULL;
    if(rear == NULL && front == NULL){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int pop(){
    if(rear == NULL) return 0;
    node *temp = front;
    int save = front->num;
    if(front == rear) front = rear = NULL;
    else front = front->next;
    free(temp);
    return save;
}



#include<iostream>
using namespace std;
typedef struct node{
    int num;
    struct node *next;
}node;
node *head = NULL;
void insertith(int x, int position);
void print();
int main(){
    insertith(1,1); // List: 1
    insertith(2,2); // List: 1,2
    insertith(3,3); // List: 1,2,3
    insertith(4,4); // List: 1,2,3,4
    insertith(5,6); // List: 1,2,5,3,4
    print();
}

void insertith(int x, int position){
    node *temp = head;

    // //Guard Clause
    // int count;
    // for(count = 1; temp != NULL; count++) temp = temp->next;
    // if(position > count){
    //     cout << "Invalid Position\n";
    //     return;
    // }
    // temp = head;

    //If adding element to position 1
    node *positionNode = new node();
    positionNode->num = x;
    if(position == 1){
        positionNode->next = head;
        head = positionNode;
        return;
    }

    //adding element except for position 1
    for(int i = 1; i < position-1 || temp == NULL; i++) temp = temp->next;
    positionNode->next = temp->next;
    temp->next = positionNode;
}

//printing element
void print(){
    node *temp = head;
    while(temp != NULL){
        cout << temp->num << endl;
        temp = temp->next;
    }
}



//With guard clause and a bug that gives you annoying 0 in the end
// #include<iostream>
// using namespace std;
// typedef struct node{
//     int num;
//     struct node *next;
// }node;
// void insertith(int x, int position);
// void print();
// void insert(int x);
// node *head = new node();
// int main(){
//     int num, position;
//     while(1){
//         cout << "Input Num: ", cin >> num;
//         cout << "ith: ", cin >> position;
//         if(num == 0) break;
//         if(position == 0) insert(num);
//         else insertith(num, position);
//     }
//     print();
// }
// void insert(int x){
//     node *temp = new node();
//     temp->num = x;
//     temp->next = head;
//     head = temp;
// }
// void insertith(int x, int position){
//     int positionCount, flag = 0;
//     if(head->num == 0){
//         cout << "No Head Value!" << endl;
//         return;
//     }
//     node* temp = head;
//     node* positionNode = NULL;
//     for(int i = 1; temp != NULL; i++){
//         if(position == i){
//             positionNode = new node();
//             positionNode->num = x;
//             positionNode->next = temp->next;
//             temp->next = positionNode;
//             flag = 1; 
//         }
//         temp = temp->next;
//         if(temp == NULL && flag == 0 && i != position){
//             printf("ith is invalid!\n");
//             break;
//         }
//     }
// }
// void print(){
//     node *temp = head;
//     while(temp != NULL){
//         cout << temp->num << endl;
//         temp = temp->next;
//     }
// }
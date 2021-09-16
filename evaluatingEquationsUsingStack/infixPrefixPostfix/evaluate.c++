#include<iostream>
#include<string>
#include<stack>
#include <ctype.h>

using namespace std;

bool precedence(char top, char compare);
string postfix(string str);

int main(){
    cout << postfix("A+B*C/D+E") << endl;
    return 0;
}

bool higherPrecedence(char top, char compare){
    if(top == '+' || top == '-')
        if(compare == '*' || compare == '/') return false;
    return true;
}

string postfix(string str){
    stack<char>list;
    string postStr = "";
    for(int i = 0; i < str.length(); i++)
        if(isalpha(str[i])) postStr += str[i];
        else if(str[i] == '*' || str[i] == '-' || str[i] == '+' || str[i] == '/'){
            if(!list.empty()) 
                while(higherPrecedence(list.top(), str[i])){ // Compare previous and current operator's precedence following PEMA 
                    postStr += list.top();
                    list.pop();
                    if(list.empty()) break; // Breaks the loop when list is empty, avoids null top on stack call
                }
            list.push(str[i]);
        }else return "Invalid Equation!";
    while(!list.empty()){
        postStr += list.top();
        list.pop();
    }
    return postStr;
}



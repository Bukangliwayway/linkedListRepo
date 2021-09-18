#include<iostream>
#include<string>
#include<stack>
#include <ctype.h>

using namespace std;

bool precedence(char top, char compare);
string postfix(string str);
string postFixParenthesis(string str);

int main(){
    cout << postFixParenthesis("A*(B+C)+(D*E)") << endl;
    return 0;
}

bool higherPrecedence(char top, char compare){
    if(top == '+' || top == '-') 
        if(compare == '*' || compare == '/') return false;
    return true;
}

string postfix(string str){
    stack<char>list;
    string postStr;
    for(int i = 0; i < str.length(); i++)
        if(isalpha(str[i])) postStr += str[i];
        else if(str[i] == '*' || str[i] == '-' || str[i] == '+' || str[i] == '/'){
            if(!list.empty()) 
                while(higherPrecedence(list.top(), str[i])){ // Compare previous and current operator's precedence following PEMA
                    //If true, gets the top element in stack and add it on string
                    postStr += list.top();
                    list.pop();
                    if(list.empty()) break; // Breaks the loop when list is empty: avoids null top on stack call at while condition
                }
            list.push(str[i]); //push the operator to the stack
        }else return "Invalid Equation!";
    //Transfer remaining elements from stack to string
    while(!list.empty()){
        postStr += list.top();
        list.pop();
    }
    return postStr;
}

string postFixParenthesis(string str){
    stack<char>list;
    string postStr;
    for(int i = 0; i < str.length(); i++)
        switch(str[i]){
            case '*': case '-': case '+': case '/': case '(':
                if(!list.empty() && str[i] != '(' && list.top() != '(')
                    while(higherPrecedence(list.top(), str[i])){
                        postStr += list.top();
                        list.pop();
                        if(list.empty()) break;
                    }
                list.push(str[i]);
                break;
            case ')':
                while(list.top() != '('){
                    postStr += list.top();
                    list.pop();
                }
                list.pop(); // pops the open parenthesis
                break;
            case 'A'...'Z': postStr += str[i]; break;
            default: return "Invalid Input!";
        }
     while(!list.empty()){
        postStr += list.top();
        list.pop();
    }
    return postStr;
}

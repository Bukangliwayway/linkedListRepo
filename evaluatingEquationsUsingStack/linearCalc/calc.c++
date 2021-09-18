#include<iostream>
#include<stack>
#include<string>
#include<string.h>
#include <ctype.h>
using namespace std;

bool check(string str);
bool toPair(char top, char compare);
string convertEq(string eq);
void saveEq(string eq, int *arr);
bool precedence(char top, char compare);
string postFix(string str);

int main(){
    int *arr;
    string eq = "10+(11+12)*13+14";
    saveEq(eq, arr);
    system("cls");
    cout << "Equation: \n\t" << eq << endl;
    cout << "Numbers: \n\t";
    for(int i = 0; arr[i]; i++) cout << arr[i] << " ";
    cout << "\nInfix:\n\t" << convertEq(eq) << endl;
    cout << "Postfix:\n\t" << postFix(convertEq(eq));
}


bool toPair(char top, char compare){
    switch(top){
        case '{': if(compare == '}') return true; else return false;
        case '[': if(compare == ']') return true; else return false;
        case '(': if(compare == ')') return true; else return false;
    }
    return false;
}

bool check(string str){
    stack<char> list;
    for(int i = 0; i < str.length(); i++)
        switch(str[i]){
            case '{': case '(': case '[': 
            case ']': case ')': case '}': 
            case 'A'...'Z': case '+': case '/': 
            case '*': case '-': break;
            default: return false;
        }
    for(int i = 0; i < str.length(); i++)
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') list.push(str[i]);       
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
            if(list.empty() || !toPair(list.top(), str[i])) return false;
            else list.pop();
    if(list.empty())return true;
    return false;
}

string convertEq(string eq){
    char variable = 'A';
    string str;
    stack<char>list; 
    for(int i = 0 ; i < eq.length(); i++){
        if(isdigit(eq[i])) list.push(eq[i]);
        else if(list.empty())str += eq[i];
        else{
            str += variable;
            str += eq[i];
            variable++;
            while(!list.empty())list.pop();
        }
    }
    if(!list.empty()) str += variable;
    return str;
}

void saveEq(string eq, int *arr){
    // int size = 0, count = 0;
    // for(int i = 0; i < eq.length(); i++)
    //     switch(eq[i]){
    //         case '*': case '/': case '-': case '+': size++;
    //     }
    int count = 0;
    string num;
    for(int i = 0; i < eq.length(); i++)
        if(isdigit(eq[i])) num += eq[i];
        else if(!num.empty()){
            arr[count] = strtol(num.c_str(), NULL, 10);
            count++;
            num.clear();
        }else continue;
    arr[count] = strtol(num.c_str(), NULL, 10); //Save the last instance
}

bool higherPrecedence(char top, char compare){
    if(top == '+' || top == '-') 
        if(compare == '*' || compare == '/') return false;
    return true;
}


string postFix(string str){
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

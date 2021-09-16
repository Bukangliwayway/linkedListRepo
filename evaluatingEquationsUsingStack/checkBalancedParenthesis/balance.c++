#include<iostream>
#include<stack>

// Checks whether the string equation has balanced parenthesis

using namespace std;

bool check(string str);
bool toPair(char top, char compare);

int main(){
    if(check("(){}")) cout << "Balanced";
    else cout << "It's Not";
}

bool check(string str){
    stack<char> list;
    for(int i = 0; i < str.length(); i++)
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') list.push(str[i]);       
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
            if(list.empty() || !toPair(list.top(), str[i])) return false;
            else list.pop();
    if(list.empty())return true;
    else return false;
}

bool toPair(char top, char compare){
    switch(top){
        case '{': if(compare == '}') return true; else return false;
        case '[': if(compare == ']') return true; else return false;
        case '(': if(compare == ')') return true; else return false;
    }
    return false;
}
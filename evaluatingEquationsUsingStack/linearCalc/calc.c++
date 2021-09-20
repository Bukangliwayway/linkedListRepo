#include<iostream>
#include<stack>
#include<string>
#include<string.h>
#include <ctype.h>
using namespace std;

bool checkParenthesis(string str);
bool toPair(char top, char compare);
string convertEq(string eq);
int* saveEq(string eq);
bool precedence(char top, char compare);
bool openParenthesis(char open);
char closingEquivalent(char open);
string postFix(string str);
int calculation(string eq, int *nums);
int solve(int a, int b, char op);

int main(){
    system("cls");
    string eq = "10+11+(12*13+14)";
    string post = "Invalid";
    int *arr, result = 0;
    string in = convertEq(eq); 
    if(!checkParenthesis(in)) cout << "Invalid Input!" << endl;
    else{
        post = postFix(in);
        arr = saveEq(eq);
        result = calculation(post,arr);
    }
    cout << "Equation: " << eq << endl; 
    cout << "Infix:    " << in << endl;
    cout << "Postfix:  " << post << endl;
    cout << "Result:   " << result;     
    return 0;
}

bool toPair(char top, char compare){
    switch(top){
        case '{': if(compare == '}') return true; else return false;
        case '[': if(compare == ']') return true; else return false;
        case '(': if(compare == ')') return true; else return false;
    }
    return false;
}

bool checkParenthesis(string str){
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

int* saveEq(string eq){
    int *arr;
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
    return arr;
}

bool higherPrecedence(char top, char compare){
    if(top == '+' || top == '-') 
        if(compare == '*' || compare == '/') return false;
    return true;
}

bool openParenthesis(char open){
    switch(open){case '(': case '{': case '[': return true;}
    return false;
}

char closingEquivalent(char open){
    switch(open){
        case ')': return '(';
        case '}': return '{';
        case ']': return '[';
    }
    return '0';
}

string postFix(string str){
    stack<char>list;
    string postStr;
    for(int i = 0; i < str.length(); i++)
        switch(str[i]){
            case '*': case '-': case '+': case '/':
                if(!list.empty() && !openParenthesis(list.top()))
                    while(higherPrecedence(list.top(), str[i])){
                        postStr += list.top();
                        list.pop();
                        if(list.empty() || openParenthesis(list.top())) break;
                    }
                list.push(str[i]);
                break;
            case ')': case '}': case ']':
                while(list.top() != closingEquivalent(str[i])){
                    postStr += list.top();
                    list.pop();
                }
                list.pop(); // pops the open parenthesis
                break;
            case '(': case '{': case '[': list.push(str[i]); break;
            case 'A'...'Z': postStr += str[i]; break;
            default: return "Invalid Input!";
        }
    while(!list.empty()){
        postStr += list.top();
        list.pop();
    }
    return postStr;
}

int calculation(string eq, int *nums){
    int a,b, result;    
    stack<int>list;
    for(int i = 0 ; i < eq.length(); i++)
        if(eq[i] == '*' || eq[i] == '/' || eq[i] == '+' || eq[i] == '-'){
            b = list.top();
            list.pop();
            a = list.top();
            list.pop();
            try {result = solve(a,b,eq[i]);}
            catch(runtime_error& e){cout << "Exception Occudred: " << endl << e.what();}
            list.push(result);
        }else{
            list.push(nums[eq[i]-'A']);            
        }
    return result;
}
int solve(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if(b == 0) throw runtime_error("Math error: Attempted to divide by Zero\n");
            return a / b;
    }
    return 0;
}
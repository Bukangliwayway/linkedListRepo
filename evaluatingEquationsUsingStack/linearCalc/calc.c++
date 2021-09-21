#include<iostream>
#include<stack>
#include<string>
#include<string.h>
#include <ctype.h>
using namespace std;

typedef struct node{
    float num;
    struct node *next;
}node;

bool checkParenthesis(string str);
bool toPair(char top, char compare);
string convertEq(string eq);
void push(float x);
void printNums();
void saveEq(string eq);
bool precedence(char top, char compare);
bool openParenthesis(char open);
char closingEquivalent(char open);
string postFix(string str);
float traverse(int position);
float calculation(string eq);
float solve(float a, float b, char op);

node *head = NULL;

int main(){
    system("cls");
    float result = 0;
    string eq = "6/2(2+1)";
    string post = "Invalid";
    string in = convertEq(eq); 

    if(!checkParenthesis(in)) cout << "Invalid Input!" << endl;
    else{
        saveEq(eq);
        post = postFix(in);
        result = calculation(post);
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
        else if(list.empty()) str += eq[i];    
        else{
            str += variable;
            if(eq[i] == '(' && isdigit(eq[i-1])) str += '*';
            str += eq[i];
            variable++;
            if(eq[i] == ')' && (eq[i+1] == '(' || isdigit(eq[i+1]))) str += '*';
            while(!list.empty())list.pop();
        }
    }
    if(!list.empty()) str += variable;
    return str;
}

void push(float x){
    node *temp, *traverse = head;
    temp = new node();
    temp->next = NULL;
    temp->num = x;
    if(head == NULL){
        temp->next = head;
        head = temp;
        return;
    }
    while(traverse->next != NULL) traverse = traverse->next;
    traverse->next = temp;
    traverse = temp;
}

void printNums(){
    node *temp = head;
    while(temp != NULL){
        cout << temp->num << ' ';
        temp = temp->next;
    }
}

 void saveEq(string eq){
    float save;
    string num;
    for(int i = 0; i < eq.length(); i++)
        if(isdigit(eq[i])) num += eq[i];
        else if(!num.empty()){
            save = strtof(num.c_str(), NULL);
            push(save);
            num.clear();
        }
    save = strtof(num.c_str(), NULL); //Save the last instance
    push(save);
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

float traverse(int position){
    node *temp = head;
    for(int i = 0; i < position; i++){
        temp = temp->next;
    }
    // cout << temp->num << ":" << position << endl;
    return temp->num;
}

float calculation(string eq){
    float a,b, result;    
    stack<float>list;
    for(int i = 0 ; i < eq.length(); i++)
        if(eq[i] == '*' || eq[i] == '/' || eq[i] == '+' || eq[i] == '-'){
            b = list.top();
            list.pop();
            a = list.top();
            list.pop();
            try {result = solve(a,b,eq[i]);}
            catch(runtime_error& e){
                cout << "Exception Occured: " << endl << e.what();
                return 0;
            }
            list.push(result);
        }else list.push(traverse(eq[i]-'A'));            
    return result;
}

float solve(float a, float b, char op){
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
#include <iostream>
#include <cmath>
using namespace std;

#define MAX 10

class Stack{
    int arr[MAX];
    int top=-1;

    public:
    void push(char val){
        if(top >= MAX-1){
            cout<<"Stack Full"<<endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Empty"<<endl;
            return;
        }
        arr[top]=0;
        top--;
    }
    
    int getTop(){
        return arr[top];
    }
    
    bool Isempty(){
        return (top==-1);
    }
};

int precedence(char c){
    if(c=='^')  return 3;
    else if(c=='*' || c=='/')  return 2;
    else if(c=='+' || c=='-')  return 1;
    else return -1;
}

string infixToPrefix(string infix){
    for(int i=0; i<(infix.size()/2); i++)   swap(infix[i], infix[infix.size()-i-1]);
    for(int i=0; i<(infix.size()); i++) {
        if(infix[i]=='(')  infix[i] = ')';
        else if(infix[i]==')')    infix[i] = '(';
    }

    Stack s;
    string postfix = "";

    for(int i=0; i<infix.length(); i++) {
        char c = infix[i];
        if((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix += c;
        }
        else if(c == '(')  s.push('(');
        else if(c==')') {
            while(!s.Isempty() && s.getTop() != '(') {
                postfix += s.getTop();
                s.pop();
            }
            if(s.getTop()=='(')    s.pop();
        }
        else {
            while(!s.Isempty() && precedence(c) <= precedence(s.getTop())) {
                postfix += s.getTop();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.Isempty()) {
        postfix += s.getTop();
        s.pop();
    }
    string prefix = postfix;
    for(int i=0; i<(prefix.size()/2); i++)   swap(prefix[i], prefix[prefix.size()-i-1]);
    return prefix;
}

int evaluatePrefix(string prefix) {
    Stack s;
    for(int i=prefix.length()-1; i>=0; i--) {
        char c = prefix[i];
        if(isdigit(c))  s.push(c-'0');
        else {
            int op1 = s.getTop(); s.pop();
            int op2 = s.getTop(); s.pop();
            int result = 0;

            switch (c) {
                case '+': result = op1+op2; break;
                case '-': result = op1-op2; break;
                case '*': result = op1*op2; break;
                case '/': result = op1/op2; break;
                case '^': result = pow(op1,op2); break;
                default: break;
            }
            s.push(result);
        }
    }
    return s.getTop();
}


int main(){
    string infix1 = "A+(B*C-D)/E";
    string prefix = infixToPrefix(infix1);
    cout<<prefix<<endl;
    string infix2 = "1+(2*3-4)";
    cout<<infix2<<" = "<<evaluatePrefix(infixToPrefix(infix2));
}

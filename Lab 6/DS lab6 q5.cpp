#include <iostream>
#include <cmath>
using namespace std;

#define MAX 10

class Stack {
    int arr[MAX];
    int top=-1;

    public:
    void push(char val){
        if(top >= MAX-1){
            cout << "Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        arr[top]=0;
        top--;
    }
    int getTop(){
        return arr[top];
    }
    bool empty(){
        return (top==-1);
    }
};


int precedence(char c) {
    if(c=='^')  return 3;
    else if(c=='*' || c=='/')  return 2;
    else if(c=='+' || c=='-')  return 1;
    else return -1;
}

string infixToPostfix(string infix){
    Stack s;
    string postfix = "";

    for(int i=0; i<infix.length(); i++) {
        char c = infix[i];
        if((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            postfix += c;
        }
        else if(c == '(')  s.push('(');
        else if(c==')') {
            while(!s.empty() && s.getTop() != '(') {
                postfix += s.getTop();
                s.pop();
            }
            if(s.getTop()=='(')    s.pop();
        }
        else {
            while(!s.empty() && precedence(c) <= precedence(s.getTop())) {
                postfix += s.getTop();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()) {
        postfix += s.getTop();
        s.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) {
    Stack s;
    for(int i=0; i<postfix.size(); i++) {
        char c = postfix[i];
        if(isdigit(c))  s.push(c-'0');
        else {
            int op2 = s.getTop(); s.pop();
            int op1 = s.getTop(); s.pop();
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

int main() {
    string infix1 = "A+(B*C-D)/E";
    string postfix = infixToPostfix(infix1);
    cout<<postfix<<endl;
    string infix2 = "2+(1*3-4)";
    cout << infix2 << " = " << evaluatePostfix(infixToPostfix(infix2));
}

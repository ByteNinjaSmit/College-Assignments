#include<iostream>
#include<cstring>
using namespace std;

// Initialising Stack
const int stack_size = 100;
char stack[stack_size];
int top = -1;

// Stack PUSH function
void push(char s){
    stack[++top] = s;
}

// Stack POP Function
char pop(){
    return stack[top--];
}

// Function to get precedence of operators
int precedence(char c){
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c=='^')
        return 3;
    else
        return 0;
}

// POSTFIX Function passing value by checking parameters
void postfix(char s[], int n){
    int i = 0;
    while (i < n){
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')){
            cout << s[i];
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i]=='^'){
            while (top > -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(s[i])){
                cout << pop();
            }
            push(s[i]);
        }
        else if (s[i] == '('){
            push(s[i]);
        }
        else if (s[i] == ')'){
            while (stack[top] != '('){
                cout << pop();
            }
            pop(); 
        }
        i++;
    }
    while (top > -1){
        cout << pop();
    }
}

int main(){
    char* s = new char; 
    cout<<"Enter A String: ";
    cin.getline(s, 100); 
    int n = strlen(s);
    postfix(s,n);
    return 0;
}
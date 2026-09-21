//Infix to Prefix Conversion Logic Example

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    for (char ch : infix) {
        if (isalnum(ch)) postfix += ch;
        else if (ch == '(') s.push(ch);
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') { postfix += s.top(); s.pop(); }
            s.pop();
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) { postfix += s.top(); s.pop(); }
            s.push(ch);
        }
    }
    while (!s.empty()) { postfix += s.top(); s.pop(); }
    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix = "A+B*C";
    cout << "Infix: " << infix << "\n";
    cout << "Prefix: " << infixToPrefix(infix) << "\n";
    return 0;
}
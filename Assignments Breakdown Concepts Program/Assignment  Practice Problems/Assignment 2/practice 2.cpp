//Operator Precedence Function

#include <iostream>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main() {
    cout << "Precedence of '^': " << precedence('^') << "\n";
    cout << "Precedence of '*': " << precedence('*') << "\n";
    cout << "Precedence of '+': " << precedence('+') << "\n";
    return 0;
}
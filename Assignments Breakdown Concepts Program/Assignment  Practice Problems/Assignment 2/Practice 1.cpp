//Stack Operation using linked list(Push,Pop,Peek,IsEmpty)

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *next;
};

class Stack {
    Node *top;
public:
    Stack() {
        top = NULL;
    }

    void push(char x) {
        Node *temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
        cout << x << " pushed to stack.\n";
    }

    char pop() {
        if (top == NULL) {
            cout << "Stack Underflow!\n";
            return '\0';
        }
        Node *temp = top;
        char x = temp->data;
        top = top->next;
        delete temp;
        return x;
    }

    char peek() {
        if (top == NULL) return '\0';
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack s;
    s.push('A');
    s.push('B');
    cout << "Top element is: " << s.peek() << "\n";
    s.pop();
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << "\n";
    return 0;
}
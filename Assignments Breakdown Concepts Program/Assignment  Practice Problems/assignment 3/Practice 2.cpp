//Modulo operator for circular wrapping

#include <iostream>
using namespace std;

int main() {
    int SIZE = 5;
    int rear = 3;

    // Wrapping around using modulo
    rear = (rear + 1) % SIZE; 
    cout << "Next index: " << rear << endl; // Output: 4

    rear = (rear + 1) % SIZE; 
    cout << "Wrapped around index: " << rear << endl; // Output: 0 (loops back)
    return 0;
}
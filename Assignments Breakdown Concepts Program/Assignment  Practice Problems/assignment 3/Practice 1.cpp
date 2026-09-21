//classes,Objects and Constructors

#include <iostream>
using namespace std;

class Box {
private:
    int length;
public:
    // Constructor
    Box() {
        length = 10;
        cout << "Constructor called! Length initialized to " << length << endl;
    }
};

int main() {
    Box b; // Automatically calls the constructor
    return 0;
}
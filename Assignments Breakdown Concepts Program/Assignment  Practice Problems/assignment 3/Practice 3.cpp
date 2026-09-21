//Menu driven control flow(Do while and switch case)


#include <iostream>
using namespace std;

int main() {
    int choice;
    do {
        cout << "\n1. Say Hello\n2. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Hello user!" << endl;
                break;
            case 2:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 2);
    
    return 0;
}

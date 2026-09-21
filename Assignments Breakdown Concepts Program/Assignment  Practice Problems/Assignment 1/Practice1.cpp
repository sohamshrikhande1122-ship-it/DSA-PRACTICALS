//Dynnamic Memory Allocation Example

#include <iostream>
using namespace std;

int main() {
    int n = 3;
    
    // Allocate dynamic memory for 'n' integers
    int *arr = new int[n];

    // Assign values
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }

    // Print values
    cout << "Dynamic Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Free the allocated memory to prevent memory leaks
    delete[] arr;
    return 0;
}

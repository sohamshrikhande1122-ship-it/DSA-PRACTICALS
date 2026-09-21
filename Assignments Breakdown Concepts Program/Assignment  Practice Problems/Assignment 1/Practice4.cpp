//Linear Search

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 23, 45, 70, 11};
    int n = 5;
    int key = 45;
    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            pos = i;
            break;
        }
    }

    if (pos != -1)
        cout << "Element found at index: " << pos;
    else
        cout << "Element not found";

    return 0;
}
//Bibnary Serch example

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // Must be sorted!
    int n = 5;
    int key = 40;
    
    int low = 0, high = n - 1;
    int pos = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            pos = mid;
            break;
        }
        if (arr[mid] < key) {
            low = mid + 1; // Search right half
        } else {
            high = mid - 1; // Search left half
        }
    }

    if (pos != -1)
        cout << "Element found at index: " << pos;
    else
        cout << "Element not found";

    return 0;
}
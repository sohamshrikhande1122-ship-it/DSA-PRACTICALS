//Selection sort example

#include <iostream>
using namespace std;

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = 5;

    // Selection Sort Logic
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap found minimum with the first element
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }

    cout << "Sorted Array (Selection Sort): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
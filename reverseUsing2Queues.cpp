#include<iostream>
#include<queue>
using namespace std;

void reverseElements(int* arr, int size) {
    queue<int> q1, q2;

    // Step 1: Put array elements into q1
    for (int i = 0; i < size; i++) {
        q1.push(arr[i]);
    }

    // Step 2: Move elements into q2 to reverse
    while (!q1.empty()) {
        int temp = q1.front();
        q1.pop();
        
        q2.push(temp);

        // Rotate q2 to keep new element at front
        for (int i = 0; i < q2.size() - 1; i++) {
            q2.push(q2.front());
            q2.pop();
        }
    }

    // Step 3: Copy back to array
    int index = 0;
    while (!q2.empty()) {
        arr[index++] = q2.front();
        q2.pop();
    }

   
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    reverseElements(arr, size);

    cout << "\nReversed Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

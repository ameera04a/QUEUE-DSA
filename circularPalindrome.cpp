#include<iostream>
#include<queue>
#include<string>
using namespace std;

// Check if queue forms a palindrome
bool isCircularPalindrome(queue<int> q) {
    int n = q.size();
    if (n == 0) return true;

    for (int i = 0; i < n; i++) {
        queue<int> temp = q; // Copy queue to temp
        string normal = "", reversed = "";

        while (!temp.empty()) {
            int val = temp.front();
            normal += to_string(val);
            reversed = to_string(val) + reversed; // Add to front to build reverse
            temp.pop();
        }

        if (normal == reversed) {
            return true;
        }

        // Rotate: move front to back
        int first = q.front();
        q.pop();
        q.push(first);
    }

    return false;
}

int main() {
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(2);

    if (isCircularPalindrome(q)) {
        cout << "Queue is a Circular Palindrome!\n";
    } else {
        cout << "Queue is NOT a Circular Palindrome.\n";
    }

    return 0;
}

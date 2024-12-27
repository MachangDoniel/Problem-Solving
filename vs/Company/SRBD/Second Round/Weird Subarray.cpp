#include <iostream>
#include <vector>
using namespace std;

// Function to compute the GCD of two numbers
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Input the length of the array
    int n;
    cin >> n;
    
    // Input the elements of the array
    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Array to store the result for each index
    vector<int> result(n, 1);

    // Two pointer approach
    int left = 0; // The left pointer
    long long curr_gcd = A[0]; // Current GCD of the window

    for (int right = 0; right < n; ++right) {
        if (right > 0) {
            curr_gcd = gcd(curr_gcd, A[right]);
        }

        // Shrink the window from the left if GCD becomes 1
        while (curr_gcd == 1 && left < right) {
            left++;
            curr_gcd = A[left];
            for (int i = left + 1; i <= right; i++) {
                curr_gcd = gcd(curr_gcd, A[i]);
            }
        }

        // The length of the current valid subarray
        result[right] = right - left + 1;
    }

    // Output the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

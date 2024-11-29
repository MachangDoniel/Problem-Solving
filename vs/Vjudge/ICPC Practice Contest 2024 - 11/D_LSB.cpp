#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // First, print the number of lines in the program
    cout << n << endl;

    // Create the shifts
    for (int i = 1; i <= n - 1; i++) {
        cout << "B" << i << " = B" << i - 1 << " << 2" << endl;
    }

    // Combine the shifts using OR
    for (int i = 2; i <= n; i++) {
        cout << "B" << i << " = B" << i << " | B" << i - 1 << endl;
    }

    // Finally, XOR the last result to isolate the LSB
    cout << "B" << n + 1 << " = B" << n << " ^ (B" << n << " << 1)" << endl;

    return 0;
}

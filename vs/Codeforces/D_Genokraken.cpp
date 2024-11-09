#include <iostream>
#include <vector>
using namespace std;

// Function to perform the path query
int query(int a, int b) {
    cout << "? " << a + 1 << " " << b + 1 << endl; // +1 to convert from 0-indexed to 1-indexed
    cout.flush();
    int result;
    cin >> result;
    return result;
}

void solve() {
    int n;
    cin >> n; // Number of nodes

    vector<int> parent(n, -1);
    parent[1] = 0; // We know that node 1's parent is node 0

    // We will use this vector to find children of node 0
    vector<int> children_of_zero;

    // Step 1: Check relationships of nodes with node 1
    for (int i = 2; i < n; i++) {
        int response = query(1, i); // Check relationship between node 1 and other nodes
        if (response == 1) {
            // This means node i is in the path with node 1, hence its parent is likely node 1
            parent[i] = 1;
        } else {
            // If the response is 0, it means node i is a child of node 0
            parent[i] = 0;
            children_of_zero.push_back(i);
        }
    }

    // Step 2: For the direct children of 0, determine their parent relationships
    for (int child : children_of_zero) {
        for (int i = 2; i < n; i++) {
            if (parent[i] == -1 && i != child) { // Check only unassigned nodes
                if (query(child, i) == 0) {
                    // If there is no path to 0, then child is the parent of i
                    parent[i] = child;
                }
            }
        }
    }

    // Output the result for this test case
    cout << "! ";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " ";
    }
    cout << endl;
    cout.flush();
}

int main() {
    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}

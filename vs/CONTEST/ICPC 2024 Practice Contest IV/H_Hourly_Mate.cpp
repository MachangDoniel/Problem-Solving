#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n, m;
        cin >> n >> m; // Read n and m
        
        vector<int> a(n), b(n); // Types and expiration times
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // Type of each Mate
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i]; // Expiration time of each Mate
        }

        // Count the number of drinks by type
        unordered_map<int, vector<int>> drinksByType;
        for (int i = 0; i < n; ++i) {
            drinksByType[a[i]].push_back(b[i]);
        }

        // Sort the expiration times for each type
        for (auto& entry : drinksByType) {
            sort(entry.second.begin(), entry.second.end());
        }

        // Start consuming drinks
        int k = 0;
        while (true) {
            // The current drink count per type for k
            unordered_map<int, int> count;
            int consumedDrinks = 0;

            for (auto& entry : drinksByType) {
                int type = entry.first;
                auto& expirationTimes = entry.second;

                // Find the first available drink of this type that can be consumed
                for (int expTime : expirationTimes) {
                    if (expTime >= consumedDrinks) {
                        count[type]++;
                        consumedDrinks++;
                        break; // Consume one drink of this type
                    }
                }
            }

            // Check if all types have at least one drink consumed
            bool allTypesSatisfied = true;
            for (int i = 1; i <= m; ++i) {
                if (count[i] == 0) {
                    allTypesSatisfied = false;
                    break;
                }
            }

            if (!allTypesSatisfied) {
                break; // Stop if not all types have been consumed
            }

            k++; // Increment k since we managed to consume one of each type
        }

        cout << k << endl; // Output the result for this test case
    }

    return 0;
}

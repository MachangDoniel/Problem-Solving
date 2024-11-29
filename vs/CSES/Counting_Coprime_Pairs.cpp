#include <iostream>
#include <vector>
using namespace std;

// Function to count coprime pairs
long long countCoprimePairs(int n, const vector<int>& nums) {
    const int MAX_VAL = 1e6;
    vector<int> freq(MAX_VAL + 1, 0);

    // Step 1: Count the frequency of each number
    for (int num : nums) {
        freq[num]++;
    }

    // Step 2: Calculate the total number of pairs
    long long totalPairs = (long long)n * (n - 1) / 2;

    // Step 3: Sieve approach to find pairs with gcd > 1
    long long gcdPairs = 0;
    for (int g = 2; g <= MAX_VAL; g++) {
        long long countMultiples = 0;
        for (int multiple = g; multiple <= MAX_VAL; multiple += g) {
            countMultiples += freq[multiple];
        }
        gcdPairs += countMultiples * (countMultiples - 1) / 2;
    }

    // Step 4: Subtract gcd > 1 pairs from total pairs
    return totalPairs - gcdPairs;
}

int main() {
    // Input
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Output the result
    cout << countCoprimePairs(n, nums) << endl;

    return 0;
}

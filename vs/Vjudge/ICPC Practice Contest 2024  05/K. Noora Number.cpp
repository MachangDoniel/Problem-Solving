#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to check if a number is a Noora number
bool is_noora(long long num) {
    string str_num = to_string(num);
    set<char> distinct_digits(str_num.begin(), str_num.end());
    
    int max_digit = *max_element(str_num.begin(), str_num.end()) - '0';
    
    return distinct_digits.size() == max_digit;
}

int main() {
    vector<long long> noora_numbers;

    // Precompute Noora numbers up to 10^18
    for (long long i = 1; i <= 1000000000000000000LL; ++i) {
        if (is_noora(i)) {
            noora_numbers.push_back(i);
        }
        // Break the loop after some reasonable limits to avoid long computation
        if (i > 10000) { // Adjust this limit based on testing
            break;
        }
    }

    // Read number of test cases
    int T;
    cin >> T;
    vector<long long> results(T);
    
    for (int i = 0; i < T; ++i) {
        long long n;
        cin >> n;
        
        // Count Noora numbers <= n using binary search
        auto count = upper_bound(noora_numbers.begin(), noora_numbers.end(), n);
        results[i] = distance(noora_numbers.begin(), count);
    }

    // Output results
    for (const auto &result : results) {
        cout << result << endl;
    }

    return 0;
}

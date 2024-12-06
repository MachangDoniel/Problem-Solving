#include<bits/stdc++.h>
using namespace std;

class MobiusFunction {
private:
    int N;                        // Maximum range
    vector<int> mobius;           // Array to store Möbius values

public:
    // Constructor: Initialize the Möbius function up to N
    MobiusFunction(int N) : N(N), mobius(N + 1, 1) {
        computeMobius();
    }

    // Compute Möbius function for all integers up to N
    void computeMobius() {
        vector<bool> isPrime(N + 1, true); // Sieve array
        for (int i = 2; i <= N; ++i) {
            if (isPrime[i]) {
                // If i is prime, update multiples of i
                for (int j = i; j <= N; j += i) {
                    mobius[j] *= -1; // Flip sign for each prime factor
                    isPrime[j] = false;
                }
                // If i^2 divides j, set Möbius to 0
                for (int j = i * i; j <= N; j += i * i) {
                    mobius[j] = 0;
                }
            }
        }
    }

    // Get Möbius value of n
    int getMobius(int n) const {
        if (n < 1 || n > N) throw out_of_range("n is out of range");
        return mobius[n];
    }

    // Print Möbius values up to N
    void printMobius() const {
        for (int i = 1; i <= N; ++i) {
            cout << "μ(" << i << ") = " << mobius[i] << endl;
        }
    }
};

int main() {
    int N;
    cout << "Enter the maximum value of N: ";
    cin >> N;

    MobiusFunction mobius(N);

    mobius.printMobius();

    int query;
    cout << "Enter a number to get its Möbius value (0 to quit): ";
    while (cin >> query && query != 0) {
        try {
            cout << "μ(" << query << ") = " << mobius.getMobius(query) << endl;
        } catch (const out_of_range &e) {
            cout << e.what() << endl;
        }
        cout << "Enter another number (0 to quit): ";
    }

    return 0;
}

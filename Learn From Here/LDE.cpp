#include<bits/stdc++.h>
using namespace std;



class LinearDiophantineSolver {
private:
    int a, b, c;    // Coefficients of the equation
    int x0, y0;     // Particular solution

    // Helper function: Extended Euclidean Algorithm
    int extendedGCD(int a, int b, int &x, int &y) {
        if (b == 0) {
            x = 1; y = 0;
            return a;
        }
        int x1, y1;
        int gcd = extendedGCD(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return gcd;
    }

public:
    // Constructor
    LinearDiophantineSolver(int a, int b, int c) : a(a), b(b), c(c), x0(0), y0(0) {}

    // Function to check if a solution exists and find one if it does
    bool findSolution() {
        int gcd = extendedGCD(a, b, x0, y0);
        if (c % gcd != 0) {
            return false; // No solution exists
        }

        // Scale the solution by c / gcd
        x0 *= c / gcd;
        y0 *= c / gcd;
        return true;
    }

    // Get particular solution
    tuple<int, int> getParticularSolution() const {
        return {x0, y0};
    }

    // Generate general solutions
    tuple<int, int> generateSolution(int k) const {
        return {x0 + k * (b / __gcd(a, b)), y0 - k * (a / __gcd(a, b))};
    }

    // Display the general solution
    void displayGeneralSolution(int range = 5) const {
        cout << "General solutions (x, y):\n";
        for (int k = -range; k <= range; ++k) {
            auto [x, y] = generateSolution(k);
            cout << "(x, y) = (" << x << ", " << y << ")\n";
        }
    }
};

int main() {
    int a, b, c;
    cout << "Enter coefficients a, b, c for the equation ax + by = c: ";
    cin >> a >> b >> c;

    LinearDiophantineSolver solver(a, b, c);

    if (solver.findSolution()) {
        auto [x, y] = solver.getParticularSolution();
        cout << "Particular solution: x = " << x << ", y = " << y << "\n";
        solver.displayGeneralSolution();
    } else {
        cout << "No solution exists for the given equation.\n";
    }

    return 0;
}

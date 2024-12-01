#include <iostream>  
#include <vector>  
using namespace std;  

const int MOD = 1000000007;  

int main() {  
    int T;  
    cin >> T;  
    vector<string> results;  

    for (int case_number = 1; case_number <= T; ++case_number) {  
        int M, N, K;  
        cin >> M >> N >> K;  

        // Compute the total number of cells  
        int total_cells = (M + 1) * (N + 1);  
        
        // If K is 0 or total_cells is 0 (0 colorings possible)  
        if (K == 0 || total_cells == 0) {  
            results.push_back("Case " + to_string(case_number) + ": 0");  
            continue;  
        }  

        // Single cell case check  
        if (total_cells == 1) {  
            results.push_back("Case " + to_string(case_number) + ": " + to_string(K));  
            continue;  
        }  

        // For K > 1 case  
        // For even and odd cells:  
        int num_even_cells = (total_cells + 1) / 2; // Count of cells with even index   
        int num_odd_cells = total_cells / 2;        // Count of cells with odd index   

        // Calculate ways based on colorings available  
        long long ways = 0;  

        // K >= 2  
        if (K >= 2) {  
            // We can choose any of K colors for even and odd indexed cells independently  
            ways = (K * K) % MOD;  
        } else { // K == 1  
            // Only one color, hence can't color them independently if separated  
            ways = (num_even_cells > 0 && num_odd_cells > 0) ? 0 : 1; // If total_cells is odd, treat separately from even (1 way single cell)  
        }  

        // Format results  
        results.push_back("Case " + to_string(case_number) + ": " + to_string(ways));  
    }  

    // Output all results  
    for (const auto& result : results) {  
        cout << result << endl;  
    }  

    return 0;  
}
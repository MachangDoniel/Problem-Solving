#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll minCostToReachN(ll N, ll A, ll B, ll X, ll Y, ll Z) {
    vector<pair<ll, ll>> operations = {{1, X}, {A, Y}, {B, Z}};
    
    // Sort operations by efficiency (cost per increment) in ascending order
    sort(operations.begin(), operations.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        return (double)a.second / a.first < (double)b.second / b.first;
    });

    ll cost = 0;
    while (N > 0) {
        for (auto& op : operations) {
            ll increment = op.first;
            ll operationCost = op.second;
            
            // Use as many of the current operation as possible
            if (increment <= N) {
                ll count = N / increment;
                N -= count * increment;
                cost += count * operationCost;
            }
        }
    }

    return cost;
}

int main() {
    int T;
    cin >> T;
    vector<tuple<ll, ll, ll, ll, ll, ll>> testCases(T);

    for (int i = 0; i < T; ++i) {
        ll N, A, B, X, Y, Z;
        cin >> N >> A >> B >> X >> Y >> Z;

        cout << minCostToReachN(N, A, B, X, Y, Z) << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

#define Good_Luck ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll MOD = 1000000007;

ll countValidTeams(ll n, vector<ll>& v) {
    ll validTeamCount = 0;
    for (ll k = 1; k < (1 << n); k++) { 
        ll sumEnergy = 0;
        ll sizeOfTeam = 0;

        for (ll j = 0; j < n; j++) {
            if (k & (1 << j)) {  
                sumEnergy += v[j];  
                sizeOfTeam++;       
            }
        }
        if (sizeOfTeam > 0 && sumEnergy % sizeOfTeam == 0) {
            validTeamCount = (validTeamCount + 1) % MOD; 
        }
    }

    return validTeamCount;
}

void solve(ll t) {
    ll n; 
    cin >> n; 
    vector<ll> v(n); 
    for (ll i = 0; i < n; i++) {
        cin >> v[i]; 
    }
    ll result = countValidTeams(n, v);
    cout << "Case " << t << ": " << result << endl; 
}

int main() {
    Good_Luck;
    ll T; 
    cin >> T; 
    for (ll t = 1; t <= T; t++) {
        solve(t);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define Good_Luck ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

void solve() {
    int n; 
    cin >> n;
    vector<int> a(n);
    map<int, pair<int, int>> mp;
    
    // Populate the map with first and last occurrences
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end()) {
            mp[a[i]] = {i, i};
        }
        mp[a[i]].second = i;
    }

    multiset<pair<pair<int, int>, int>> ms;
    for (auto &it : mp) {
        ms.insert({{it.second.first, it.second.second}, it.first});
    }

    int last = -1;
    for (auto it = ms.begin(); it != ms.end();) {
        if (it->first.second < last) 
            it = ms.erase(it);  // Remove intervals fully covered by previous
        else 
            last = max(last, it->first.second), ++it;
    }

    // Start processing from the first interval
    auto it = ms.begin();
    int st = it->first.first, en = it->first.second;
    map<int, int> freq;

    // Count frequencies for elements outside the range [st, en]
    for (int i = 0; i < st; i++) {
        freq[a[i]]++;
    }
    for (int i = en + 1; i < n; i++) {
        freq[a[i]]++;
    }

    ms.erase(ms.begin()); // Remove the first interval from the multiset
    int ans = ms.size(); // Initial answer is the size of the remaining intervals

    // Now handle the remaining intervals one by one
    while (!ms.empty()) {
        it = ms.begin();
        int new_st = it->first.first, new_en = it->first.second;

        // Update frequencies as the window shifts
        for (int i = st; i < new_st; i++) {
            freq[a[i]]++;
        }
        for (int i = en + 1; i <= new_en; i++) {
            freq[a[i]]--;
            if (freq[a[i]] == 0) {
                freq.erase(a[i]);
            }
        }

        // Update the answer with the minimum unique elements count
        ans = min(ans, (int)freq.size());
        st = new_st;
        en = new_en;
        ms.erase(ms.begin()); // Move to the next interval
    }

    cout << ans + 1 << endl; // Include the first interval
}

int32_t main() {
    Good_Luck;
    int T=1; 
    cin >> T;
    for(int t=1; t<=T; t++) {
        solve();
    }
    return 0;
}

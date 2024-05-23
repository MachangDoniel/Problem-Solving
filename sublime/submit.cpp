#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

// Comparator for suffixes
struct Suffix {
    int index;
    int rank[2];
};

bool cmp(const Suffix &a, const Suffix &b) {
    if (a.rank[0] == b.rank[0])
        return a.rank[1] < b.rank[1];
    return a.rank[0] < b.rank[0];
}

vector<int> buildSuffixArray(const string &text) {
    int n = text.size();
    vector<Suffix> suffixes(n);

    for (int i = 0; i < n; ++i) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = text[i] - 'a';
        suffixes[i].rank[1] = ((i + 1) < n) ? (text[i + 1] - 'a') : -1;
    }

    sort(suffixes.begin(), suffixes.end(), cmp);

    vector<int> ind(n);

    for (int k = 4; k < 2 * n; k *= 2) {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        for (int i = 1; i < n; ++i) {
            if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            } else {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; ++i) {
            int nextIndex = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (nextIndex < n) ? suffixes[ind[nextIndex]].rank[0] : -1;
        }

        sort(suffixes.begin(), suffixes.end(), cmp);
    }

    vector<int> suffixArr(n);
    for (int i = 0; i < n; ++i) {
        suffixArr[i] = suffixes[i].index;
    }

    return suffixArr;
}

vector<int> buildLCPArray(const string &text, const vector<int> &suffixArr) {
    int n = text.size();
    vector<int> lcp(n, 0);
    vector<int> invSuffix(n, 0);

    for (int i = 0; i < n; ++i) {
        invSuffix[suffixArr[i]] = i;
    }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (invSuffix[i] == n - 1) {
            k = 0;
            continue;
        }

        int j = suffixArr[invSuffix[i] + 1];
        while (i + k < n && j + k < n && text[i + k] == text[j + k]) {
            k++;
        }

        lcp[invSuffix[i]] = k;

        if (k > 0) {
            k--;
        }
    }

    return lcp;
}

int countUniqueSubstrings(const string &text) {
    int n = text.size();

    vector<int> suffixArr = buildSuffixArray(text);
    vector<int> lcp = buildLCPArray(text, suffixArr);

    int totalSubstrings = n * (n + 1) / 2;

    int repeatedSubstrings = accumulate(lcp.begin(), lcp.end(), 0);

    return totalSubstrings - repeatedSubstrings;
}

int main() {
    string text; 
    cin>>text;
    cout << countUniqueSubstrings(text) << endl;
    return 0;
}

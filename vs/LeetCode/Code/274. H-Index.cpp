class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.rbegin(),citations.rend());
        // reverse(citations.begin(),citations.end());
        int h=0;
        for(int i=0;i<n;i++){
            h=max(h,min(i+1,citations[i]));
        }
        return h;
    }
};
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int candidate = 0;  
            int count = 0;  
    
            for (int num : nums) {  
                if (count == 0) {  
                    candidate = num;  
                    count = 1;  
                } 
                else if (num == candidate) {  
                    count++;  
                } 
                else {  
                    count--;  
                }  
            }  
    
            return candidate;  
        }
    };






// optimize space
/*
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")   
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insnS2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-Pointer-checks")
#pragma GCC optimize("Ofast")
int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");

    for (string s; getline(cin, s); out << '\n') {
        int ans = 0;
        int c = 0;

        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            bool _neg = false;

            if (s[_i] == '-') {
                ++_i;
                _neg = true;
            }

            int v = s[_i++] & 15;

            while ((s[_i] & 15) < 10)
                v = v * 10 + (s[_i++] & 15);

            if (_neg)
                v = -v;

            if (c == 0)
                ans = v;
            
            ans == v ? ++c : --c;
        }
        out << ans;
    }
    out.flush();
    exit(0);
    return 0;
}();
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int freq=0,ans=0;
        for(int i=0;i<n;i++){
            if(freq==0) ans=nums[i];
            if(ans==nums[i]) freq++;
            else freq--;
        }
        return ans;
    }
};
*/
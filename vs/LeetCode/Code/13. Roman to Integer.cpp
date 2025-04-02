class Solution {
    public:
        int romanToInt(string s) {
            int ans=0,prev=0;
            for(int i=0;i<s.size();i++){
                int present=0;
                if(s[i]=='I') present=1;
                else if(s[i]=='V') present=5;
                else if(s[i]=='X') present=10;
                else if(s[i]=='L') present=50;
                else if(s[i]=='C') present=100;
                else if(s[i]=='D') present=500;
                else if(s[i]=='M') present=1000;
                if(prev>=present) ans+=present;
                else ans+=(present-2*prev);
                prev=present;
            }
            return ans;
        }
    };
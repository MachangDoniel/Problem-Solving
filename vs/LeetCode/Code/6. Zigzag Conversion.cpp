class Solution {
public:
    string convert(string s, int numRows) {
        string ss[numRows];
        bool inc=true;
        int count=0;
        for(int i=0;i<s.size();i++){
            ss[count]+=s[i];
            inc?count++:count--;
            if(count==numRows) count--;
            else if(count==-1) count++;
            if(count==numRows-1) inc=false;
            else if(count==0) inc=true;
        }
        string ans;
        for(int i=0;i<numRows;i++){
            ans+=ss[i];
        }
        return ans;
    }
};
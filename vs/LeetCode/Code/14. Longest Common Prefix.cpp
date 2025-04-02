class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string prefix=strs[0];
            for(int i=1;i<strs.size();i++){
                string temp;
                for(int j=0;j<min(prefix.size(),strs[i].size());j++){
                    if(strs[i][j]==prefix[j]) temp+=prefix[j];
                    else break;
                }
                prefix=temp;
            }
            return prefix;
        }
    };

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++){
            for(int j=0;j<min(prefix.size(),strs[i].size());j++){
                if(strs[i][j]!=prefix[j]){
                    prefix.erase(prefix.begin()+j,prefix.end());
                    break;
                }
            }
            if(min(prefix.size(),strs[i].size())<prefix.size()) prefix.erase(prefix.begin()+min(prefix.size(),strs[i].size()),prefix.end());
        }
        return prefix;
    }
};
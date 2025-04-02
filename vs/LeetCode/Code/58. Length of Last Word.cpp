class Solution {
    public:
        int lengthOfLastWord(string s) {
            stringstream line(s);
            string str;
            while(line>>str){
    
            }
            return str.size();
        }
    };

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                count=0;
            }
            else count++,ans=count;
        }
        return ans;
    }
};
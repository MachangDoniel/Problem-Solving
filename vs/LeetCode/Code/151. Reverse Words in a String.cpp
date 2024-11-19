class Solution {
public:
    string reverseWords(string s) {
        while(*s.begin()==' '){
            s.erase(s.begin());
        }
        reverse(s.begin(),s.end());
        while(*s.begin()==' '){
            s.erase(s.begin());
        }
        int index=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(s[index-1]!=' ') s[index]=s[i],index++;
            }
            else s[index]=s[i],index++;
        }
        s.erase(s.begin()+index,s.end());
        index=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') reverse(s.begin()+index,s.begin()+i),index=i+1;
        }
        reverse(s.begin()+index,s.end());
        // cout<<s<<endl;
        return s;
    }
};
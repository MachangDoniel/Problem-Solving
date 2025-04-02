class Solution {
    public:
        bool isPalindrome(string s) {
            int l=0,r=s.size()-1;
            while(l<r){
                char right,left;
                while(l<r && !(('a'<=s[r] && s[r]<='z') || ('A'<=s[r] && s[r]<='Z') || ('0'<=s[r] && s[r]<='9'))){
                    r--;
                }
                ('A'<=s[r] && s[r]<='Z')?right=s[r]-'A'+'a':right=s[r];
                while(l<r && !(('a'<=s[l] && s[l]<='z') || ('A'<=s[l] && s[l]<='Z')  || ('0'<=s[l] && s[l]<='9'))){
                    l++;
                }
                ('A'<=s[l] && s[l]<='Z')?left=s[l]-'A'+'a':left=s[l];
                // cout<<left<<" "<<right<<endl;
                if(left!=right) return false;
                l++,r--;
            }
            return true;
        }
    };

    class Solution {
        public:
            bool isPalindrome(string s) {
                string str;
                for(int i=0;i<s.size();i++){
                    if(('a'<=s[i] && s[i]<='z') || ('0'<=s[i] && s[i]<='9')) str+=s[i];
                    else if('A'<=s[i] && s[i]<='Z') str+=s[i]-'A'+'a';
                }
                for(int i=0,j=str.size()-1;i<j;i++,j--){
                    if(str[i]!=str[j]) return false; 
                }
                return true;
            }
        };
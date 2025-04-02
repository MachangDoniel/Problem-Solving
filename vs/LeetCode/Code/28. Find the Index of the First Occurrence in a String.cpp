class Solution {
    public:
        int strStr(string haystack, string needle) {
            for(int i=0;i<int(1+haystack.size()-needle.size());i++){
                // cout<<i<<" "<<haystack.size()<<"-"<<needle.size()<<"+"<<1<<" "<<int(haystack.size()-needle.size()+1)<<endl;
                bool flag=true;
                for(int j=0;j<needle.size();j++){
                    if(haystack[i+j]!=needle[j]){
                        flag=false;
                        break;
                    }
                }
                if(flag) return i;
            }
            return -1;
        }
    };
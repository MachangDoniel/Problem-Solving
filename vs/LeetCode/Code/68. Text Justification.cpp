class Solution {
    public:
    
        string format(vector<string>&temp,int wordlen,int maxWidth){
            int noOfWord=temp.size();
            int space=maxWidth-wordlen;
            int segment=noOfWord-1;
            string res=temp[0];
            for(int i=1;i<temp.size();i++){
                int tempspace=space/segment+(space%segment!=0);
                space-=tempspace;
                segment--;
                while(tempspace--){
                    res+=" ";
                }
                res+=temp[i];
            }
            while(res.size()<maxWidth){
                res+=" ";
            }
            return res;
        }
    
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            int n=words.size();
            vector<string> result;
            vector<string> temp;
            int wordlen=0;
            for(int i=0;i<n;i++){
                if(temp.empty() || temp.size()+wordlen+words[i].size()<=maxWidth){
                    temp.push_back(words[i]);
                    wordlen+=words[i].size();
                }
                else{
                    result.push_back(format(temp,wordlen,maxWidth));
                    temp.clear();
                    temp.push_back(words[i]);
                    wordlen=words[i].size();
                }
            }
            string last=temp[0];
            for(int i=1;i<temp.size();i++){
                last+=" "+temp[i];
            }
            while(last.size()<maxWidth){
                last+=" ";
            }
            result.push_back(last);
            return result;
        }
    };
    
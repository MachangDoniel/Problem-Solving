class Solution {
public:
int n;
    bool valid(int i){
        return i>=0 && i<n;
    }
    int candy(vector<int>& ratings) {
        n=ratings.size();
        vector<pair<int,int>>vp(ratings.size());
        for(int i=0;i<n;i++){
            vp[i]={ratings[i],i};
        }
        sort(vp.begin(),vp.end());
        vector<int>candys(ratings.size(),1);
        int sum=0;
        for(int i=0;i<n;i++){
            int x=vp[i].first;
            int index=vp[i].second;
            if(valid(index-1) && valid(index+1)){
                if(ratings[index]>ratings[index-1] && ratings[index]>ratings[index+1]) candys[index]=max(candys[index-1],candys[index+1])+1;
                else if(ratings[index]>ratings[index-1]) candys[index]=candys[index-1]+1;
                else if(ratings[index]>ratings[index+1]) candys[index]=candys[index+1]+1;
            }
            else if(valid(index-1)){
                if(ratings[index]>ratings[index-1]) candys[index]=candys[index-1]+1;
            }
            else if(valid(index+1)){
                if(ratings[index]>ratings[index+1]) candys[index]=candys[index+1]+1;
            }
            sum+=candys[index];
            // cout<<index<<" got candys "<<candys[index]<<endl;
        }
        for(int i=0;i<n;i++){
            cout<<candys[i]<<" ";
        }
        return sum;
    }
};
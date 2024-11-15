class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sum=0,mn=INT_MAX,pos=-1;
        for(int i=0;i<n;i++){
            sum+=gas[i]-cost[i];
            if(mn>sum){
                mn=sum;
                pos=i+1;
            }
        }
        return (sum>=0)?pos%n:-1;
    }
};
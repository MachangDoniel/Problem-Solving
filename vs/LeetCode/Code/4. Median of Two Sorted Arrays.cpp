class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int high=n+1,low=-1;
        while(high>low+1){
            int mid=(high+low)/2;
            int idx1=mid;
            int idx2=(m+n+1)/2-idx1;
            cout<<idx1<<" "<<idx2<<endl;
            int lmx1=(idx1==0)?INT_MIN:nums1[idx1-1];
            int lmx2=(idx2==0)?INT_MIN:nums2[idx2-1];
            int rmn1=(idx1==n)?INT_MAX:nums1[idx1];
            int rmn2=(idx2==m)?INT_MAX:nums2[idx2];
            if(lmx1<=rmn2 && lmx2<=rmn1){
                if((n+m)%2) return double(max(lmx1,lmx2));
                else return double(max(lmx1,lmx2)+min(rmn1,rmn2))/2;
            }
            else if(lmx1>rmn2) high=mid;
            else low=mid;
        }
        return 0.0;
    }
};
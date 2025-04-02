#include<bits/stdc++.h>
using namespace std;

#define int long long
// MyTask

struct SimpleHash {
    long long len, base, mod;
    vector<long long> P, H, R;
    SimpleHash() {}
    SimpleHash(string str, long long b, long long m) {
        base = b, mod = m, len = str.size();
        P.resize(len + 4, 1), H.resize(len + 3, 0), R.resize(len + 3, 0);
        for (long long i = 1; i <= len + 3; i++)
            P[i] = (P[i - 1] * base) % mod;
        for (long long i = 1; i <= len; i++)
            H[i] = (H[i - 1] * base + str[i - 1]+1007) % mod;
        for (long long i = len; i >= 1; i--)
            R[i] = (R[i + 1] * base + str[i - 1]+1007) % mod;
    }
    inline long long range_hash(long long l, long long r) {
        long long hashval = (H[r + 1] - (P[r - l + 1] * H[l] % mod))%mod;
        return (hashval < 0 ? hashval + mod : hashval);
    }
    inline long long reverse_hash(long long l, long long r) {
        long long hashval = R[l + 1] - (P[r - l + 1] * R[r + 2] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }
};
struct DoubleHash {
    SimpleHash sh1, sh2;
    DoubleHash() {}
    DoubleHash(string str) {
        sh1 = SimpleHash(str, 1949313259, 2091573227);
        sh2 = SimpleHash(str, 1997293877, 2117566807);
    }
    long long concate(DoubleHash& B, long long l1 , long long r1 , long long l2 , long long r2) {
        long long len1 = r1 - l1+1 , len2 = r2 - l2+1;
        long long x1 = sh1.range_hash(l1, r1) ,
        x2 = B.sh1.range_hash(l2, r2);
        x1 = (x1 * B.sh1.P[len2]) % 2091573227;
        long long newx1 = (x1 + x2) % 2091573227;
        x1 = sh2.range_hash(l1, r1);
        x2 = B.sh2.range_hash(l2, r2);
        x1 = (x1 * B.sh2.P[len2]) % 2117566807;
        long long newx2 = (x1 + x2) % 2117566807;
        return (newx1 << 32) ^ newx2;
    }
    inline long long range_hash(long long l, long long r) {
        return (sh1.range_hash(l, r) << 32) ^ sh2.range_hash(l, r);
    }
    inline long long reverse_hash(long long l, long long r) {
        return (sh1.reverse_hash(l, r) << 32) ^ sh2.reverse_hash(l, r);
    }
};


// Find the no of specific substring that a string has

 // common mistake
int countSubstringWrong(string s,string ss){
    int count=0;
    int n=s.size();
    int m=ss.size();
    for(int i=0,index=0;i<s.size();i++){
        if(s[index]==s[i]) index++;
        else{
            index=0;
            if(s[index]==s[i]) index++;
        }
        if(index>=m) index=0,count++;
    }
    // cout<<count<<endl;
    return count;
}
// may face time limit
int countSubstringRight(string s,string ss){
    int count=0,n=s.size(),m=ss.size();
    for(int i=0,index=0;i<s.size();i++){
        if(s[index]==s[i]) index++;
        else{
            i-=index;
            index=0;
        }
        if(index>=m) index=0,count++;
    }
    // cout<<count<<endl;
    return count;
}
// using double hash user defined data type
int countSubstringDH(string s,string ss){
    int count=0,n=s.size(),m=ss.size();
    DoubleHash dh(s);
    DoubleHash dhss(ss);
    int val=dhss.range_hash(0,m-1);
    for(int i=0;i<s.size();i++){
        if(i+m-1<n && dh.range_hash(i,i+m-1)==val){
            count++;
            i++;
        }
    }
    // cout<<count<<endl;
    return count;
}

 
main()
{
    string s,ss; cin>>s>>ss;
    // cout<<"Using General Approach: ";
    // cout<<countSubstringWrong(s,ss)<<endl;  // common mistake
    // cout<<"Using General Approach: ";
    // cout<<countSubstringRight(s,ss)<<endl;  // may face time limit
    cout<<"Using DoubleHash Approach: ";
    cout<<countSubstringDH(s,ss)<<endl;     // using double hash user defined data type
}
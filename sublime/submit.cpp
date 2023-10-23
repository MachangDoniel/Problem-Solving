#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set= tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;  //ordered_set
template <typename T>
using multi_ordered_set= tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;  //multiple_ordered_set
 
int main()
{
    int num;
    multiset<int> s;
    s.insert(4);
    s.insert(3);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(6);

    cout<<"The set is: ";
    for(auto it:s) cout<<it<<" ";
        cout<<endl;
    for(int i=1;i<s.size();i++){
        cout<<"Lower_Bound of "<<i<<": "<<*s.lower_bound(i)<<endl;
        cout<<"Upper_Bound of "<<i<<": "<<*s.upper_bound(i)<<endl;
    }
    return 0;
}

# Contest Programming


## Tools Required
1. [Code::Blocks](https://www.codeblocks.org/downloads/) or
2. [Visual Studio](https://code.visualstudio.com/) or
3. [Sublime Text](https://www.sublimetext.com/3)

## Coding platforms
1. https://codeforces.com/
2. https://leetcode.com/
3. https://www.topcoder.com/
4. https://www.hackerrank.com/
5. https://atcoder.jp/
6. https://www.codechef.com/
7. https://cses.fi/
8. https://www.interviewbit.com/
9. https://lightoj.com/
10. https://onlinejudge.org/

## Points to be noted
### Header 
All in one
```bash
#include<bits/stdc++.h>
using namespace std;
```
### PBDS(Policy Based Data Structure)
[Read about pbds](https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/),
To set up pbds, add the following code to your template.

```bash
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set= tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;  //ordered_set
template <typename T>
using multi_ordered_set= tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;  //multiple_ordered_set
```
### Difference between set and ordered_set
Additional Operations is ordered_set:
1. order_of_key (k) : Number of items strictly smaller than k .
2. find_by_order(k) : K-th element in a set (counting from zero).

A little change in ordered_set template(using less_equal insteat of less) will allow duplicates in ordered_set, lets name it multi_ordered_set.
### Difference between multiset and multi_ordered_set
lower_bound: is a built-in function in C++ STL which returns an iterator pointing to the element in the container which is equivalent to k.

upper_bound: is a built-in function in C++ STL which returns an iterator pointing to the immediate next element which is just greater than k.
#### Set
```bash
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
    set<int> s;
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
```
Output:
```bash
The set is: 1 2 3 4 6 
Lower_Bound of 1: 1
Upper_Bound of 1: 2
Lower_Bound of 2: 2
Upper_Bound of 2: 3
Lower_Bound of 3: 3
Upper_Bound of 3: 4
Lower_Bound of 4: 4
Upper_Bound of 4: 6
```
#### Multiset
```bash
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
```
Output
```bash
The set is: 1 2 3 3 4 6 
Lower_Bound of 1: 1
Upper_Bound of 1: 2
Lower_Bound of 2: 2
Upper_Bound of 2: 3
Lower_Bound of 3: 3
Upper_Bound of 3: 4
Lower_Bound of 4: 4
Upper_Bound of 4: 6
Lower_Bound of 5: 6
Upper_Bound of 5: 6
```

#### Ordered_set
```bash
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
    ordered_set<int> s;
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
```
Output
```bash
The set is: 1 2 3 4 6 
Lower_Bound of 1: 1
Upper_Bound of 1: 2
Lower_Bound of 2: 2
Upper_Bound of 2: 3
Lower_Bound of 3: 3
Upper_Bound of 3: 4
Lower_Bound of 4: 4
Upper_Bound of 4: 6

```

#### Multi_Ordered_Set
```bash
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
    multi_ordered_set<int> s;
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
```
Output
```bash
The set is: 1 2 3 3 4 6 
Lower_Bound of 1: 2
Upper_Bound of 1: 1
Lower_Bound of 2: 3
Upper_Bound of 2: 2
Lower_Bound of 3: 4
Upper_Bound of 3: 3
Lower_Bound of 4: 6
Upper_Bound of 4: 4
Lower_Bound of 5: 6
Upper_Bound of 5: 6
```

Note: Here, Upper_Bound & Lower_Bound works in ordered_set as usual, But in multiple_ordered_set, it works different.

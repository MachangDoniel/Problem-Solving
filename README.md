
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

## Learn From Here
1. Learn algorithms from [CP Algorithms](https://cp-algorithms.com/index.html)

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


## Dynamic Programming
Learn [Longest Increasing Subsequences, Box Stacking](https://www.youtube.com/watch?v=aPQY__2H3tE)

### Combination Calculation Code
See [Code](Learn%20From%20Here/combination%20by%20dp.cpp)

### Overview
This code provides three methods to compute combinations \(nCr\) modulo \(10^9 + 7\) using three distinct techniques:
1. **Dynamic Programming (DP)**: Precomputing a table of combinations.
2. **Traditional Method with Modular Inverse**: Using precomputed factorials and Fermat's Little Theorem for modular inverses.
3. **Traditional Method Without Modular Inverse**: A straightforward combination calculation without modular arithmetic, used for smaller values of \(n\) and \(r\).

### Methods Explained

#### 1. **Dynamic Programming (DP) Method**

**Precomputation**:
- A 2D DP table (`comb`) is precomputed where `comb[i][j]` holds the value of \(iCj\) modulo \(10^9 + 7\).
- For each row `i`, the combination values are computed recursively using the identity:
  \[
  C(i, j) = C(i-1, j-1) + C(i-1, j)
  \]
- **Time Complexity**:
  - **Precomputation**: \(O(N^2)\) to fill the DP table.
  - **Query**: \(O(1)\) for retrieving any combination.
- **Space Complexity**: \(O(N^2)\) for storing the DP table.

**Advantages**:
- Very fast for queries once the DP table is precomputed.
- Suitable for solving problems requiring many combination queries efficiently.
- Guaranteed accuracy since there are no issues with precision or modular arithmetic.

**Disadvantages**:
- **Space Complexity**: \(O(N^2)\), which can become large for high values of \(N\) (e.g., \(N = 10^5\)).
- Not feasible for extremely large \(n\), as the space requirements grow quadratically.

**When to Use**:
- When you need to calculate many combinations for different values of \(n\) and \(r\).
- When \(N\) is moderate, and space is not a significant concern.

---

#### 2. **Traditional Method with Modular Inverse (Fermat's Little Theorem)**

**Precomputation**:
- Factorials and their modular inverses are precomputed.
- Modular inverses are computed using Fermat’s Little Theorem, which allows the inverse of \(a\) modulo \(p\) to be calculated as:
  \[
  a^{p-2} \mod p
  \]
- **Time Complexity**:
  - **Precomputation**: \(O(N)\) for computing factorials and their modular inverses.
  - **Query**: \(O(1)\) for retrieving combinations after precomputation.
- **Space Complexity**: \(O(N)\) for storing factorials and their inverses.

**Advantages**:
- **Efficient**: Once precomputation is done, each combination query takes \(O(1)\) time.
- **Space-efficient**: Requires only \(O(N)\) space for factorials and inverses.
- **Accurate**: Handles large values correctly using modular arithmetic, which avoids overflow.

**Disadvantages**:
- **Precomputation required**: Requires computing factorials and inverses upfront.
- **Not feasible for very large \(n\)** unless modulo arithmetic is used, since factorials grow very large.

**When to Use**:
- When \(n\) and \(r\) are large, but you only need to make a few queries.
- Suitable for problems that involve **modular arithmetic**, such as competitive programming.

---

#### 3. **Traditional Method Without Modular Inverse**

**Calculation**:
- Combines the factorials directly without using modular arithmetic.
- **Time Complexity**: \(O(n \cdot r)\) due to the factorial and division operations.
- **Space Complexity**: \(O(1)\), since no additional space is required.

**Advantages**:
- **Simple and easy to understand**.
- **No precomputation** needed, making it straightforward for small values of \(n\) and \(r\).

**Disadvantages**:
- **Inefficient for large \(n\)** due to direct multiplication and division.
- **Overflow issues**: Can lead to overflow in languages without big integer support, especially for large factorials.
- **No modular arithmetic**: Does not handle large numbers well without modular reduction.

**When to Use**:
- Only for small values of \(n\) and \(r\).
- When you do not need modular arithmetic, and \(n\) and \(r\) are small enough to avoid overflow.

---

### Conclusion

- **Dynamic Programming (DP)** is the best choice when you need to calculate many combinations efficiently after a single precomputation, especially for moderate values of \(n\) where space is not a limiting factor.
- **Traditional Method with Modular Inverse** is ideal when \(n\) and \(r\) are large, and you need fast queries after an initial precomputation. It is the most space-efficient for large \(n\) and handles modular arithmetic correctly.
- **Traditional Method Without Modular Inverse** is only suitable for small \(n\) and \(r\) and should be avoided for large values or when modulus is required to prevent overflow.

### Complexity Summary

| Method | Time Complexity | Space Complexity |
|--------|-----------------|------------------|
| **DP** | \(O(N^2)\) (precomputation), \(O(1)\) (query) | \(O(N^2)\) |
| **Modular Inverse** | \(O(N)\) (precomputation), \(O(1)\) (query) | \(O(N)\) |
| **Without Modular Inverse** | \(O(n \cdot r)\) | \(O(1)\) |

---


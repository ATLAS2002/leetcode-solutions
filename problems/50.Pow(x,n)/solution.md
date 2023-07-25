# Intuition
> Iterative Approach ⌛

We can get desired results by just multiplying `x`, `n` times ...but that would make time complexity of this algorithm linear $O(N)$.

> Divide and Conquer ✔️

Since, `n` ranges from `INT_MIN` to `INT_MAX`, we are not allowed to implement a simple linear algorithm. What we can do is, Recursively calculate the subproblems and use them accordingly. This would reduce time complexity down to logarithmic $O(logN)$, which is much much better.

<hr/>

# Approach
### Tips :
- Use recursion (Shorter Code)
- Take the parameter `n` as `long int` (any larger datatype than `int` will do) to avoid overflow/Runtime Error.
- Store the value of a recursion call so you don't need to call it again.
### Steps :
1. Base Cases :
    i ) If `n==1` then `return x`.
    ii ) If `n==0` then `return 1`.
    iii ) If `x==1` then `return 1`.
2. Corner Case :
`n` being negative means, `1/x` being multiplied `positive n` times. Instead of writing separate code, we can recursively get the value of `x` being multiplied `abs(n)` times. And return `1/value`.
3. Recurrence Relation :
i ) When `n` is `even` : We can assume `n = 2k`, where `k` is any positive integer. Now we can write the relation as `myPow(x,n) = myPow(x,k) * myPow(x,k)`. [ because `xⁿ.xⁿ = x²ⁿ`]
ii ) When `n` is `odd` : We can assume `n = 2k + 1`, where `k` is any positive integer. Now we can write the relation as `myPow(x,n) = myPow(x,k) * myPow(x,k) * x`. [ because `xⁿ.xⁿ.x = (x)²ⁿ+¹`]

<hr/>

# Complexity
- :hourglass_flowing_sand: Time complexity: _O(logN)_
- :package: Space complexity: _O(logN)_

<hr/>

# Code
```cpp
class Solution {
public:
    double myPow(double x, long int n) {
        if(n==1) return x;
        if(x==1.0 or n==0) return 1.0;
        if(n<0) return 1.0/myPow(x, -n);
        double ans = myPow(x,n/2);
        ans *= ans;
        if(n&1) ans *= x;
        return ans;
    }
};
```
<hr/>

- :calender: **Date :** $24/07/2023$
- :copyright: **Author :** _Siddharth Biswas_  
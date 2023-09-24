# :thought_balloon: Intuition
> Iterative Approach ⌛

We can get desired results by just multiplying `x`, `n` times ...but that would make time complexity of this algorithm linear $O(N)$.

> Divide and Conquer ✔️

Since, `n` ranges from `INT_MIN` to `INT_MAX`, we are not allowed to implement a simple linear algorithm. What we can do is, Recursively calculate the subproblems and use them accordingly. This would reduce time complexity down to logarithmic $O(logN)$, which is much much better.

<hr/>

# :pencil: Approach
### Tips :
- Use recursion _(Shorter Code)_
- Take the parameter `n` as `long int` <sub>_(any larger datatype than `int` will do)_</sub> to avoid overflow/Runtime Error.
- Store the value of a recursion call so you don't need to call it again.
### Steps :
1. Base Cases :
- If `n==1` then `return x`.
- If `n==0` then `return 1`.
- If `x==1` then `return 1`.
2. Corner Case : <br/> 
`n` being negative means, `1/x` being multiplied `positive n` times. Instead of writing separate code, we can recursively get the value of `x` being multiplied `abs(n)` times. And return `1/value`.
3. Recurrence Relation :
<br/> i ) When `n` is `even` : We can assume `n = 2k`, where `k` is any positive integer. Now we can write the relation as `myPow(x,n) = myPow(x,k) * myPow(x,k)`. [ because ${x^k * x^k} = x^{2k} = x^n$ ] 
<br/> ii ) When `n` is `odd` : We can assume `n = 2k + 1`, where `k` is any positive integer. Now we can write the relation as `myPow(x,n) = myPow(x,k) * myPow(x,k) * x`. [ because $x^k * x^k * x = x^{2k+1} = x^n$ ]

<hr/>

# :bar_chart: Complexity
- :hourglass_flowing_sand: Time complexity: _O(logN)_
- :package: Space complexity: _O(logN)_

<hr/>

# :keyboard: Code
```cpp
class Solution {
public:
    double myPow(double x, long int n) {
        if(n==1) return x; // base case
        if(x==1.0 or n==0) return 1.0; // base case 
        if(n<0) return 1.0/myPow(x, -n); // handling corner case
        double ans = myPow(x,n/2); // store value of subproblem
        ans *= ans; // reuse that value
        if(n&1) ans *= x; // when n is odd
        return ans;
    }
};
```
<hr/>

# :card_index_dividers: Metadata
- :question: **Question :** [`Pow(x, n)`](https://leetcode.com/problems/powx-n)
- :vertical_traffic_light: **Difficulty :** medium 
- :calendar: **Date :** $24/07/2023$
- :copyright: **Author :** _Siddharth Biswas_  

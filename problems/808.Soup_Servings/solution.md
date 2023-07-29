# 💭 Intuition
Only thing that makes this problem harder to solve is that ridiculous constraint. There is no way you can run a loop for $10^9$, also you can not use any logarithmic approach to cut down the time complexity. <br/>
On the surface it does look impossible, but upon closer inspection you can see as the value of `n` goes higher, the answer also gets closer to 1. <br/>
![INPUTvsOUTPUT_GRAPH](https://assets.leetcode.com/users/images/e625902a-2dd7-4964-bb28-4f3271f2ae15_1690625521.5589256.png) <br/>
After a certain point _`(n = 4800)`_, the answer is always $\to1$. Now we have narrowed down the constraint to 4799. We can use depth first seach to get probability for all operations. Then we memoize it to optimize efficiently.

<hr/>

# 📝 Approach
- Return 1 if `n >= 4800`.
- Declare a `dp` array, to keep track remaining amount of soups. Give it a size of `n+1` for `soup_a` and `n+1` for `soup_b`. Inititally all values are set to -1.
- Define the `operations` array globally (or you can define inside main function and pass it to the helper function). Purpose of this array is to store the possible operations. I have made it as an array of 4 pairs. `operations = {{100,0},{75,25},{50,50},{25,75}}` <br/>
It is totally upto you how you handle this, you can even directly use the operations without using an array but it is considered good practice.
- Then `n` is passed to `calc` function as the volume of soup A and B. <br/>
  Which then uses depth first search algorithm and generates all necessary subproblems and returns the answer.
- Base Cases :
    - If A is empty, return 1.
    - If A and B both are empty, return 0.5.
    - If B is empty, return 0.
    - If `dp` already has the answer, return it.
- Add up the probabilities after doing all 4 operations. Since each operation has equal probability of occuring, multiply them with 0.25 (divide by 4) to get current probability.
- Before returning the value, store it in `dp`. 

<hr/>

# 📊 Complexity
- ⏳ Time complexity: $O(N^2)$
- 📦 Space complexity: $O(N^2) + Recursive\ Stack\ Space$

<hr/>

# ⌨️ Code
```cpp
class Solution {
    pair<int,int> operations[4] = {{100,0},{75,25},{50,50},{25,75}};
    double calc(int soup_a, int soup_b, vector<vector<double>>& dp) {
        if(soup_a <= 0 and soup_b <= 0) return 0.5; // both empty
        if(soup_a <= 0) return 1.0; // soup A empty
        if(soup_b <= 0) return 0.0; // soup B empty
        if(dp[soup_a][soup_b] != -1) return dp[soup_a][soup_b]; // repeating
        double probability = 0;
        for(const auto opr : operations) // DFS
            probability += calc(soup_a - opr.first, soup_b - opr.second, dp);
        return dp[soup_a][soup_b] = probability / 4;
    }
public:
    double soupServings(int n) {
        if(n >= 4800) return 1.0; // check INTUITION for explanation
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        return calc(n, n, dp);
    }
};
```

<hr/>

# :card_index_dividers: Metadata
- :question: **Question :** [`Soup Servings`](https://leetcode.com/problems/soup-servings)
- :vertical_traffic_light: **Difficulty :** medium 
- :calendar: **Date :** $29/07/2023$
- :copyright: **Author :** _Siddharth Biswas_  

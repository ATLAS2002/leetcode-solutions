# 💭 Intuition
Okay this one is straightforward DP question. Because the solution is the **LOWEST** sum of removed characters. So we have to remove minimum letters possible from both of the strings, so remaining strings are equal. If thought in reverse, we will be solving to *maximize the length of remaining string, which would be a subsequence of both strings*.
Hmm, does that ring a bell? Ah yes,the classic **LCS** DP problem.
1. Find the Longest Common Substring of `s1` and `s2`.
    1. First priority is length of the string. $longer\ the\ better\ [¬‿¬]$
    2. Take characters with higher ASCII value. That is second priority.
3. Calculate `total` ASCII sum of both `s1` and `s2`.
4. Since the LCS appears in both strings, we will have to deduct it twice from `total`.  And that is the desired answer.
 
<hr/>

# 📝Approach
We will be using a 2D array `dp` as a table to store the subproblems. 
It will have `n` rows and `m` columns, all cells are initially 0.
- $E.g:$ `dp[i][j]` = answer to the subproblem where,
    - first string is `i+1` length prefix of `s1` 
    - second string is `j+1` length prefix of `s2`.
    
Next step is to fill the table `dp`:
- There are total 3 choices that we have.
    - If currently both characters match `s1[i] == s2[j]`, then we can take that ASCII value and add it to previous best answer `dp[i-1][j-1]`.
    - If we don't take then also we have two options
        - take one less character from `s1`. `dp[i-1][j]`
        - take one less character from `s2`. `dp[i][j-1]`

Now that we have the maximum sum of ASCII values of the Longest Common Subsequence of `s1` and `s2`, we can easily find the sum of characters that are being omitted.
    We can do so by adding up ASCII values of all characters in both strings, then deduct `dp[n-1][m-1]` twice, because they appear in both strings.
$\therefore$ The answer is `total` - 2 * `dp[n-1][m-1]`.

<hr/>

# 📊 Complexity
- ⏳ Time complexity: $O(N^2)$

- 📦 Space complexity: $O(N^2)$
 
<hr/>

# ⌨️ Code
```cpp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int dp[n][m]; memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int ans = 0;
                if(s1[i] == s2[j]) {
                    ans = s1[i]; 
                    if(i && j) // boundary check to avoid runtime errors
                        ans += dp[i-1][j-1]; 
                }
                // previous answers :
                if(i) ans = max(ans, dp[i-1][j]); 
                if(j) ans = max(ans, dp[i][j-1]); 
                dp[i][j] = ans;
            }
        }
        int total = 0;
        for(const auto& c : s1) total += c;
        for(const auto& c : s2) total += c;
        return total - 2*dp[n-1][m-1];
    }
};
```

<hr/>

# :card_index_dividers: Metadata
- :question: **Question :** [`Minimum ASCII Delete Sum for Two Strings`](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings)
- :vertical_traffic_light: **Difficulty :** medium 
- :calendar: **Date :** $31/07/2023$
- :copyright: **Author :** _Siddharth Biswas_  

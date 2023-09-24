# 💭 Intuition

- Initially all glasses are empty.
- Pour all cups of champaign in the top glass (0,0).
- Each cup can hold at most 1 cup of champaign. <br/>
    In case of overflowing, the excess amount is divided into two equal portions and poured onto the bottom (r+1, c) and bottom-right (r+1, c+1) glasses.
- 2D dp is an optimal approach. <br/>
    We can populate `dp[i][j]` with the help of `dp[i-1][j]` and `dp[i-1][j-1]`. <br/>
    That implies each children can be derived from their direct parents (`dp[i-1]`). 
- Since we are asked about a single glass in a particular row, storing the whole 2D array of answers does not help. <br/>
    We just need values of previous row to get answer of current row.
- Keep track of 2, 1D arrays (`prev` and `curr`) to populate the answers.
- On closer inspection, We can get the values from `prev` array and update the same array, such that there is no information loss. <br/> 
- This has to be done is *reverse*, so the values between previous row and current row are not mixed up. <br/>
     

<hr/>

# 📝 Approach

1. Declare a 1D dp array of size `query_row + 1` with initial value of 0.
2. Initially all the champaign is poured inside top glass. `dp[0] = poured`
3. Keep traversing the rows until `query_row`.
4. Start filling from the last glass of that row. <br/>
    - Because each glass overflows to the bottom and bottom-right glass.
    - Filling from the start will change the value of next glass in that column, overwriting the value of previous row in that column.
5. If `dp[i] <= 1`, then it won't overflow.
6. Else the excess amount `dp[i] - 1` is poured in equal halves.
7. Here we will add one half to next column, and rewrite the current column with another half.
8. After `query_row - 1`th row is done traversing, it is assured that target glass is not going to be filled anymore.
9. Return `1.0` if glass is overflowing, else return `dp[query_glass]`.

<hr/>

# 📊 Complexity

###### $N$ = `query_row`

- ⏳ Time complexity: $O(N^2)$

- 📦 Space complexity: $O(N)$

<hr/>

# ⌨️ Code

```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[query_row+1];
        memset(dp, 0.0, sizeof(dp));
        dp[0] = poured;
        for (int row = 0; row < query_row; row++) {
            for (int col = row; col >= 0; col--) {
                double excess_half = std::max(0.0, (dp[col] - 1) / 2.0);
                dp[col + 1] += excess_half;
                dp[col] = excess_half;
            }
        }
        return std::min(1.0, dp[query_glass]);
    }
};
```

<hr/>

# :card_index_dividers: Metadata

- :question: **Question :** [`Champagne Tower`](https://leetcode.com/problems/champagne-tower)
- :vertical_traffic_light: **Difficulty :** medium
- :calendar: **Date :** $24/09/2023$
- :copyright: **Author :** _Siddharth Biswas_  

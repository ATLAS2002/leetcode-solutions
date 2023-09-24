# 💭 Intuition
Can we use subproblems to get current answer? **YES!**
Think of it like this: when player_1 chooses a number the **score increases** by that number. Similarly when player_2 chooses, **score decreases**. If the score is $\ge0$ in the end, then player_1 wins!
### Let's understand this method with an example
- Suppose one player is picking from range $[l,\dots,r]$.
- If he picks $l$, then other player has to choose either $l+1$ or $r$. 
- If he picks $r$, other player will be choosing either $l$ or $r-1$.

And so on this process continues. Both try their best.
$\therefore$ Final score = sum of all numbers player_1 chose - sum of all numbers player_2 chose
= 1st pick - 2nd pick + 3rd pick - 4th pick + ...
= 1st pick - [2nd pick - 3rd pick + 4th pick - ...]
In this way total of player_1's score is being added to final score, and total of player_2's score is being decremented from it.
There is our recurrence relation! 
###### We can use recursion to implement this. And we can further optimize the program using DP.

<hr/>

# 📝 Approach
### Let's look at recursion implementation first!
- Here, `solve` function recursively searches in every subarray of `nums` which is expensive in terms of time complexity. 
- It takes the whole `nums` array, a `start` and an `end` point as parameters. Those two integers help to keep track of starting and ending position of current subarray of `nums`.
- As a base case, check if current subarray exists (whether `start <= end` is true). Else eturn 0, current player cannot choose anymore.
- If player takes first element of the subarray, then next player will have to choose `start+1` or `end`. <br/>
 So `takes_first` = `nums[start] - solve(start+1, end)`.
- If player takes last element of the subarray, next player chooses either `start` or `end-1`. <br/>
 So `takes_last` = `nums[end] - solve(start, end-1)`.
- Both players are playing optimally, current answer will be maximum between these two options. `max(takes_first, takes_last)`
###### If the final score is greater than or equals to 0, return ***true*** else return ***false***.
#### There exists multiple overlapping subproblems. Handling them wisely will result in a much faster program. That's where _Memoization(Top-Down)_ comes into play.
The subproblems are unique by the `start` and `end` point of their subarrays. We can store values of the subproblems in a 2D array `memo`, that stores answer to subarrays starting from `start` and ending to `end` index. 
- Memoizing a recursive solution is really easy. Create the array `memo` with maximum possible values of these two required states `start` and `end`. _[Since we are declaring the array globally... we will be taking maximum value of N, that is 20]_
- Initially all values should be set to `-1`, so that we know this subproblem has not appeared before.
- Inside `solve` function, right after the base case, check if the current subproblem has been generated previously, if yes return `memo[start][end]`.
- Else just let the recursion generate the answer for you. And right after returning the answer, put that inside `memo`. `memo[start][end] = ans`

And that's it! You have memoized the recursive solution. 
### With the help of memoization we greatly reduced the execution time by elemenating repeatative calculation of subproblems. But that's not all, this code can be further optimized by discarding the recursion part.
- Now that we don't need the `solve` function to do anymore recursion, we can just declare `dp` array inside the main function. One advantage is now you give it the correct size _[that is given value of N = `nums.size()`]_
- Rather than starting from the whole array, in this approach we will be generating the smallest subproblems first. Then using smaller subproblems we can generate answer to bigger subproblems.
- The problem is bigger when length of subarray is greater.
  Which means first we have to calculate for every subarray having length 1, then 2, 3, ..., and finally the whole array.
- Run the outer loop from `length=1` to `length=n`.
- Inside the outer loop, run the inner loop from `start=0` to `start=n-length`.
- As a base case, generate answers to subarrays having length 1. `dp[i][i] = nums[i]`
- Instead of calling the function to get the answer to smaller subproblems, we can directly access them through `dp` array now. 
- With the same logic, we get the values of `takes_first` and `takes_last`.
- Before this iteration ends, store the maximum score in dp. `dp[start][end] = max(takes_first, takes_last)`
- In the end, return true if `dp[0][n-1] >= 0`, else return false. 

<hr/>

# 📊 Complexity
- ⏳ **Time complexity :**
    - **Recursion** : $O(2^N)$ 
    - **Memoization** : $O(N^2)$
    - **Tabulation** : $O(N^2)$

- 📦 **Space complexity :**
    - **Recursion** : $O(N)$ *(Recursive stack space)*
    - **Memoization** : $O(N^2 + N)$ *(that extra N is Recursive stack space)*
    - **Tabulation** : $O(N^2)$
    
<hr/>


# ⌨️ Code

### 🥉 RECURSION
```cpp
class Solution {
private:
    // returns final score = score of player 1 - score of player 2
    int solve(vector<int>& nums, int start, int end) {
        if(start > end) return 0; // base case
        int takes_first = nums[start] - solve(nums, start+1, end); // if player takes left first number
        int takes_last = nums[end] - solve(nums, start, end-1); // if player takes right first number
        return max(takes_first, takes_last); // player will choose the maximum score
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1) >= 0; // returns true when answer is not negative
    }
};
```

### 🥈 TOP-DOWN APPROACH *(Time Complexity reduced)*
```cpp
class Solution {
private:
    int memo[20][20]; // dp array
    // returns final score
    int solve(vector<int>& nums, int start, int end) {
        if(start > end) return 0; // base case
        if(memo[start][end] != -1) return memo[start][end]; // check if current subproblem has been computed before
        int takes_first = nums[start] - solve(nums, start+1, end); // if player takes left first number
        int takes_last = nums[end] - solve(nums, start, end-1); // if player takes right first number
        return memo[start][end] = max(takes_first, takes_last); // store the answer first, then return it
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        memset(memo, -1, sizeof(memo)); // initially -1, implying no subproblem has been computed yet
        return solve(nums, 0, nums.size()-1) >= 0; // returns true when answer is not negative
    }
};
```
### 🥇 BOTTOM-UP APPROACH _(Auxilary Stack Space removed)_
```cpp
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n]; // dp array
        for(int length = 1; length <= n; length++) { // loop starting from smallest subproblem to bigger 
            for(int start = 0; start <= n-length; start++){ // starting point of each subarray
                if(length == 1) { // base case
                    dp[start][start] = nums[start];
                    continue;
                }
                int end = start+length-1;
                int takes_first = nums[start] - dp[start+1][end]; // if player takes left first number
                int takes_last = nums[end] - dp[start][end-1]; // if player takes right first number
                dp[start][end] = max(takes_first, takes_last); // store the answer in dp array
            }
        }
        return dp[0][n-1] >= 0; // returns true when answer is not negative
    }
};
```

<hr/>

# :card_index_dividers: Metadata
- :question: **Question :** [`Predict the Winner`](https://leetcode.com/problems/predict-the-winner)
- :vertical_traffic_light: **Difficulty :** medium 
- :calendar: **Date :** $28/07/2023$
- :copyright: **Author :** _Siddharth Biswas_  

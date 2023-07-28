class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        for(int length = 1; length <= n; length++) {
            for(int start = 0; start <= n-length; start++){
                if(length == 1) {
                    dp[start][start] = nums[start];
                    continue;
                }
                int end = start+length-1;
                int takes_first = nums[start] - dp[start+1][end];
                int takes_last = nums[end] - dp[start][end-1];
                dp[start][end] = max(takes_first, takes_last);
            }
        }
        return dp[0][n-1] >= 0;
    }
};
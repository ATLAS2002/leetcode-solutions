class Solution {
private:
    int memo[20][20];
    int solve(vector<int>& nums, int start, int end) {
        if(start > end) return 0;
        if(memo[start][end] != -1) return memo[start][end];
        int takes_first = nums[start] - solve(nums, start+1, end);
        int takes_last = nums[end] - solve(nums, start, end-1);
        return memo[start][end] = max(takes_first, takes_last);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return solve(nums, 0, nums.size()-1) >= 0;
    }
};
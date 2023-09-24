class Solution {
private:
    int solve(vector<int>& nums, int start, int end) {
        if(start > end) return 0;
        int takes_first = nums[start] - solve(nums, start+1, end);
        int takes_last = nums[end] - solve(nums, start, end-1);
        return max(takes_first, takes_last);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1) >= 0;
    }
};
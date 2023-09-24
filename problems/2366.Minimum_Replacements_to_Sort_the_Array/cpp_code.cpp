class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        for(int i=nums.size()-2; i>=0; i--) {
            if(nums[i] <= nums[i+1]) continue;
            int div = (nums[i] + nums[i+1] - 1) / nums[i+1];
            ans += div-1;
            nums[i] /= div;
        }   return ans;
    }
};
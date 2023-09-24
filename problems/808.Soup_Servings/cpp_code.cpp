class Solution {
    pair<int,int> operations[4] = {{100,0},{75,25},{50,50},{25,75}};
    double calc(int soup_a, int soup_b, vector<vector<double>>& dp) {
        if(soup_a <= 0 and soup_b <= 0) return 0.5;
        if(soup_a <= 0) return 1.0;
        if(soup_b <= 0) return 0.0;
        if(dp[soup_a][soup_b] != -1) return dp[soup_a][soup_b];
        double probability = 0;
        for(const auto opr : operations)
            probability += calc(soup_a - opr.first, soup_b - opr.second, dp);
        return dp[soup_a][soup_b] = probability / 4;
    }
public:
    double soupServings(int n) {
        if(n >= 4800) return 1.0;
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        return calc(n, n, dp);
    }
};
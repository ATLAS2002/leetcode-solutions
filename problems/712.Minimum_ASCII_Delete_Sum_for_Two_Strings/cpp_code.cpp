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
                    if(i && j) 
                        ans += dp[i-1][j-1]; 
                }
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
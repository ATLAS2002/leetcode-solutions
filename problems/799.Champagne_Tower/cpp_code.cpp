#include <bits/stdc++.h>

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        double dp[query_row + 1];
        memset(dp, 0.0, sizeof(dp));
        dp[0] = poured;
        for (int row = 0; row < query_row; row++)
        {
            for (int col = row; col >= 0; col--)
            {
                double excess_half = std::max(0.0, (dp[col] - 1) / 2.0);
                dp[col + 1] += excess_half;
                dp[col] = excess_half;
            }
        }
        return std::min(1.0, dp[query_glass]);
    }
};

int main()
{
    Solution solve;
    for (int i = 0; i < 6; i++)
    {
        int poured, query_row, query_glass;
        std::cin >> poured >> query_row >> query_glass;
        std::cout << solve.champagneTower(poured, query_row, query_glass) << std::endl;
    }
    return 0;
}
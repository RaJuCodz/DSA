class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || K == 0)
            return 0;

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(K + 1, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 2; b++) {
                for (int k = 1; k <= K; k++) {
                    if (b == 1) {
                        dp[i][b][k] =
                            max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
                    } else {
                        dp[i][b][k] = max(prices[i] + dp[i + 1][1][k - 1],
                                          dp[i + 1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][K];
    }
};

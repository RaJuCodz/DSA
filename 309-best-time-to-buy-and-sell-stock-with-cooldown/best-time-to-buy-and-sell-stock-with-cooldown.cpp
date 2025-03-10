class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp0(n + 2, 0), dp1(n + 2, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp0[i] = max(dp0[i + 1], -prices[i] + dp1[i + 1]);
            dp1[i] = max(dp1[i + 1], prices[i] + dp0[i + 2]);
        }
        return dp0[0];
    }
};

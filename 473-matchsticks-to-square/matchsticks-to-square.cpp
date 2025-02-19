class Solution {
public:
    bool makesquare(vector<int>& m) {
        int n = m.size();
        int sum = accumulate(m.begin(), m.end(), 0);
        if (sum % 4 != 0) return false;
        sum /= 4;
        
        vector<int> dp(1 << n, -1);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) continue;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue; 
                int nmask = mask | (1 << j);
                if (dp[mask] + m[j] <= sum) 
                    dp[nmask] = (dp[mask] + m[j]) % sum;
            }
        }
        return dp[(1 << n) - 1] == 0; 
    }
};

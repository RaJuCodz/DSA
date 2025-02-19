class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;
        
        int target = totalSum / k;
        int fullMask = (1 << n) - 1;
        vector<int> dp(1 << n, -1);
        dp[0] = 0;

        for (int mask = 0; mask <= fullMask; mask++) {
            if (dp[mask] == -1) continue; 

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) {
                    int newMask = mask | (1 << i);
                    if (dp[mask] + nums[i] <= target)
                        dp[newMask] = (dp[mask] + nums[i]) % target;
                }
            }
        }
        
        return dp[fullMask] == 0; 
    }
};

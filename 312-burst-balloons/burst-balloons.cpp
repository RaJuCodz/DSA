class Solution {
public:
    vector<vector<int>> memo;
    vector<int> a;    
    int rec(int left, int right) {
        if (left + 1 == right) return 0;
        if (memo[left][right] != -1) return memo[left][right];
        int ans = 0;
        for (int i = left + 1; i < right; i++) {
            ans = max(ans, a[left] * a[i] * a[right] + rec(left, i) + rec(i, right));
        }
        return memo[left][right] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        a.resize(n + 2, 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = nums[i];
        }
        memo.assign(n + 2, vector<int>(n + 2, -1));
        return rec(0, n + 1);
    }
};

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> a = nums, diff(n + 1, 0);

        auto f = [&](int k) -> bool {
            fill(diff.begin(), diff.end(), 0);
            for (int i = 0; i < k; ++i) {
                int l = queries[i][0], r = queries[i][1], val = queries[i][2];
                diff[l] -= val;
                if (r + 1 < n) diff[r + 1] += val;
            }
            int curr = 0;
            for (int i = 0; i < n; ++i) {
                curr += diff[i];
                if ((a[i] + curr) > 0) return false;
            }
            return true;
        };

        int left = 0, right = m, ans= -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (f(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

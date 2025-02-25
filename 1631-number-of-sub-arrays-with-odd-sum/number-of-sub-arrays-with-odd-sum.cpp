class Solution { 
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1, sum = 0, ans = 0;

        for (int num : arr) {
            sum += num;
            if (sum % 2 == 0) {
                ans = (ans + oddCount) % MOD;
                evenCount++;
            } else {
                ans = (ans + evenCount) % MOD;
                oddCount++;
            }
        }
        return ans;
    }
};

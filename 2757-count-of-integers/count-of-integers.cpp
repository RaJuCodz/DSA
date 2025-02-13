typedef long long ll;
int MOD = 1e9+7;
class Solution {
public:
    int dp[23][2][405];
    int mini, maxi;
    string R;
    
    int rec(int i, int tight, int sum) {
        if (sum > maxi) return 0; 
        if (i == R.size()) {
            return (sum >= mini && sum <= maxi);
        }
        if (dp[i][tight][sum] != -1) return dp[i][tight][sum];

        int ans = 0;
        int limit = (tight == 1) ? (R[i] - '0') : 9;

        for (int j = 0; j <= limit; j++) {
            ans = (ans + rec(i + 1, (tight & (j == limit)), sum + j)) % MOD;
        }

        return dp[i][tight][sum] = ans;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        mini = min_sum;
        maxi = max_sum;
        R = num2;
        int right = rec(0, 1, 0) % MOD;

        memset(dp, -1, sizeof(dp));
        R = num1;
        int left = rec(0, 1, 0) % MOD;
        int sum = 0;
        for (char x : num1) sum += (x - '0');
        int ok = (sum >= mini && sum <= maxi) ? 1 : 0;

        return (right - left + ok + MOD) % MOD;
    }
};

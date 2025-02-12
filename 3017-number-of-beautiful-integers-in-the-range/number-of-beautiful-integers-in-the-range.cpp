class Solution {
public:
    int dp[10][2][2][10][10][20];
    int k;

    int rec(string &s, int i, bool tight, bool l, int even, int odd, int remainder) {
        if (i >= s.size()) return (remainder == 0) && (even == odd);

        if (dp[i][tight][l][even][odd][remainder] != -1) 
            return dp[i][tight][l][even][odd][remainder];

        int lmt = tight ? s[i] - '0' : 9;
        int ans = 0;

        for (int dig = 0; dig <= lmt; dig++) {
            ans += rec(
                s, 
                i + 1, 
                tight && (dig == lmt), 
                l && (dig == 0), 
                even + (dig == 0 ? !l : !(dig & 1)), 
                odd + (dig & 1), 
                (((int)pow(10, s.size() - i - 1) * dig) + remainder) % k
            );
        }
        
        return dp[i][tight][l][even][odd][remainder] = ans;
    }

    int numberOfBeautifulIntegers(int l, int r, int k) {
        this->k = k;
        
        string s = to_string(l - 1);
        memset(dp, -1, sizeof(dp));
        int ansl = rec(s, 0, 1, 1, 0, 0, 0);

        s = to_string(r);
        memset(dp, -1, sizeof(dp));
        return rec(s, 0, 1, 1, 0, 0, 0) - ansl;
    }
};

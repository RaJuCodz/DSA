class Solution {
public:
    int dp[11][2][1024][2];

    int gogo(string &s, int tight = 1, int pos = 0, int mask = 0, int rep = 0) {
        if (pos == s.size()) return rep;
        if (dp[pos][tight][mask][rep] != -1) return dp[pos][tight][mask][rep];

        int ans = 0;
        for (int i = 0; i <= (tight ? s[pos] - '0' : 9); i++) {
            int newMask = (mask == 0 && i == 0) ? mask : (mask | (1 << i));
            ans += gogo(s, tight && (i == s[pos] - '0'), pos + 1, newMask, rep | ((mask >> i) & 1));
        }
        return dp[pos][tight][mask][rep] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return gogo(s);
    }
};

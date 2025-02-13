typedef long long ll;
class Solution {
public:
    int MOD = 1e9+7;
    int dp[501][2][52]; 
    int nxt[52][26];    
    string e, Z;
    
    void buildAutomaton(string &evil) {
        int m = evil.size();
        vector<int> lps(m, 0);
        for (int i = 1, len = 0; i < m; i++) {
            while (len > 0 && evil[i] != evil[len])
                len = lps[len - 1];
            if (evil[i] == evil[len])
                len++;
            lps[i] = len;
        }
    
        for (int i = 0; i <= m; i++) {
            for (int ch = 0; ch < 26; ch++) {
                if (i < m && (evil[i] - 'a' == ch))
                    nxt[i][ch] = i + 1;
                else {
                    if (i == 0)
                        nxt[i][ch] = 0;
                    else
                        nxt[i][ch] = nxt[lps[i - 1]][ch];
                }
            }
        }
    }
    
    int rec(int i, int tight, int state, int n) {
        if (state == e.size()) return 0; 
        if (i == n) return 1;
        if (dp[i][tight][state] != -1) return dp[i][tight][state];
        int ans = 0;
        char lim = (tight == 1) ? Z[i] : 'z';
        for (char c = 'a'; c <= lim; c++) {
            int nt = tight;
            if (tight == 1 && c < lim)
                nt = 0;
            int newState = nxt[state][c - 'a'];
            if (newState == e.size())
                continue;
            ans = (ans + rec(i + 1, nt, newState, n)) % MOD;
        }
        return dp[i][tight][state] = ans;
    }
    
    int findGoodStrings(int n, string S1, string S2, string evil) {
        e = evil;
        buildAutomaton(evil);
        
        memset(dp, -1, sizeof(dp));
        Z = S2;
        int R = rec(0, 1, 0, n);
        
        memset(dp, -1, sizeof(dp));
        Z = S1;
        int L = rec(0, 1, 0, n);
        bool valid = true;
        int state = 0;
        for (char c : S1) {
            state = nxt[state][c - 'a'];
            if (state == e.size()) {
                valid = false;
                break;
            }
        }
        return (R - L + (valid ? 1 : 0) + MOD) % MOD;
    }
};

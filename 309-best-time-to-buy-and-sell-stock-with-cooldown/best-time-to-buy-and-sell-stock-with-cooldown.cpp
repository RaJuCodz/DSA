class Solution {
public:
    int dp[5000][2];
    vector<int> a;
    
    int rec(int i, int holding) {
        if(i >= a.size()) return 0;
        if(dp[i][holding] != -1) return dp[i][holding];
        int doNothing = rec(i+1, holding);
        if(holding == 0) {
            int buy = -a[i] + rec(i+1, 1);
            dp[i][holding] = max(doNothing, buy);
        } else { 
            int sell = a[i] + rec(i+2, 0); 
            dp[i][holding] = max(doNothing, sell);
        }
        return dp[i][holding];
    }
    
    int maxProfit(vector<int>& prices) {
        a = prices;
        memset(dp, -1, sizeof(dp));
        return rec(0, 0);
    }
};

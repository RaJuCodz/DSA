class Solution {
public:
    int dp[501][501];
    vector<int> a;
    int INF = 1e9;
    int k;
    int n;
    int rec(int i , int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans =INF;
        if(i<n-1)ans= min(ans,a[i+1]-a[i] + rec(i+2,j));
        if(j>0)ans= min(ans,a[j]-a[j-1] + rec(i,j-2));
        ans=min(ans,k + rec(i+1,j-1));
        return dp[i][j]=ans;

    }
    int minOperations(string s, string t, int x) {
        k=x;
        for(int i =0;i<s.size();i++){
            if(s[i]!=t[i]) a.push_back(i);
        }
        n=a.size();
        if(a.size()%2) return -1;
        memset(dp,-1,sizeof(dp));
        return rec(0,a.size()-1);

    }
};
class Solution {
public:
    int maximumLength(vector<int>& a, int k) {
       int n = a.size();
        int ans =0;
        vector<vector<int>> dp(n+1,vector<int> (k,1));
        for(int i =1;i<n;i++){
            for(int j =0;j<i;j++){
                // for i har j ko compare karega jo issme pehle aaya try karega (a[j] + a[i]) wala subsequence bane
                int rem = (a[i]+a[j])%k;
                dp[i][rem]=max(dp[i][rem],1+dp[j][rem]);
                ans=max(dp[i][rem],ans);
            }
        }
        return ans;

    }
};
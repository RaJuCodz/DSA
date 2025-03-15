class Solution {
public:
    vector<int> a;
    int x;
    // int dp[100001][2];
    int rec(int i,int last,vector<vector<int>> &dp){
        if(i==a.size()) return 0;
        if(dp[i][last]!=-1) return dp[i][last];
        int ans =0;
        ans=max(ans,rec(i+1,0,dp));
        if(last==0 && a[i]<=x) ans=max(ans,1+rec(i+1,1,dp));
        return dp[i][last]=ans;
    }
    int minCapability(vector<int>& nums, int k) {
        a=nums;
        int L =0; int n = a.size();
        int R =*max_element(nums.begin(),nums.end());
        int ans =1e9;
        auto check =[&](int y){
            x=y;
            vector<vector<int>> dp(n+1,vector<int>(2,-1));
            if(rec(0,0,dp)>=k) return true;
            return false;
        };  
        while(L<=R){
            int mid = (L+R)/2;
            if(check(mid)){
                R=mid-1;
                ans=mid;
            }
            else L=mid+1;
        }
        return ans;
    }
};
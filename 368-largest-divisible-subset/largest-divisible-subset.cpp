class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> hash(n,-1);
        vector<int> dp(n,1); 
        for(int i =0;i<n;i++){
            hash[i]=i;
            for(int j =i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        hash[i]=j;
                        dp[i]=dp[j]+1;
                    }
                }
            }
        }
        int L =-1; int ans =0;
        for(int i =n-1;i>=0;i--){
            if(dp[i]>ans){
                ans=dp[i];
                L=i;
            }
        }
        vector<int> a;
        a.push_back(nums[L]);
        while(hash[L]!=L){
            L=hash[L];
            a.push_back(nums[L]);
        }
        return a;
    }
};
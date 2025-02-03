class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i =0;i<n;i++){
            int cnt =0; int prev =-1; 
            for(int j =i;j<n;j++){
                if(nums[j]<=prev) break;
                cnt++;
                prev=nums[j];
            }
            ans=max(cnt,ans);
            prev=0x7fffffff;
            cnt=0;
            for(int j =i;j<n;j++){
                if(nums[j]>=prev) break;
                cnt++;
                prev=nums[j];
            }
            ans=max(cnt,ans);
        }
        return max(1,ans);
    }
};
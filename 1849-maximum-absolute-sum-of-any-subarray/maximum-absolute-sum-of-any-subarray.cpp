class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans =0; int sum =0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0) sum=0;
            ans=max(ans,sum);
        }
        sum=0;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>0) sum=0;
            ans=max(ans,abs(sum));
        }
        return ans;
    }
};
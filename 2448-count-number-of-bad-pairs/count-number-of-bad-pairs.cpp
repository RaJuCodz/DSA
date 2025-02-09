class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long ans =n*(n-1)/2;
        unordered_map<int,int> m;
        for(int i =0;i<nums.size();i++){
            ans-=m[nums[i]-i];
            m[nums[i]-i]++;
        }
        return ans;
    }
};
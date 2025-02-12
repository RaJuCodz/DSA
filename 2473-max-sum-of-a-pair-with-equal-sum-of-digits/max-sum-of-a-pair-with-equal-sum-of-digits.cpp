class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,multiset<int>> s; int ans =-1;
        for(auto x : nums){
            int sum =0;
            int y =x;
            while(x){
                sum+=(x%10);
                x/=10;
            }
            s[sum].insert(y);
            if(s[sum].size()>1){
                int z = *s[sum].rbegin();
                s[sum].erase(s[sum].find(z));
                ans=max(ans,z+*s[sum].rbegin());
                s[sum].insert(z);
            }
        }
        // for(auto x)
        return ans;
    }
};
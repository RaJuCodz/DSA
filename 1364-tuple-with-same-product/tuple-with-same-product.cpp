class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(auto x: nums){
            for(auto y : nums){
                if(x==y) continue;
                m[x*y]++;
            }
        }
        int ans =0;
        for(auto x : m){
            // cout<<x.second;
            ans+=4*(x.second/2-1)*x.second/2;
        }
        return ans;
    }
};
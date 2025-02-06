class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x: nums){
            for(auto y : nums){
                if(x==y) continue;
                m[x*y]++;
            }
        }
        int ans =0;
        for(auto &x : m){
            int Z = x.second/2;
            ans+=4*(Z-1)*Z;
        }
        return ans;
    }
};
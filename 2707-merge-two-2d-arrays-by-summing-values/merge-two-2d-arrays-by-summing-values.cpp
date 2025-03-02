class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> m;
        int maxi=0;
        for(auto x : nums1){
            m[x[0]]+=x[1];
            maxi=max(x[0],maxi);
        }
        for(auto x : nums2){
            m[x[0]]+=x[1];
             maxi=max(x[0],maxi);
        }
        vector<vector<int>> ans;
        for(auto x :m){
            ans.push_back({x.first,x.second});
        }
        return ans;

    }
};
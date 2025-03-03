class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a;
        a.reserve(nums.size());
        vector<int> b;
        int cnt =0;
        for(auto x : nums){
            if(x<pivot) a.push_back(x);
            else if(x>pivot) b.push_back(x);
            else cnt++;
        }
        while(cnt--) a.push_back(pivot);
        for(auto x : b) a.push_back(x);
        return a;
    }
};
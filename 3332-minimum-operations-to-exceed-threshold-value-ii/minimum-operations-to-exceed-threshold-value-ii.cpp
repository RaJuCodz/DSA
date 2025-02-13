class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> s(nums.begin(),nums.end());
        int ans =0;
        while(*s.begin()<k){
            long long x = *s.begin();
            s.erase(s.find(x));
            long long y = *s.begin();
            s.erase(s.find(y));
            s.insert((long long)min(x,y)*2+max(x,y));
            ++ans;
        }
        return ans;
    }
};
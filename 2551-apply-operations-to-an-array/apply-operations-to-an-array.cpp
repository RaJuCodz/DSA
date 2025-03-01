class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
            
            bool ok = false;
            for(int i =0;i<n-1;i++){
                if(nums[i]==nums[i+1]){
                    nums[i]*=2;
                    nums[i+1]=0;
                    ok = true;
                }
            }
            
            
        
                int cnt =0;
                for(auto x : nums){
                    if(x==0) cnt++;
                }
                vector<int> ans;
                int x =0;
                for(int i =0;i<n-cnt;i++){
                    while(nums[x]==0) {
                        x++;
                    }
                    ans.push_back(nums[x++]);
                }
                while(cnt--){
                    ans.push_back(0);
                }
                return ans;
    }
};
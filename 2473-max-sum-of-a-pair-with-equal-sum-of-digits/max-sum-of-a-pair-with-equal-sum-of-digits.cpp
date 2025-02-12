class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,int> s; int ans =-1;
        for(auto x : nums){
            int sum =0;
            int y =x;
            while(x){
                sum+=(x%10);
                x/=10;
            }
           
            if(s.count(sum)){
                ans=max(ans,y+s[sum]);
                s[sum]=max(s[sum],y);
            }
            else s[sum]=y;
        }
        // for(auto x)
        return ans;
    }
};
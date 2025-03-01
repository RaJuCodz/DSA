class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans =0; int n =a.size();
        for(int i =0;i<n-1;i++){
            ans+=max(0,a[i+1]-a[i]);
        }
        return ans;
    }
};
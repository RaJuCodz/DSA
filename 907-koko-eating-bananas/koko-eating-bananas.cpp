typedef long long ll;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int k) {
        auto f =[&](ll val){
            ll op =0;
            for(auto x : piles){
                op+=(x+val-1)/val;
            }
            return op<=k;
        };
        int l =1; int h = 1e9; int ans =0;
        while(l<=h){
            ll mid = (l+h)/2;
            if(f(mid)) {ans=mid; h=mid-1;}
            else l=mid+1;
        }
        return ans;
    }
};
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans =0;
        long long L =1; long long R = 1e15;
        auto f =[&](long long mid){
            long long car =0;
            for(auto x : ranks){
                car+=sqrt(mid/x);
            }
            return car>=cars;
        };
        while(L<=R){
            long long mid = (L+R)/2;
            if(f(mid)){
                ans=mid;
                R=mid-1;
            }
            else L=mid+1;
        }
        return ans;
    }
};
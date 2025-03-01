class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int oneb =0,twob=0,ones=1e9,twos=1e9;
        for(auto x : a){
            ones=min(ones,x);
            oneb = max(oneb,x-ones);
            twos = min(twos,x-oneb);
            twob = max(twob,x-twos);
            
        }
        return twob;
    }
};
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> a; int ans =0;
        int cnt0=0;
        int cnt1=0;
        for(auto  x: s){
            if(x=='1'){
                if(cnt0){
                    a.push_back(cnt0);
                }
                cnt0=0;
                cnt1++;
            }
             if(x=='0'){
                if(cnt1){
                    a.push_back(cnt1);
                }
                cnt1=0;
                cnt0++;
            }
        }
        if(cnt1){
            a.push_back(cnt1);
        }
        if(cnt0){
            a.push_back(cnt0);
        }
    
        for(int i =0;i<a.size()-1;i++){
            int x = min(a[i],a[i+1]);
            ans+=x;
        }
        return ans;
        
    }
};
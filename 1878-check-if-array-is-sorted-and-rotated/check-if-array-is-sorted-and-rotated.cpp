class Solution {
public:
    bool check(vector<int>& a) {
        int n =a.size(); int c =0;
        int ind =0;
        for(int i =0;i<n-1;i++){
            if(a[i]>a[i+1]){
                c++;
                if(a[0]<a[n-1]) return false;
            }
        }
        if(c>1) return false;
        
        return true;
    }
};
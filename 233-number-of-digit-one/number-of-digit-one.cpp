typedef long long ll;
class Solution {
public:
    ll dp[11][2][11];
    string R;
    ll rec(int i , int tight, int cnt){
        if(i==R.size()) return cnt;
        if(dp[i][tight][cnt]!=-1) return dp[i][tight][cnt];
        int limit = (tight==1? R[i]-'0':9);
        ll ans =0;
        for(int j = 0;j<=limit;j++){
            ll upcnt =cnt+ (j==1);
            if(tight){
                if(j==limit) ans+=rec(i+1,1,upcnt);
                else ans+=rec(i+1,0,upcnt);
            }
            else{
                 ans+=rec(i+1,0,upcnt);
            }
           
        }
        return dp[i][tight][cnt]=ans;
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        R=to_string(n);
        return rec(0,1,0);
    }
};
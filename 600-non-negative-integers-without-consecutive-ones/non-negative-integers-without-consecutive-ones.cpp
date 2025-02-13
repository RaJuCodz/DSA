class Solution {
public:
    int dp[32][2][3];
    string s;
    int rec(int i , int t , int prev){
        if(i==s.size()) return 1;
        if(dp[i][t][prev]!=-1) return dp[i][t][prev];
        int ans =0;
        int limit = (t==1)?s[i]-'0':1;
        for(int j=0;j<=limit;j++){
            if(j==1 && prev==1) continue;
            if(t==1){
                if(j==limit){
                    ans+= rec(i+1,1,j);
                }
                else ans+=rec(i+1,0,j);
            }
            else{
                ans+=rec(i+1,0,j);
            }   
        }
        return dp[i][t][prev]=ans;
    }
    int findIntegers(int n) {
        bitset<31> A(n);
        s=A.to_string();
        memset(dp,-1,sizeof(dp));
        return rec(0,1,2);
    }
};
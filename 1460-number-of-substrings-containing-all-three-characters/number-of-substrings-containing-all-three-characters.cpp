class Solution {
public:
    int numberOfSubstrings(string s) {
            int n = s.size();
           vector<vector<int>> dp(n,vector<int> (3));
           dp[0][s[0]-'a']++;
           for(int i =1;i<n;i++){
                dp[i]=dp[i-1];
                dp[i][s[i]-'a']++;
           }
           
           int ans =0;
           for(int i =0;i<n;i++){
                int L =i+2;
                int R =n-1;
                int X =n;
                while(L<=R){
                    int mid = (L+R)/2;
                    bool ok=true;
                    int o =0;
                    for(int x=0;x<3;x++){
                        int z = (i>0)?dp[i-1][x]:0;
                        o+=min(1,dp[mid][x]-z);
                    }
                    if(o>=3){
                        R=mid-1;
                        X=mid;
                    }
                    else{
                        L=mid+1;
                    }
                }
                ans+=(n-X);
           }
           return ans;
    }
};
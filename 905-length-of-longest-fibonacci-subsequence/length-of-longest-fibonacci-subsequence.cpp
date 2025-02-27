class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int dp[1001][1001]; 
        for(int i =0;i<1001;i++){
            for(int j =0;j<1001;j++) dp[i][j]=2;
        }
        int ans =0;
        map<int,int> m; int n = arr.size();
        for(int i =0;i<n;i++) m[arr[i]]=i;
        for(int i =0;i<n-1;i++){
            for(int j =i+1;j<n;j++){
                int s = arr[i];
                int t = arr[j];
                int f = t-s;
                if(f>=s) break;
                if(m.count(f)){
                    dp[i][j]=dp[m[f]][i]+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans>2? ans : 0;

    }
};
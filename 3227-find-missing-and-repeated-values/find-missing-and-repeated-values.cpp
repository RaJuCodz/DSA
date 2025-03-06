class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n  =grid.size();
        vector<int> f((n*n)+1);
        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid.size();j++){
                f[grid[i][j]]++;
            }
        }
        vector<int> ans(2);
        for(int i =1;i<=n*n;i++){
            if(f[i]>1) ans[0]=i;
            if(!f[i]) ans[1]=i;
        }
        return ans;
    }
};
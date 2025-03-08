class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int f = 0;
        for(int i = 0;i<k;i++){
            if(blocks[i]=='B') f++;
        }
        int n = blocks.size();
        if(f==k) return 0;
        int ans = k - f;
        for(int i = k;i<n;i++){
            if(blocks[i]=='B') f++;
            if(blocks[i-k]=='B') f--;
            ans = min(ans,k-f);
            
        }
        return ans;
    }
};
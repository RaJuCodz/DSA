class Solution {
public:
    int ans = 0;
    void rec(vector<int> &fr) {
        for (int i = 0; i < 26; ++i) {
            if (fr[i] == 0) continue;
            fr[i]--;  
            ans++;
            rec(fr); 
            fr[i]++;  
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> fr(26, 0);
        for (char x : tiles) fr[x - 'A']++; 
        rec(fr);
        return ans;
    }
};

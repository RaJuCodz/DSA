class Solution {
public:
    int n;
    vector<vector<int>> g;
    vector<vector<int>> components;
    vector<bool> vis;
    vector<int> size;
    
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    
    bool valid(int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;
    }
    
    void dfs(int r, int c, int cval) {
        components[r][c] = cval;
        ++size[cval];
        
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            if (valid(nr, nc) && g[nr][nc] == 1 && components[nr][nc] == -1) {
                dfs(nr, nc, cval);
            }
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        g = grid;
        
        components = vector<vector<int>>(n, vector<int>(n, -1));
        size = vector<int>(n * n);
        vis = vector<bool>(n * n);
        
        int ans = 0;
        
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 1 && components[i][j] == -1) {
                    dfs(i, j, c);
                    ans = max(ans, size[c]);
                    c++;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 0) {
                    vector<int> comps;
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dr[d];
                        int nj = j + dc[d];
                        
                        if (valid(ni, nj) && g[ni][nj] == 1) {
                            comps.push_back(components[ni][nj]);
                        }
                    }
                    
                    int tot = 1;
                    for (int x: comps) {
                        if (!vis[x]) {
                            vis[x] = 1;
                            tot += size[x];
                        }
                    }
                    
                    ans = max(ans, tot);
                    
                    for (int x: comps) {
                        vis[x] = 0;
                    }
                }
            }
        }
        
        return ans;
    }
};
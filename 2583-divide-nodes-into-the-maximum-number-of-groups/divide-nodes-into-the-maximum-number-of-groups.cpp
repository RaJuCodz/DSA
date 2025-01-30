class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& e) {
        vector<vector<int>> g(n + 1);
        for (auto& x : e) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }

        vector<bool> v(n + 1, false);
        vector<vector<int>> c;

        function<void(int, vector<int>&)> dfs = [&](int u, vector<int>& t) {
            v[u] = true;
            t.push_back(u);
            for (int w : g[u]) {
                if (!v[w]) dfs(w, t);
            }
        };

        for (int i = 1; i <= n; ++i) {
            if (!v[i]) {
                vector<int> t;
                dfs(i, t);
                c.push_back(t);
            }
        }

        int r = 0;
        for (auto& t : c) {
            int mg = 0;
            bool b = true;
            for (int s : t) {
                queue<int> q;
                q.push(s);
                vector<int> d(n + 1, -1);
                d[s] = 0;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int w : g[u]) {
                        if (d[w] == -1) {
                            d[w] = d[u] + 1;
                            q.push(w);
                        } else if (abs(d[w] - d[u]) != 1) {
                            b = false;
                        }
                    }
                }
                mg = max(mg, *max_element(d.begin(), d.end()));
            }
            if (!b) return -1;
            r += mg + 1;
        }

        return r;
    }
};
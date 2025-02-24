class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        map<int, vector<int>> adj;
        vector<int> par(n, -1), time(n, -1), leaf(n, 0);
        
        for (auto& v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);  
        }
        queue<int> pq;
        pq.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;

        while (!pq.empty()) {
            int node = pq.front();
            pq.pop();
            for (auto v : adj[node]) {
                if (!visited[v]) {
                    visited[v] = true;
                    par[v] = node;  
                    pq.push(v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1 && i != 0) 
                leaf[i] = 1;
        }
        
        int t = 0, bobStart = bob;
        while (bob != -1) {
            time[bob] = t++;
            bob = par[bob];
        }

        queue<array<int, 3>> q;
        q.push({0, amount[0], 0});
        int ans = INT_MIN;
        fill(visited.begin(), visited.end(), false);
        visited[0] = true;

        while (!q.empty()) {
            auto [node, wealth, t] = q.front();
            q.pop();

            if (leaf[node]) {
                ans = max(ans, wealth);
            }

            for (auto v : adj[node]) {
                if (!visited[v]) {
                    visited[v] = true;
                    if (time[v] == -1) {
                        q.push({v, wealth + amount[v], t + 1});
                    } else if (t + 1 == time[v]) {
                        q.push({v, wealth + amount[v] / 2, t + 1});
                    } else if (t + 1 < time[v]) {
                        q.push({v, wealth + amount[v], t + 1});
                    } else {
                        q.push({v, wealth, t + 1});
                    }
                }
            }
        }
        return ans;
    }
};

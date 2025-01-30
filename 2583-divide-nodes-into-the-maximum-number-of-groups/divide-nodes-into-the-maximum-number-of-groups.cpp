#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n + 1, false);
        vector<vector<int>> components; 
        function<void(int, vector<int>&)> dfs = [&](int node, vector<int>& component) {
            visited[node] = true;
            component.push_back(node);
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, component);
                }
            }
        };
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, component);
                components.push_back(component);
            }
        }
        int result = 0;
        for (auto& component : components) {
            int maxGroups = 0;
            bool isBipartite = true;
            vector<int> color(n + 1, -1); 

            for (int startNode : component) {
                queue<int> q;
                q.push(startNode);
                vector<int> distance(n + 1, -1);
                distance[startNode] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if (distance[neighbor] == -1) {
                            distance[neighbor] = distance[node] + 1;
                            q.push(neighbor);
                        } else if (abs(distance[neighbor] - distance[node]) != 1) {
                            isBipartite = false;
                        }
                    }
                }

                maxGroups = max(maxGroups, *max_element(distance.begin(), distance.end()));
            }

            if (!isBipartite) return -1; 
            result += maxGroups + 1; 
        }

        return result;
    }
};
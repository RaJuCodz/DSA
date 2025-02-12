class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false; 
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<int>> vis(x + 1, vector<int>(y + 1, 0));
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [X, Y] = q.front();
            q.pop();

            if (X == target || Y == target || X + Y == target) return true;

            vector<pair<int, int>> nextStates = {
                {x, Y},    
                {X, y},    
                {0, Y},    
                {X, 0},    
                {max(0, X - (y - Y)), min(y, X + Y)},  
                {min(x, X + Y), max(0, Y - (x - X))}   
            };

            for (auto [newX, newY] : nextStates) {
                if (!vis[newX][newY]) {
                    vis[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }
        return false;
    }
};

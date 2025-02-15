class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            int X = i * i;
            string s = to_string(X);
            int len = s.size();
            queue<pair<int, int>> q;
            q.push({0, 0});  
            bool valid = false;
            
            while (!q.empty() && !valid) {
                int sz = q.size();
                for (int j = 0; j < sz; j++) {
                    auto [index, curSum] = q.front();
                    q.pop();
                    
                    if (index == len) {
                        if (curSum == i) {
                            valid = true;
                            break;
                        }
                        continue;
                    }
                    
                    int num = 0;
                    for (int k = index; k < len; k++) {
                        num = num * 10 + (s[k] - '0');  
                        if (curSum + num > i) break;    
                        q.push({k + 1, curSum + num});  
                    }
                }
            }
            
            if (valid) ans += X;
        }
        return ans;
    }
};

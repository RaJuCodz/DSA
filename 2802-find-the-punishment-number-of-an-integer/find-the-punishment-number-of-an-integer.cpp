class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;        
        for (int i = 1; i <= n; i++) {
            int X = i * i;
            string s = to_string(X);
            int len = s.size();
            stack<pair<int, int>> st;
            st.push({0, 0});  
            bool valid = false;
            while (!st.empty() && !valid) {
                int sz = st.size();
                
                    auto [index, curSum] = st.top();
                    st.pop();                    
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
                        st.push({k + 1, curSum + num});  
                    }
                
            }
            if (valid) ans += X;
        }
        return ans;
    }
};

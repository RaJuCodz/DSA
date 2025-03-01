class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        for (string &word : words) {
            int maxChain = 1;
            for (int i = 0; i < word.size(); i++) {
                string pred = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(pred)) {
                    maxChain = max(maxChain, dp[pred] + 1);
                }
            }
            dp[word] = maxChain;
            ans = max(ans, maxChain);
        }

        return ans;
    }
};

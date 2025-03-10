class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<vector<int>> f(n, vector<int>(5, 0));
        vector<int> g(n, 0);
        set<char> vow = {'a', 'e', 'i', 'o', 'u'};
        map<char, int> Z;
        int y = 0;
        for (auto x : vow) {
            Z[x] = y++;
        }
        if (vow.count(word[0])) {
            f[0][Z[word[0]]]++;
        } else {
            g[0] = 1;
        }
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1];
            g[i] = g[i - 1];
            if (vow.count(word[i])) {
                f[i][Z[word[i]]]++;
            } else {
                g[i]++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int base = (i > 0 ? g[i - 1] : 0);
            int need = base + k;
            int pos = lower_bound(g.begin() + i, g.end(), need) - g.begin();
            if (pos == n || g[pos] != need)
                continue;
            int pos2 = upper_bound(g.begin() + i, g.end(), need) - g.begin() - 1;
            int L = pos, R = pos2, validStart = -1;
            while (L <= R) {
                int mid = (L + R) / 2;
                bool hasAll = true;
                for (int v = 0; v < 5; v++) {
                    int countV = f[mid][v] - (i > 0 ? f[i - 1][v] : 0);
                    if (countV < 1) {
                        hasAll = false;
                        break;
                    }
                }
                if (hasAll) {
                    validStart = mid;
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            }
            if (validStart != -1) {
                ans += (pos2 - validStart + 1);
            }
        }
        return ans;
    }
};

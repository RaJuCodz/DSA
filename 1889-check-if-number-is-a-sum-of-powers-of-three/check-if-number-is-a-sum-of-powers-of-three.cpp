class Solution {
public:
    int fastPow(int a, int b) {
        int res = 1;
        while (b) {
            if (b % 2) res *= a;
            a *= a;
            b /= 2;
        }
        return res;
    }

    bool checkPowersOfThree(int n) {
        set<int> m;
        m.insert(0); 
        for (int i = 0; i <= 15; i++) {
            set<int> temp(m); 
            int L =fastPow(3, i);
            if(L>n) break;
            for (int x : temp) {
                long long z =x+L ;
                if(z>n) break;
                m.insert(z);
            }
        }
        return m.count(n);
    }
};

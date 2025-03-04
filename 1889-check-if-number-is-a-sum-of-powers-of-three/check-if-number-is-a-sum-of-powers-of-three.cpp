class Solution {
public:
    bool checkPowersOfThree(int n) {
        set<int> m;
        m.insert(0); m.insert(1); 
        long long a =1;
        for (int i = 0; i <= 15; i++) {
            set<int> temp(m); 
            a*=3;
             if(a>n) break;
            for (int x : temp) {
                long long z =x+a ;
                if(z>n) break;
                m.insert(z);
            }
        }
        return m.count(n);
    }
};

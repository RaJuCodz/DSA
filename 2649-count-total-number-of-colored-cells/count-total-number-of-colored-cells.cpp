class Solution {
public:
    long long coloredCells(int n) {
        // 1 5 13 25
        // +4 + 8 +12;
        long long ans =1;
        n--;
        long long X=4;
        while(n--){
            ans+=(X);
            X=X+4;
        }
        return ans;
    }
};
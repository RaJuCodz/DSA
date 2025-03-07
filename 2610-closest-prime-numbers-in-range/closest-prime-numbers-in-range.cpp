class Solution {
public:
    vector<int> sieve(int n,int left) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = left; i <= n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
    
        return primes;
}
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2,-1);
        vector<int> p = sieve(right,left);
        int n = p.size();
        int dis = 1e9;
        for(int i =0;i<n-1;i++){
            if(p[i+1]-p[i]<dis){
                ans[0]=p[i];
                ans[1]=p[i+1];
                dis=p[i+1]-p[i];
            }
        }
        return ans;
    }
};
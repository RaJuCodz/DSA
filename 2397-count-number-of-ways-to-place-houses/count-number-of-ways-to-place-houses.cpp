#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int> pq;
typedef priority_queue<int, vector<int>, greater<int>> pqg;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define repr(i, a, b) for(int i = a; i >= b; --i)
#define deb(x) cout << #x << " = " << x << endl;
#define INF 1e9
#define LINF 1e18
#define MOD 1000000007
#define MOD2 998244353
// int rec(int i ,int prev){
//     if(i==1) return 4;
    
// }
class Solution {
public:
    int countHousePlacements(int n) {
        int dp[n+1][4];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        // if(n==1) return 4;
        for(int i =1;i<=n;i++){
           for(int j =0;j<4;j++){
               for(int k =0;k<4;k++){
                   if(j&k){
                       continue;
                   }
                   dp[i][k] = (dp[i][k] + dp[i-1][j])%MOD;
               }
           }
        }
        ll ans =0;
        for(int i =0;i<4;i++){
            ans= (ans + dp[n][i])%MOD;
        }
        return ans;
        
    }
};
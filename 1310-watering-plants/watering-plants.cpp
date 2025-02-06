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
class Solution {
public:
    int wateringPlants(vector<int>& p, int c) {
        int n = p.size();
        int cur = c;
        int steps=0;
        for(int i =0;i<n;i++){
            if(cur>p[i]){
                steps++;
                cur-=p[i];
            }
            else if(cur==p[i]){
                cur=0;
                steps++;
            }
            else{
                // steps++;
                   steps+=(2*i+1);
                // cout<<(2*i+1)<<endl;
                cur=c-p[i];
            }
            cout<<steps<<" ";
            
        }
        return steps;
    }
};
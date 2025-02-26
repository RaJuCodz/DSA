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
// #define endl '\n'
 
ll min(ll a, int b) { return (a < b) ? a : b; }
ll min(int a, ll b) { return (a < b) ? a : b; }
ll max(ll a, int b) { return (a > b) ? a : b; }
ll max(int a, ll b) { return (a > b) ? a : b; }
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }
bool prime(ll a) { if (a == 1) return false; for (int i = 2; i <= sqrt(a); ++i) if (a % i == 0) return false; return true; }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
 
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
 
template<typename T>
void print_vector(const vector<T>& v) {
    for(const auto& i : v) cout << i << " ";
    cout << endl;
}
 
template<typename T>
void print_set(const set<T>& s) {
    for(const auto& i : s) cout << i << " ";
    cout << endl;
}
 
template<typename T1, typename T2>
void print_map(const map<T1, T2>& m) {
    for(const auto& p : m) cout << p.fi << ": " << p.se << endl;
}
 
template<typename T1, typename T2>
void print_pair(const pair<T1, T2>& p) {
    cout << "(" << p.fi << ", " << p.se << ")";
}
 
vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}
 
ll power(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b % 2) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}
class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& pts, int k) {
        int n = pts.size();
        vector<ll> pos;
        for (auto &p : pts) {
            int x = p[0], y = p[1];
            ll t;
            if (y == 0) t = x;
            else if (x == side) t = side + y;
            else if (y == side) t = 2LL * side + (side - x);
            else t = 3LL * side + (side - y);
            pos.push_back(t);
        }
       
        sort(pos.begin(), pos.end());
         // print_vector(pos);
        int m = pos.size();
        auto f = [&](ll d) -> bool {
            for (int i = 0; i < m; i++) {
                int cnt = 1;
                ll first = pos[i];  ll last = pos[i];
                int j = i;
                while (cnt < k) {
                    auto it = lower_bound(pos.begin() + j + 1, pos.end(), last + d);
                    if (it == pos.end()) break;
                    last = *it;
                    // cout<<*it<<" ";
                    cnt++;
                    j = it - pos.begin();
                }
                // cout<<last<<" ";
                if (cnt >= k && (pos[i] + 4LL * side - last) >= d)
                    return true;
            }
            return false;
        };
        
        ll lo = 0, hi = 2LL * side, ans = 0;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (f(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return (int)ans;
    }
};
 
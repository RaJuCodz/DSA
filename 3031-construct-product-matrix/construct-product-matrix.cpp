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
#define endl '\n'

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

// Define MOD as a constexpr variable
constexpr int MOD = 12345;

ll power(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b % 2) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

// MINT class for modular arithmetic
template<int MOD>
class MINT {
public:
    long long val;

    MINT(long long v = 0) {
        val = v % MOD;
        if (val < 0) val += MOD;
    }

    MINT& operator+=(const MINT& other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    MINT& operator-=(const MINT& other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    MINT& operator*=(const MINT& other) {
        val = (val * other.val) % MOD;
        return *this;
    }

    MINT& operator/=(const MINT& other) {
        *this *= other.inv();
        return *this;
    }

    MINT operator+(const MINT& other) const {
        MINT res = *this;
        res += other;
        return res;
    }

    MINT operator-(const MINT& other) const {
        MINT res = *this;
        res -= other;
        return res;
    }

    MINT operator*(const MINT& other) const {
        MINT res = *this;
        res *= other;
        return res;
    }

    MINT operator/(const MINT& other) const {
        MINT res = *this;
        res /= other;
        return res;
    }

    MINT operator-() const {
        return MINT(-val);
    }

    bool operator==(const MINT& other) const {
        return val == other.val;
    }

    bool operator!=(const MINT& other) const {
        return val != other.val;
    }

    MINT pow(long long p) const {
        MINT res = 1;
        MINT a = *this;
        while (p > 0) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }

    MINT inv() const {
        return pow(MOD - 2);
    }

    friend ostream& operator<<(ostream& os, const MINT& m) {
        return os << m.val;
    }

    friend istream& operator>>(istream& is, MINT& m) {
        long long x;
        is >> x;
        m = MINT(x);
        return is;
    }
};

using mint = MINT<MOD>;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<long long> rows, pref_r{1}, suf_r{1};
        for (const auto &r : g)
            rows.push_back(accumulate(begin(r), end(r), 1LL, [](long long res, int v){
                return (res * v) % 12345;
            }));
        for (int i = 0; i < g.size(); ++i) {
            pref_r.push_back(pref_r.back() * rows[i] % 12345);
            suf_r.push_back(suf_r.back() * rows[m - i - 1] % 12345);
        }
        for (int i = 0; i < g.size(); ++i) {
            vector<long long> pref{1}, suf{1};
            for (int j = 0; j < g[i].size(); ++j) {
                pref.push_back(pref.back() * g[i][j] % 12345);
                suf.push_back(suf.back() * g[i][n - j - 1] % 12345);
            }
            for (int j = 0; j < n; ++j)
                g[i][j] = pref_r[i] * suf_r[m - i - 1] * pref[j]* suf[n - j - 1] % 12345;
        }
        return g;
    }
    
};
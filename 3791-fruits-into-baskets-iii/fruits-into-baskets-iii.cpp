#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long ll;
typedef vector<int> vi;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
struct segtree {
    int sz;
    vector<int> tree;
    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        tree.assign(2 * sz, 0);
    }
    int merge(int a, int b) {
        return max(a, b);
    }
    void build(vector<int>& a, int x, int l, int r) {
        if (r - l == 1) {
            if (l < (int)a.size())
                tree[x] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * x + 1, l, mid);
        build(a, 2 * x + 2, mid, r);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void build(vector<int>& a) {
        init(a.size());
        build(a, 0, 0, sz);
    }
    void set(int i, int v, int x, int l, int r) {
        if (r - l == 1) {
            tree[x] = v;
            return;
        }
        int mid = (l + r) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, l, mid);
        else
            set(i, v, 2 * x + 2, mid, r);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }
    
    void set(int i, int v) {
        set(i, v, 0, 0, sz);
    }
    int findLeftmost(int required, int x, int lx, int rx) {
        if (rx - lx == 1)
            return lx;
        int mid = (lx + rx) / 2;
        if (tree[2 * x + 1] >= required)
            return findLeftmost(required, 2 * x + 1, lx, mid);
        else
            return findLeftmost(required, 2 * x + 2, mid, rx);
    }
    int findLeftmost(int required) {
        if (tree[0] < required)
            return -1;
        return findLeftmost(required, 0, 0, sz);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segtree st;
        st.build(baskets);
        int unplaced = 0;
        for (int i = 0; i < n; i++) {
            int fruitQty = fruits[i];
            if (st.tree[0] < fruitQty) {
                unplaced++;
            } else {
                int basketIndex = st.findLeftmost(fruitQty);
                st.set(basketIndex, 0);
            }
        }
        return unplaced;
    }
};

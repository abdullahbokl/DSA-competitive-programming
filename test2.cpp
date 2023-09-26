// 7oSkaaa
// https://codeforces.com/contest/1878/problem/E

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> RET = {"NO", "YES"};

template <typename T = int>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x;
    return in;
}

template <typename T = int>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (const T& x : v) out << x << ' ';
    return out;
}

template <typename T = int, int Base = 0>
struct Segment_Tree {
    struct Node {
        T val;

        Node(T V = 0) : val(V) {}

        Node operator=(const T rhs) {
            val = rhs;
            return *this;
        }
    };

    int size;
    Node DEFAULT;
    vector<Node> tree;
#define LEFT (idx << 1)
#define RIGHT ((idx << 1) | 1)
#define VAL val

    Segment_Tree(int n = 0) {
        size = 1, DEFAULT = -1;
        while (size < n) size *= 2;
        tree = vector<Node>(2 * size, DEFAULT);
    }

    Segment_Tree(int n, const vector<T>& nums) {
        size = 1, DEFAULT = -1;
        while (size < n) size *= 2;
        tree = vector<Node>(2 * size, DEFAULT);
        build(nums);
    }

    // Main operation to do

    Node operation(const Node& a, const Node& b) { return Node(a.VAL & b.VAL); }

    // If Base is 1 so the array is 1-based else the array is 0-based

    void build(const vector<T>& nums, int idx, int lx, int rx) {
        if (Base ? lx >= sz(nums) : lx > sz(nums)) return;
        if (rx == lx)
            tree[idx] = nums[lx - !Base];
        else {
            int mx = (rx + lx) / 2;
            build(nums, LEFT, lx, mx);
            build(nums, RIGHT, mx + 1, rx);
            tree[idx] = operation(tree[LEFT], tree[RIGHT]);
        }
    }

    void build(const vector<T>& nums) { build(nums, 1, 1, size); }

    void update(int index, T v, int idx, int lx, int rx) {
        if (rx == lx)
            tree[idx] = v;
        else {
            int mx = (rx + lx) / 2;
            if (index <= mx)
                update(index, v, LEFT, lx, mx);
            else
                update(index, v, RIGHT, mx + 1, rx);
            tree[idx] = operation(tree[LEFT], tree[RIGHT]);
        }
    }

    void update(const int index, const T v) { update(index, v, 1, 1, size); }

    Node query(int l, int r, int idx, int lx, int rx) {
        if (lx > r || l > rx) return DEFAULT;
        if (lx >= l && rx <= r) return tree[idx];
        int mx = (lx + rx) / 2;
        return operation(query(l, r, LEFT, lx, mx),
                         query(l, r, RIGHT, mx + 1, rx));
    }

    Node query_Node(const int l, const int r) {
        return query(l, r, 1, 1, size);
    }

    T query(const int l, const int r) { return query_Node(l, r).VAL; }

    T get(const int idx) { return query_Node(idx, idx).VAL; }

    friend ostream& operator<<(ostream& out, const Node& node) {
        out << node.VAL << ' ';
        return out;
    }

    void print(int idx, int lx, int rx) {
        if (lx == rx)
            cout << tree[idx] << ' ';
        else {
            int mx = (lx + rx) / 2;
            print(LEFT, lx, mx);
            print(RIGHT, mx + 1, rx);
        }
    }

    void print() {
        print(1, 1, size);
        cout << '\n';
    }

// remove macro LEFT and RIGHT
#undef LEFT
#undef RIGHT
#undef VAL
};

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    Segment_Tree<int> st(n, a);
    int q;
    cin >> q;
    while (q--) {
        int l, k;
        cin >> l >> k;
        int lx = l, rx = n, ans = -1;
        while (lx <= rx) {
            int mx = lx + (rx - lx) / 2;
            (st.query(l, mx) >= k ? lx = mx + 1, ans = mx : rx = mx - 1);
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        Solve();
    }
    return 0;
}
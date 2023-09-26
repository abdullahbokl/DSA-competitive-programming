
// C. Vasilije in Cacak
// https://codeforces.com/contest/1878/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> RET = {"NO", "YES"};

void Solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    auto sum = [&](ll l, ll r) {
        return (r * (r + 1) / 2) - (l * (l - 1) / 2);
    };
    bool is_between = true;
    if (x > sum(n - k + 1, n)) is_between = false;
    if (x < sum(1, k)) is_between = false;
    cout << RET[is_between] << '\n';
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




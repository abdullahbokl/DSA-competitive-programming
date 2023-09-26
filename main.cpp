#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define cin(vec) \
    for (auto &i : (vec)) cin >> i;
#define cout(vec) \
    for (auto &i : (vec)) cout << i << ' ';
enum Dir { RIGHT, DOWN, LEFT, UP };
int dir_r[] = {0, 1, 0, -1};
int dir_c[] = {1, 0, -1, 0};
int matrixMax = 1e3 + 7;
int MAX = 1e5 + 1;

void boklFastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void coutMatrix(vector<vector<int>> &matrix) {
    for (auto &i : matrix) {
        for (auto &j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}
//*****CODE*****************************************

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    // Vasilije is given three positive integers: n, k, and x, and he has to
    // determine if he can choose k distinct integers between 1 and n, such that
    // their sum is equal to x.

    int q;
}
//**********************************************
int main() {
    boklFastIO();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

// Type definitions for convenience
typedef long long ll;
typedef unsigned long long ull;

// Input/Output macros
#define cin(vec) for (auto& i : (vec)) cin >> i;
#define cout(vec) for (auto& i : (vec)) cout << i << " ";

// Constants and Global Variables
namespace Constants {
    enum Dir { RIGHT, DOWN, LEFT, UP };
    const int dir_r[] = {0, 1, 0, -1};
    const int dir_c[] = {1, 0, -1, 0};
    const int MATRIX_MAX = 1e3 + 1;
    const int MAX = 1e5 + 1;
}

// Global variables (consider converting to local variables where possible)
vector<vector<bool>> visMatrix(Constants::MATRIX_MAX, vector<bool>(Constants::MATRIX_MAX, false));
vector<bool> vis(Constants::MAX, false);

/****************************************************************************
 * I/O Optimization
 ****************************************************************************/
void optimizeIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

/****************************************************************************
 * Number Theory Operations
 ****************************************************************************/
namespace NumberTheory {
    // Greatest Common Divisor (GCD)
    ll gcd(ll a, ll b) { 
        return b == 0 ? a : gcd(b, a % b); 
    }

    ll gcdIterative(ll a, ll b) {
        while (b != 0) {
            ll r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    // Least Common Multiple (LCM)
    ll lcm(ll a, ll b) { 
        return a * (b / gcd(a, b)); 
    }

    ll lcmIterative(ll a, ll b) {
        ll ans = a;
        while (ans % b != 0) ans += a;
        return ans;
    }

    // Fast Power Operations
    ll fastPowerRecursive(ll a, ll b) {
        if (b == 0) return 1;
        if (b % 2 == 0) {
            ll x = fastPowerRecursive(a, b / 2);
            return x * x;
        }
        return a * fastPowerRecursive(a, b - 1);
    }

    ll fastPowerIterative(ll a, ll b) {
        ll ans = 1;
        while (b != 0) {
            if (b % 2 == 1) ans *= a;
            a *= a;
            b /= 2;
        }
        return ans;
    }

    // Modular Arithmetic Operations
    ll modAdd(ll a, ll b, ll m) { return (a % m + b % m) % m; }
    ll modSub(ll a, ll b, ll m) { return (a % m - b % m + m) % m; }
    ll modMul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }
    ll modNegative(ll a, ll m) {
        ll ans = a % m;
        return ans < 0 ? ans + m : ans;
    }

    ll modPow(ll base, ll exp, ll mod) {
        if (exp == 0) return 1;
        if (exp % 2 == 0) {
            ll x = modPow(base, exp / 2, mod);
            return modMul(x, x, mod);
        }
        return modMul(base, modPow(base, exp - 1, mod), mod);
    }

    ll modPowIterative(ll base, ll exp, ll mod) {
        base %= mod;
        ll ans = 1;
        while (exp > 0) {
            if (exp & 1) ans = modMul(ans, base, mod);
            base = modMul(base, base, mod);
            exp >>= 1;
        }
        return ans;
    }
}

/****************************************************************************
 * Combinatorics
 ****************************************************************************/
namespace Combinatorics {
    // Factorial Calculations
    ll factorial(ll n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }

    ll factorialIterative(ll n) {
        ll ans = 1;
        for (int i = 2; i <= n; ++i) ans *= i;
        return ans;
    }

    // Fibonacci Sequence
    template <typename T>
    T fibonacci(T n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    template <typename T>
    T fibonacciIterative(T n) {
        if (n <= 1) return n;
        T a = 0, b = 1;
        for (int i = 2; i <= n; ++i) {
            T c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

/****************************************************************************
 * Prime Numbers and Factorization
 ****************************************************************************/
namespace Primes {
    bool isPrime(ll n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0) return false;
        for (ll i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    vector<ll> primeFactors(ll n) {
        vector<ll> factors;
        while (n % 2 == 0) {
            factors.push_back(2);
            n /= 2;
        }
        for (ll i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                factors.push_back(i);
                n /= i;
            }
        }
        if (n > 2) factors.push_back(n);
        return factors;
    }

    vector<ll> sieveOfEratosthenes(ll n) {
        vector<ll> primes;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (ll i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (ll j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        for (ll i = 2; i <= n; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }
        return primes;
    }
}

/****************************************************************************
 * String Operations
 ****************************************************************************/
namespace StringOps {
    bool isPalindrome(const string& s) {
        int len = s.length();
        for (int i = 0; i * 2 < len; ++i) {
            if (s[i] != s[len - i - 1]) return false;
        }
        return true;
    }

    bool isPalindrome(ll n) {
        return isPalindrome(to_string(n));
    }

    void findPalindromicSubstrings(const string& s, int start, int size, vector<string>& result) {
        if (start >= size) return;
        for (int len = 1; len <= size - start; ++len) {
            string sub = s.substr(start, len);
            if (isPalindrome(sub)) result.push_back(sub);
        }
        findPalindromicSubstrings(s, start + 1, size, result);
    }

    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

    string toLower(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    string toUpper(string s) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    }
}

/****************************************************************************
 * Tree Operations
 ****************************************************************************/
namespace Tree {
    struct TreeNode {
        int val;
        TreeNode *left, *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }

    void preorderTraversal(TreeNode* root) {
        if (!root) return;
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    void postorderTraversal(TreeNode* root) {
        if (!root) return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->val << " ";
    }

    int treeHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        
        return abs(leftHeight - rightHeight) <= 1 && 
               isBalanced(root->left) && 
               isBalanced(root->right);
    }

    bool isBSTUtil(TreeNode* root, long long min, long long max) {
        if (!root) return true;
        
        if (root->val <= min || root->val >= max) return false;
        
        return isBSTUtil(root->left, min, root->val) && 
               isBSTUtil(root->right, root->val, max);
    }

    bool isBST(TreeNode* root) {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
}

/****************************************************************************
 * Matrix Operations
 ****************************************************************************/
namespace Matrix {
    vector<vector<int>> matrixMultiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size(), m = A[0].size(), p = B[0].size();
        vector<vector<int>> C(n, vector<int>(p, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < p; ++j) {
                for (int k = 0; k < m; ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    vector<vector<int>> matrixPower(vector<vector<int>>& A, int n) {
        int size = A.size();
        vector<vector<int>> result(size, vector<int>(size, 0));
        
        // Initialize result as identity matrix
        for (int i = 0; i < size; ++i) {
            result[i][i] = 1;
        }
        
        while (n > 0) {
            if (n & 1) {
                result = matrixMultiply(result, A);
            }
            A = matrixMultiply(A, A);
            n >>= 1;
        }
        return result;
    }

    void rotateMatrix90Degrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    vector<vector<int>> transposeMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
}

/****************************************************************************
 * Search Algorithms
 ****************************************************************************/
namespace Search {
    // Linear Search
    template<typename T>
    int linearSearch(const vector<T>& arr, const T& target) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == target) return i;
        }
        return -1;
    }

    // Binary Search
    template<typename T>
    int binarySearch(const vector<T>& arr, const T& target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    // Ternary Search
    template<typename T>
    int ternarySearch(const vector<T>& arr, const T& target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            
            if (arr[mid1] == target) return mid1;
            if (arr[mid2] == target) return mid2;
            
            if (target < arr[mid1]) right = mid1 - 1;
            else if (target > arr[mid2]) left = mid2 + 1;
            else {
                left = mid1 + 1;
                right = mid2 - 1;
            }
        }
        return -1;
    }
}

/****************************************************************************
 * Sorting Algorithms
 ****************************************************************************/
namespace Sort {
    template<typename T>
    void bubbleSort(vector<T>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    template<typename T>
    void insertionSort(vector<T>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }

    template<typename T>
    void merge(vector<T>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        
        vector<T> L(n1), R(n2);
        for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];
        
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    template<typename T>
    void mergeSort(vector<T>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
}

/****************************************************************************
 * Graph Algorithms
 ****************************************************************************/
namespace Graph {
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, visited, v);
            }
        }
    }

    void bfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void dijkstra(vector<vector<pair<int, int>>>& adj, vector<int>& dist, int start) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[start] = 0;
        pq.push({0, start});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (auto& [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    bool hasCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, 0);  // 0: unvisited, 1: visiting, 2: visited
        
        function<bool(int)> dfs = [&](int u) {
            color[u] = 1;  // Mark as visiting
            
            for (int v : adj[u]) {
                if (color[v] == 1) return true;  // Back edge found
                if (color[v] == 0 && dfs(v)) return true;
            }
            
            color[u] = 2;  // Mark as visited
            return false;
        };
        
        for (int u = 0; u < n; ++u) {
            if (color[u] == 0 && dfs(u)) {
                return true;
            }
        }
        return false;
    }
}

namespace Permutation {
    // it's a permutaion if all elements are in range [1, n] 
    bool isPermutation(vector<int>& arr) { 
        int n = arr.size();
        vector<bool> seen(n + 1, false);
        
        for (int num : arr) {
            if (num < 1 || num > n || seen[num]) return false;
            seen[num] = true;
        }
        
        return true;
    }

    vector<int> nextPermutation(vector<int>& arr) {
        int n = arr.size(), i = n - 2;
        vector<int> result = arr;
        
        // Find first decreasing element from right
        while (i >= 0 && result[i] >= result[i + 1]) --i;
        
        if (i >= 0) {
            // Find smallest element greater than arr[i]
            int j = n - 1;
            while (j >= 0 && result[j] <= result[i]) --j;
            swap(result[i], result[j]);
        }
        
        // Reverse the suffix
        reverse(result.begin() + i + 1, result.end());
        return result;
    }
}

/****************************************************************************
 * Bit Manipulation
 ****************************************************************************/
namespace BitOps {
    void printBits(ll n) {
        for (int i = 63; i >= 0; --i) {
            cout << ((n >> i) & 1);
        }
        cout << '\n';
    }

    string decimalToBinary(ll n) {
        string binary;
        while (n > 0) {
            binary = (char)('0' + (n & 1)) + binary;
            n >>= 1;
        }
        return binary;
    }

    ll binaryToDecimal(const string& s) {
        ll decimal = 0;
        for (char c : s) {
            decimal = (decimal << 1) + (c - '0');
        }
        return decimal;
    }

    bool isPowerOf2(ll n) { return n && !(n & (n - 1)); }
    bool isOdd(ll n) { return n & 1; }
    bool isEven(ll n) { return !(n & 1); }
    ll getBit(ll n, int i) { return (n >> i) & 1; }
    ll setBit1(ll n, int i) { return n | (1LL << i); }
    ll setBit0(ll n, int i) { return n & ~(1LL << i); }
    ll toggleBit(ll n, int i) { return n ^ (1LL << i); }
}

/****************************************************************************
 * Main Function
 ****************************************************************************/
void solve() {
    // Your solution code here
    cout << "Hello, World!\n";
    cout << NumberTheory::gcd(6, 9) << '\n';
}

int main() {
    optimizeIO();
    int t = 1;
    // cin >> t;  // Uncomment for multiple test cases
    while (t--) solve();
    return 0;
}

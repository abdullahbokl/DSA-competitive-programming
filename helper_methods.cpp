#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define cin(vec) \
    for (auto& i : (vec)) cin >> i;
#define cout(vec) \
    for (auto& i : (vec)) cout << i << " ";
enum Dir { RIGHT, DOWN, LEFT, UP };
int dir_r[] = {0, 1, 0, -1};
int dir_c[] = {1, 0, -1, 0};
int matrixMax = 1e3 + 1;
int MAX = 1e5 + 1;
vector<vector<bool>> visMatrix(matrixMax, vector<bool>(matrixMax, false));
vector<bool> vis(MAX, false);

/* Helper Methods */
void boklFastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

/* number theory helper functions */

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

long long gcdIter(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }

long long lcmIter(long long a, long long b) {
    long long ans = a;
    while (ans % b != 0) ans += a;
    return ans;
}

long long recursiveFastPow(long long a, long long b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        long long x = recursiveFastPow(a, b / 2);
        return x * x;
    }
    return a * recursiveFastPow(a, b - 1);
}

long long powIter(long long a, long long b) {
    long long ans = 1;
    while (b != 0) {
        if (b % 2 == 1) ans *= a;
        a *= a;
        b /= 2;
    }
    return ans;
}

long long modAdd(long long a, long long b, long long m) {
    return (a % m + b % m) % m;
}

long long modSub(long long a, long long b, long long m) {
    return (a % m - b % m + m) % m;
}

long long modMul(long long a, long long b, long long m) {
    return ((a % m) * (b % m)) % m;
}

// long long modDiv(long long a, long long b, long long m) {
//     return (a % m * modPow(b, m - 2, m)) % m;
// }

long long modNegative(long long a, long long b) {
    long long ans = a % b;
    if (ans < 0) ans += b;
    return ans;
}

long long modPow(long long base, long long exp, long long mod) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long x = modPow(base, exp / 2, mod);
        return modMul(x, x, mod);
    }
    return modMul(base, modPow(base, exp - 1, mod), mod);
}

long long modPowIter(long long base, long long exp, long long mod) {
    base %= mod;
    long long ans = 1;
    while (exp > 0) {
        if (exp & 1) ans = modMul(ans, base, mod);
        base = modMul(base, base, mod);
        exp >>= 1;
    }
    return ans;
}

/* factorial helper functions */

long long fact(long long n) {
    if (n == 0 || n == 1) return 1;
    return n * fact(n - 1);
}

long long factIter(long long n) {
    long long ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

/* fibonacci helper functions */

long long fib(long long n) {
    if (n == 0 || n == 1) return n;
    return fib(n - 1) + fib(n - 2);
}

long long fibIter(long long n) {
    if (n == 0 || n == 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

/* prime numbers helper functions */

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<long long> primeFactors(long long n) {
    vector<long long> ans;
    while (n % 2 == 0) {
        ans.push_back(2);
        n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n > 2) ans.push_back(n);
    return ans;
}

vector<long long> sieve(long long n) {
    vector<long long> ans;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (long long i = 2; i <= n; ++i) {
        if (isPrime[i]) ans.push_back(i);
    }
    return ans;
}

/* Palindrome helper functions */

bool isPalindrome(string s) {
    int len = s.length();
    for (int i = 0; i * 2 < len; ++i) {
        if (s[i] != s[len - i - 1]) return false;
    }
    return true;
}

// overloading function to accept numbers
bool isPalindrome(long long n) {
    string s = to_string(n);
    int len = s.length();
    for (int i = 0; i * 2 < len; ++i) {
        if (s[i] != s[len - i - 1]) return false;
    }
    return true;
}

/* substrings */

// print all palindromic substrings of string s
void findPalindromicSubstrings(const string& s, int start, int size,
                               vector<string>& result) {
    if (start + size > s.size()) return;
    string substring = s.substr(start, size);
    if (isPalindrome(substring)) result.push_back(substring);

    if (start + size == s.size())
        findPalindromicSubstrings(s, start + 1, 1, result);
    else
        findPalindromicSubstrings(s, start, size + 1, result);
}

/* sub-sequence helper functions */

// generate all sub-sequences of an array
void generateSubSec(int idx, vector<int>& nums, vector<int>& subSec,
                    vector<vector<int>>& subSecuences) {
    if (idx >= nums.size()) {
        subSecuences.push_back(subSec);
        return;
    }

    subSec.push_back(nums[idx]);
    generateSubSec(idx + 1, nums, subSec, subSecuences);
    subSec.pop_back();
    generateSubSec(idx + 1, nums, subSec, subSecuences);
}

// generate all sub-sequences of an array with specific sum 'targetSum'
void generateSubSecWithSum(int idx, int sum, vector<int>& nums,
                           vector<int>& subSec,
                           vector<vector<int>>& subSecuences, int targetSum) {
    if (idx >= nums.size()) {
        if (sum == targetSum) subSecuences.push_back(subSec);
        return;
    }

    subSec.push_back(nums[idx]);
    generateSubSecWithSum(idx + 1, sum + nums[idx], nums, subSec, subSecuences,
                          targetSum);
    subSec.pop_back();
    generateSubSecWithSum(idx + 1, sum, nums, subSec, subSecuences, targetSum);
}

// generate all sub-sequences of an array with specific length 'targetLength'
void generateSubSecWithLength(int idx, vector<int>& nums, vector<int>& subSec,
                              vector<vector<int>>& subSecuences,
                              int targetLength) {
    if (idx >= nums.size()) {
        if (subSec.size() == targetLength) subSecuences.push_back(subSec);
        return;
    }

    subSec.push_back(nums[idx]);
    generateSubSecWithLength(idx + 1, nums, subSec, subSecuences, targetLength);
    subSec.pop_back();
    generateSubSecWithLength(idx + 1, nums, subSec, subSecuences, targetLength);
}

// generate all sub-sequences of an array with specific length 'targetLength'
// and specific sum 'targetSum'
void generateSubSecWithLengthAndSum(int idx, int sum, vector<int>& nums,
                                    vector<int>& subSec,
                                    vector<vector<int>>& subSecuences,
                                    int targetLength, int targetSum) {
    if (idx >= nums.size()) {
        if (subSec.size() == targetLength && sum == targetSum)
            subSecuences.push_back(subSec);
        return;
    }

    subSec.push_back(nums[idx]);
    generateSubSecWithLengthAndSum(idx + 1, sum + nums[idx], nums, subSec,
                                   subSecuences, targetLength, targetSum);
    subSec.pop_back();
    generateSubSecWithLengthAndSum(idx + 1, sum, nums, subSec, subSecuences,
                                   targetLength, targetSum);
}

/* Permutation helper functions */

vector<string> permutations(string s) {
    vector<string> ans;
    sort(s.begin(), s.end());
    do {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    return ans;
}

vector<long long> permutations(long long n) {
    string s = to_string(n);
    vector<string> ans = permutations(s);
    vector<long long> ans2;
    for (auto& i : ans) {
        ans2.push_back(stoll(i));
    }
    return ans2;
}

// generate all permutations of numbers usign backtracking
void generatePermutations(int idx, vector<int>& nums,
                          vector<vector<int>>& ans) {
    if (idx >= nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); ++i) {
        swap(nums[idx], nums[i]);
        generatePermutations(idx + 1, nums, ans);
        swap(nums[idx], nums[i]);
    }
    // 1 2
    // 2 1
}

void generatePermutations(vector<int>& nums, vector<int>& temp,
                          vector<vector<int>>& ans) {
    if (temp.size() == nums.size()) {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) {
            continue;
        }
        temp.push_back(nums[i]);
        generatePermutations(nums, temp, ans);
        temp.pop_back();
    }
    // 1 2
    // 2 1
}

// calculate how many permutations will be generated from n numbers
long long permutationsCount(int n) {
    // formula: n! : used to calculate all permutations count
    long long ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

long long permutationsCount2(int n, int r) {
    // formula: n! / (n - r)! : used to calculate permutations count with length
    long long ans = 1;
    for (int i = n - r + 1; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

/* Combination helper functions */

void generateCombinations(vector<int>& nums, vector<int>& ds, int idx) {
    if (idx == nums.size()) {
        for (auto& i : ds) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    ds.push_back(nums[idx]);
    generateCombinations(nums, ds, idx + 1);
    ds.pop_back();
    generateCombinations(nums, ds, idx + 1);
    // 1 2
    // 1
    // 2
}

void generateCombinations(vector<int>& nums, vector<int>& ds) {
    if (ds.size() == nums.size()) {
        for (auto& i : ds) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        ds.push_back(nums[i]);
        generateCombinations(nums, ds);
        ds.pop_back();
    }
    // 1 1
    // 1 2
    // 2 1
    // 2 2
}

long long combinationsCount(int n, int r) {
    // formula: n! / (r! * (n - r)!) : used to calculate combinations count
    long long ans = 1;
    for (int i = n - r + 1; i <= n; ++i) {
        ans *= i;
    }
    for (int i = 2; i <= r; ++i) {
        ans /= i;
    }
    return ans;
}

/* linear search helper functions */

int linearSearch(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) return i;
    }
    return -1;
}

int linearSearchRecursive(vector<int>& nums, int target, int idx) {
    if (idx == nums.size()) return -1;
    if (nums[idx] == target) return idx;
    return linearSearchRecursive(nums, target, idx + 1);
}

/* Binary Search helper functions */

// assign mid without adding or subtracting can cause infinite loop
// if start or end = mid (e.g. 1, 2) and target = 2
// to avoid that use start + (end-start+1)/2 instead of (start+end)/2

long long binarySearch(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) return m;
        if (nums[m] < target) l = m + 1;
        if (nums[m] > target) r = m - 1;
    }
    return -1;
}

int recursiveBS(vector<int>& v, int target, int l, int r) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (v[mid] == target) return mid;
    if (v[mid] > target) return recursiveBS(v, target, l, mid - 1);
    if (v[mid] < target) return recursiveBS(v, target, mid + 1, r);
}

long long binarySearchFindFirst(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) {
            ans = m;
            r = m - 1;
        }
        if (nums[m] < target) l = m + 1;
        if (nums[m] > target) r = m - 1;
    }
    return ans;
}

long long binarySearchFindLast(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int ans = -1;
    while (l <= r) {
        // avoid infinite loop
        int m = l + (r - l + 1) / 2;
        if (nums[m] == target) {
            ans = m;
            l = m + 1;
        }
        if (nums[m] < target) l = m + 1;
        if (nums[m] > target) r = m - 1;
    }
    return ans;
}

double binarySearch(vector<double>& nums, double target) {
    double l = 0, r = nums.size() - 1;
    while (fabs(r - l) > 1e-9) {
        double m = (l + r) / 2;
        if (nums[m] == target) return m;
        if (nums[m] < target) l = m;
        if (nums[m] > target) r = m;
    }
    return -1;
}

long long binarySearchBitonic(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) return m;
        if (nums[m] < target) {
            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (nums[m] > target) {
            if (nums[m] < nums[m + 1]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    return -1;
}

/* Ternary Search helper functions */

long long ternarySearch(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (nums[m1] == target) return m1;
        if (nums[m2] == target) return m2;
        if (nums[m1] > target) r = m1 - 1;
        if (nums[m1] < target) l = m1 + 1;
        if (nums[m2] < target) l = m2 + 1;
        if (nums[m2] > target) r = m2 - 1;
    }
    return -1;
}

long long ternarySearchBitonic(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (nums[m1] == target) return m1;
        if (nums[m2] == target) return m2;
        if (nums[m1] < nums[m1 + 1]) {
            if (nums[m1] > target) r = m1 - 1;
            if (nums[m1] < target) l = m1 + 1;
        } else {
            if (nums[m1] > target) l = m1 + 1;
            if (nums[m1] < target) r = m1 - 1;
        }
        if (nums[m2] < nums[m2 + 1]) {
            if (nums[m2] > target) r = m2 - 1;
            if (nums[m2] < target) l = m2 + 1;
        } else {
            if (nums[m2] > target) l = m2 + 1;
            if (nums[m2] < target) r = m2 - 1;
        }
    }
    return -1;
}

/* Sorting helper functions */

void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[minIdx]) minIdx = j;
        }
        swap(nums[i], nums[minIdx]);
    }
}

void insertionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        int j = i - 1;
        int key = nums[i];
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
}

void mergeSort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(nums, l, m);
    mergeSort(nums, m + 1, r);
    vector<int> temp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (nums[i] < nums[j]) {
            temp.push_back(nums[i]);
            ++i;
        } else {
            temp.push_back(nums[j]);
            ++j;
        }
    }
    while (i <= m) {
        temp.push_back(nums[i]);
        ++i;
    }
    while (j <= r) {
        temp.push_back(nums[j]);
        ++j;
    }
    for (int i = l; i <= r; ++i) {
        nums[i] = temp[i - l];
    }
}

void quickSort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j < r; ++j) {
        if (nums[j] < pivot) {
            ++i;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    int p = i + 1;
    quickSort(nums, l, p - 1);
    quickSort(nums, p + 1, r);
}

void heapify(vector<int>& nums, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && nums[l] > nums[largest]) largest = l;
    if (r < n && nums[r] > nums[largest]) largest = r;
    if (largest != i) {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(nums, n, i);
    }
    for (int i = n - 1; i >= 0; --i) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

/* Graph helper functions */

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int u) {
    visited[u] = true;
    for (auto& v : adj[u]) {
        if (!visited[v]) dfs(adj, visited, v);
    }
}

void dfsIter(vector<vector<int>>& adj, vector<bool>& visited, int u) {
    stack<int> st;
    st.push(u);
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (!visited[v]) {
            visited[v] = true;
            for (auto& i : adj[v]) {
                st.push(i);
            }
        }
    }
}

void bfs(vector<vector<int>>& adj, vector<bool>& visited, int u) {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (!visited[v]) {
            visited[v] = true;
            for (auto& i : adj[v]) {
                q.push(i);
            }
        }
    }
}

void bfsIter(vector<vector<int>>& adj, vector<bool>& visited, int u) {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (!visited[v]) {
            visited[v] = true;
            for (auto& i : adj[v]) {
                q.push(i);
            }
        }
    }
}

void dijkstra(vector<vector<pair<int, int>>>& adj, vector<int>& dist, int u) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, u});
    dist[u] = 0;
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        for (auto& i : adj[v]) {
            int w = i.first;
            int weight = i.second;
            if (dist[w] > dist[v] + weight) {
                dist[w] = dist[v] + weight;
                pq.push({dist[w], w});
            }
        }
    }
}

/* summation helper functions */

long long sumOfFirstNNumbers(long long n) { return n * (n + 1) / 2; }

long long sumOfFirstNEvenNumbers(long long n) { return n * (n + 1); }

long long sumOfFirstNOddNumbers(long long n) { return n * n; }

long long oddNumberAtIndex(long long index) { return 2 * (index - 1) + 1; }

long long evenNumberAtIndex(long long index) { return 2 * index; }

long long sumOfNumbersInRange(long long l, long long r) {
    return (r - l + 1) * (l + r) / 2;
}

long long sumOfEvenNumbersInRange(long long l, long long r) {
    return (r - l + 1) * (l + r);
}

long long sumOfOddNumbersInRange(long long l, long long r) {
    return (r - l + 1) * (r + l);
}

long long sumOfSquaresOfFirstNNumbers(long long n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

long long sumOfCubesOfFirstNNumbers(long long n) {
    long long ans = n * (n + 1) / 2;
    return ans * ans;
}

vector<long long> prefixSum(vector<long long>& nums) {
    int n = nums.size();
    vector<long long> ans(n);
    ans[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        ans[i] = ans[i - 1] + nums[i];
    }
    return ans;
}

vector<long long> suffixSum(vector<long long>& nums) {
    int n = nums.size();
    vector<long long> ans(n);
    ans[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        ans[i] = ans[i + 1] + nums[i];
    }
    return ans;
}

long long partialSum(vector<long long>& nums, int l, int r) {
    vector<long long> prefix = prefixSum(nums);
    if (l == 0) return prefix[r];
    return prefix[r] - prefix[l - 1];
}

// arithmetic progression
long long sumOfArithmeticProgression(long long a, long long d, long long n) {
    return n * (2 * a + (n - 1) * d) / 2;
}

// geometric progression
long long sumOfGeometricProgression(long long a, long long r, long long n) {
    return a * (1 - recursiveFastPow(r, n)) / (1 - r);
}

/* kadane's algorithm */

long long greatestSumOfContiguousSubarray(vector<int>& nums) {
    int n = nums.size();
    long long ans = INT_MIN;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }

    if (ans == 0) {
        ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (long long)nums[i]);
        }
    }
    return ans;
}

long long leastSumOfContiguousSubarray(vector<int>& nums) {
    int n = nums.size();
    long long ans = INT_MAX;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        ans = min(ans, sum);
        if (sum > 0) sum = 0;
    }

    if (ans == 0) {
        ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, (long long)nums[i]);
        }
    }
    return ans;
}

vector<long long> greatestSubarray(vector<int>& nums) {
    int n = nums.size();
    long long ans = INT_MIN;
    long long sum = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        if (sum > ans) {
            ans = sum;
            r = i;
        }
        if (sum < 0) {
            sum = 0;
            l = i + 1;
        }
    }

    if (ans == 0) {
        ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > ans) {
                ans = nums[i];
                l = r = i;
            }
        }
    }
    return {l, r, ans};
}

/* Pascal Triangle helper functions */

vector<vector<long long>> pascalTriangle(int n) {
    vector<vector<long long>> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i].resize(i + 1);
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans;
}

/* leap year */

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
    return false;
}

// calculate number of leap years between two years
int numberOfLeapYears(int y1, int y2) {
    int ans = 0;
    for (int i = y1; i <= y2; ++i) {
        if (isLeapYear(i)) ++ans;
    }
    return ans;
}

/* Bits helper functions */

void printBits(long long n) {
    while (n) {
        cout << (n & 1);
        n &= (n - 1);  // remove last set bit (more efficient than n >>= 1)
        // n >>= 1;
    }
}

string decimalToBinary(long long n) {
    string ans = "";
    while (n) {
        ans += (n & 1) + '0';
        n &= (n - 1);
        // n >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

long long countBits(long long n) {
    long long ans = 0;
    while (n) {
        ++ans;
        n >>= 1;
    }
    return ans;
}

long long countOnes(long long n) {
    long long ans = 0;
    while (n) {
        n &= (n - 1);
        ++ans;
    }
    return ans;
}

long long countZeros(long long n) {
    long long ans = 0;
    while (n) {
        if (!(n & 1)) ++ans;
        // n >>= 1;
        n &= (n - 1);
    }
    return ans;
}

long long binaryToDecimal(string s) {
    long long ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        ans = (ans << 1) + (s[i] - '0');
    }
    return ans;
}

void printAllSubsets(int len) {  // from 0 to len-1
    for (int i = 0; i < (1 << len); ++i) {
        for (int j = 0; j < len; ++j) {
            if (i & (1 << j)) cout << j << ' ';
        }
        cout << '\n';  // 0 1 01 2 02 12 012
    }
}

void printAllCombinations(int len) {
    for (int i = 0; i < (1 << len); ++i) {
        for (int j = 0; j < len; ++j) {
            if (i & (1 << j)) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
}

// check if a number is power of 2
bool isPowerOf2(long long n) { return n && !(n & (n - 1)); }

// check if a number is odd
bool isOdd(long long n) { return n & 1; }

// check if a number is even
bool isEven(long long n) { return !(n & 1); }

// check if a number is positive using bits
bool isPositive(long long n) { return !(n & (1 << 31)); }

// check if a number is palindrome
bool isPalindrome2(long long n) {
    long long temp = n;
    long long rev = 0;
    while (temp) {
        rev = (rev << 1) + (temp & 1);
        temp >>= 1;
    }
    return rev == n;
}

// get the ith bit of a number
long long getBit(long long n, int i) { return (n >> i) & 1; }

// set the ith bit of a number to 1
long long setBit1(long long n, int i) { return n | (1 << i); }

// set the ith bit of a number to 0
long long setBit0(long long n, int i) { return n & ~(1 << i); }

// toggle/flip the ith bit of a number
long long toggleBit(long long n, int i) { return n ^ (1 << i); }

long long greyCode(long long n) { return n ^ (n >> 1); }

long long greyCodeInverse(long long n) {
    long long ans = 0;
    for (; n; n >>= 1) {
        ans ^= n;
    }
    return ans;
}

/* recursion helper functions */

// simple recursion
void recursion(int n) {
    cout << n << " ";    // 5 4 3 2 1 0
    if (n == 0) return;  // base case
    cout << n << " ";    // 5 4 3 2 1
    recursion(n - 1);    // recursive call (subproblem of n)
    cout << n << " ";    // 1 2 3 4 5
}

// draw a traiangle
void tr(int n) {
    if (n == 0) return;

    tr(n - 1);
    for (int i = 1; i <= n; i++) {
        cout << '*';
    }
    cout << endl;
}

// reversed traiangle
void revTr(int n) {
    if (n == 0) return;

    for (int i = 1; i <= n; i++) {
        cout << '*';
    }
    cout << endl;

    revTr(n - 1);
}

// pyramid using recursion
void pyramid(int n, int stars) {
    if (n == 0) return;
    for (int i = 0; i < n - 1; i++) cout << " ";
    for (int i = 0; i < stars; i++) cout << "*";
    cout << '\n';

    pyramid(n - 1, stars + 2);
}

// 3n+1 series

int series3N(int n) {
    if (n == 1) return 1;
    cout << "n = " << n << endl;
    // return number of elements
    return 1 + (n & 1 ? series3N(3 * n + 1) : series3N(n / 2));
}

// print digits of a number using recursion
void printDigits(long long n) {
    if (!n) return;
    printDigits(n / 10);
    cout << n % 10 << endl;
}

vector<vector<long long>> grid;
// path with maximum sum in a matrix
long long maxPath(int r, int c) {
    if (r == grid.size() - 1 && c == grid[0].size() - 1) return grid[r][c];
    if (r == grid.size() - 1) return grid[r][c] + maxPath(r, c + 1);
    if (c == grid[0].size() - 1) return grid[r][c] + maxPath(r + 1, c);

    return grid[r][c] + max(maxPath(r + 1, c), maxPath(r, c + 1));
}

// multiplyMatricesRecurcivly
void multiplyMats(vector<vector<int>>& firstMat, vector<vector<int>>& secondMat,
                  vector<vector<int>>& resultMat, int r = 0, int c = 0,
                  int index = 0) {
    if (r == firstMat.size()) return;
    if (c == secondMat[0].size())
        return multiplyMats(firstMat, secondMat, resultMat, r + 1, 0, 0);
    if (index == secondMat.size())
        return multiplyMats(firstMat, secondMat, resultMat, r, c + 1, 0);
    resultMat[r][c] += firstMat[r][index] * secondMat[index][c];
    multiplyMats(firstMat, secondMat, resultMat, r, c, index + 1);
}

// connected components using recursion

/*
    check if there is a path from S to E using recursion

    S * * * .
    . . . * .
    . * . * .
    . * . . E
*/
bool connectedComp(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
        grid[r][c] == '*' || visMatrix[r][c])
        return false;
    visMatrix[r][c] = true;
    if (grid[r][c] == 'E') return true;
    if (connectedComp(grid, r + 1, c)) return true;
    if (connectedComp(grid, r - 1, c)) return true;
    if (connectedComp(grid, r, c + 1)) return true;
    if (connectedComp(grid, r, c - 1)) return true;

    return false;
}

// count connected '.' in a matrix >> use vis matrix to avoid infinity loop
long long countConnectedComp(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
        grid[r][c] == '*' || visMatrix[r][c])
        return 0;

    visMatrix[r][c] = true;

    return 1 + countConnectedComp(grid, r + 1, c) +
           countConnectedComp(grid, r - 1, c) +
           countConnectedComp(grid, r, c + 1) +
           countConnectedComp(grid, r, c - 1);
}

// print in zigzag order
void printZigzag(vector<vector<int>>& pixelMatrix, int row, int col, int N,
                 bool up, int cnt) {
    // base case: reached the bottom-right cell of the matrix
    if (col == N && row < N) return;
    // validate indices
    if (row < 0 or row >= N or col < 0 or col >= N) return;

    // Print the current item

    if (cnt % N == 0 && cnt) cout << endl;
    cnt++;
    cout << pixelMatrix[row][col] << " ";

    // Decide the next cell to visit
    if (up) {
        if (col == N - 1) {
            printZigzag(pixelMatrix, row + 1, col, N, !up, cnt);  // Move down
        } else if (row == 0) {
            printZigzag(pixelMatrix, row, col + 1, N, !up, cnt);  // Move right
        } else {
            printZigzag(pixelMatrix, row - 1, col + 1, N, up,
                        cnt);  // Move up-right
        }
    } else {
        if (row == N - 1) {
            printZigzag(pixelMatrix, row, col + 1, N, !up, cnt);  // Move right
        } else if (col == 0) {
            printZigzag(pixelMatrix, row + 1, col, N, !up, cnt);  // Move down
        } else {
            printZigzag(pixelMatrix, row + 1, col - 1, N, up,
                        cnt);  // Move down-left
        }
    }
}

/* Random helper functions */
long long random(long long l, long long r) { return l + rand() % (r - l + 1); }

long long randomTimeBased(long long l, long long r) {
    long long ans = l + rand() % (r - l + 1);
    return ans;
}

//**code***********************************
void solve() {}
//**********************************************
int main() {
    boklFastIO();
    //***CODE***************************************
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
        //        cout << '\n';
    }
    //**********************************************
    return 0;
}

/* Notes */

// basic math

/* divisibility rules */
// 2: last digit is even
// 3: sum of digits is divisible by 3
// 4: last two digits are divisible by 4
// 5: last digit is 0 or 5
// 6: divisible by 2 and 3
// 8: last three digits are divisible by 8
// 9: sum of digits is divisible by 9
// 10: last digit is 0

/* prime numbers formula */
// #1
// 6n+1 or 6n-1 (except 2 and 3)
// examples
// 6n+1: 7, 13, 19, 31, 37, 43, 61, 67, 73, 79, 97
// 6n-1: 5, 11, 17, 23, 29, 41, 47, 53, 59, 71, 83
// #2
// 30k+i (except 2, 3, 5)
// examples
// 30k+1: 31, 61, 91, 121, 151, 181, 211, 241
// 30k+7: 37, 67, 97, 127, 157, 187, 217, 247
// #3
// To know the prime numbers greater than 40
// n^2 + n + 41 (for n = 0 to 39)
// examples
// n = 0: 41
// n = 39: 1601

/* summation formulas */

// n(n+1)/2 = sum of first n natural numbers
// n(n-1)/2 = sum of first n natural numbers except n (n-1)
// n^2 + n = n(n+1) = sum of first n even numbers
// n^2 = sum of first n odd numbers
// n(n+1)(2n+1)/6 = sum of squares of first n natural numbers
// (n(n+1)/2)^2 = sum of cubes of first n natural numbers

/* permutations and combinations formula */

// permutations : order matters : 123 != 132
// nPr = n! / (n - r)! == nCr * r! : used to arrange r objects from n objects

// combinations : order doesn't matter : 123 == 132
// nCr = n! / [r! * (n - r)!] == nPr / r! : used to select r objects from n
// objects

// nCr = n-1Cr-1 + n-1Cr (pascal triangle) (nCr = nCn-r)
// example
// 1
// 1 1
// 1 2 1
// 1 3 3 1

/* inclusion-exclusion principle */
// |A U B U C| = |A| + |B| + |C| - |A n B| - |A n C| - |B n C| + |A n B n C|
// add odds and subtract evens

/* leap year */

// year % 4 == 0 && year % 100 != 0 || year % 400 == 0

/* C IO */

// #include <stdio.h>
// int a, b;
// scanf("%d %d", &a, &b);

// int a = 123, b = 456;
// printf("%d %d\n", a, b);

// $d : for int and long
// $f : for float and double
// $u : for unsigned int and unsigned long
// $c : for char
// $s : for string

/* Files */

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

/* big int */

// 128 bit integer (2^128 - 1) =
// 340,282,366,920,938,463,463,374,607,431,768,211,455 (20 digits)
// __int128_t x = 123456789123456789123456789123456789;
// valid only in gcc compiler

/* Bits and Bits Manipulation */

// 1. Bitwise AND (&)
// 2. Bitwise OR (|)
// 3. Bitwise XOR (^)
// 4. Bitwise NOT (~)
// 5. Left Shift (<<)
// 6. Right Shift (>>)

/*
        A 	B 	!A 	A&B 	A|B 	A^B
        0	0	1	0		0		0
        0	1	1	0		1		1
        1	0	0	0		1		1
        1	1	0	1		1		0
*/

// 0 = 0000, 1 = 0001, 2 = 0010, 3 = 0011, 4 = 0100, 5 = 0101, 6 = 0110,
// 7 = 0111, 8 = 1000, 9 = 1001, 10 = 1010, 11 = 1011, 12 = 1100, 13 = 1101,
// 14 = 1110, 15 = 1111

// 1. Bitwise AND (&) // 0 & 0 = 0, 0 & 1 = 0, 1 & 0 = 0, 1 & 1 = 1
// X & 0 = 0
// X & X = X

// common use cases
// 1) used to check if a number is odd or even : x & 1 == 0 (even) or 1 (odd)
// 2) number is negative or positive : x & (1 << 31) == 0 (pos) or 1 (neg)
// 3) used to check if a number is power of 2 :
// x & (x - 1) == 0 (power of 2) or not (not power of 2)

// 2. Bitwise OR (|) // 0 | 0 = 0, 0 | 1 = 1, 1 | 0 = 1, 1 | 1 = 1
// X | 0 = X
// X | X = X

// 3. Bitwise XOR (^)
// X ^ 0 = X
// X ^ X = 0
// X ^ Y = Z >> X ^ Z = Y >> Y ^ Z = X
// A ^ B ^ C ^ D = E	For any bit in E with 1, must be ODD number of 1s
// (search) (A ^ B ^ C ^ D ^ E) ^ (A ^ B ^ C) = D ^ E

// common use cases
// 1) used to toggle a bit : x ^ (1 << i) (toggle ith bit) (0 based)
// example : 7 ^ (1 << 2) = 3 (0111 ^ 0100 = 0011) (toggle 2nd bit)
// 2) used to check if two numbers are of opposite sign :
// x ^ y < 0 (opposite sign) or not (same sign)
// 3) used to check if two numbers are equal : x ^ y == 0 (equal) or not (not
// equal) 4) used to swap two numbers : x ^= y; y ^= x; x ^= y; example : x = 5,
// y = 7 (0101, 0111) >> x ^= y (0010) >> y ^= x (0101) >> x ^= y (0111) 5)
// X%(2^n) = X & (2^n -1) 5) used to find the missing number in an array : int
// missingNumber(vector<int>& nums) {
//     int ans = 0;
//     for (int i = 0; i < nums.size(); ++i) {
//         ans ^= nums[i];
//         ans ^= i;
//     }
//     ans ^= nums.size();
//     return ans;
// }
// 6) used to find the unique number in an array :
// int uniqueNumber(vector<int>& nums) {
//     int ans = 0;
//     for (int i = 0; i < nums.size(); ++i) {
//         ans ^= nums[i];
//     }
//     return ans;
// }
// 7) used to find the two unique numbers in an array :
// vector<int> uniqueNumbers(vector<int>& nums) {
//     int ans = 0;
//     for (int i = 0; i < nums.size(); ++i) {
//         ans ^= nums[i];
//     }
//     int mask = ans & (-ans);
//     int x = 0, y = 0;
//     for (int i = 0; i < nums.size(); ++i) {
//         if (nums[i] & mask) {
//             x ^= nums[i];
//         } else {
//             y ^= nums[i];
//         }
//     }
//     return {x, y};
// }

// 4. Bitwise NOT (~)

// 5. Left Shift (<<)
// x << y = x * 2^y
//
// 6. Right Shift (>>)
// x >> y = x / 2^y

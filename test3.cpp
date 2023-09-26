#pragma GCC optimise ("03")
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define int long long
#define dd long double
#define p2(n) (n)*(n)
#define p(n,os) pow(n,os)
#define PINF LONG_LONG_MAX
#define NINF LONG_LONG_MIN
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define sz(x) ll(x.size())
// #define endl '\n'
#define nom(c) ((int)((c)-'0'))
#define fsmal(c) (((int)(c))-32)
#define let(n) ((char)((n)+'0'))
#define fcap(n) (int)(((n)+32))
#define fix(x) cout<<fixed<<setprecision(x)
#define pr(a,b) pair<a,b>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vect(n) vector<n>
#define veci vector<int>
#define vecll vector<ll>
#define vecdd vector<dd>a
#define vec_2d(typee,name,n,m) vector<vect(typee)> name(n,vect(typee)(m));
#define cin(vec) for(auto& i : vec) cin >> i;
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
#define copv(vec) copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));cout<<endl;
#define copa(arr,n) copy(arr,arr+n,ostream_iterator<int>(cout," "));cout<<endl;
#define cin_2d(vec) for(auto &r:vec)for(auto &c:r) cin>>c;
#define cout_2d(vec) for(auto &r:vec){for(auto &c:r)cout<<c<<" ";cout<<endl;}
#define PI acos(-1)
#define MOD (ll)(1e9 + 7) 
#define hole(s) (s).begin(),(s).end()
#define holer(s) (s).rbegin(),(s).rend()
#define ltor(s,l,r) (s).begin()+l,(s).begin()+r
#define apps ll t;cin>>t;while(t--){app();/*if(t)/cout<<endl;*/}
#define Zhran ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
ll fact(ll n){if(n<=1)return 1;else return ((n % 998244353)* (fact(n-1) % 998244353))%998244353;}
bool istPrime(ll n){if(n==2)return 1;if(n<2||n%2==0)return 0;for(ll i=3;i*i<=n;i+=2){if(n%i==0)return 0;}return 1;}
ll gcd(ll x,ll y){if(!x||!y)return max(x,y);return gcd(max(x,y)%min(x,y),min(x,y));}
ll lcm(ll x,ll y){return (x*y)/gcd(x,y);}
ll fastpow(ll x,ll n){ll result = 1;while(n>0){if(n%2==1)result=result*x;x=x*x;n/=2;}return result;}
ll modfastpow(ll x,ll n,ll m){ll result = 1;while(n>0){if(n%2==1)result=(result*x)%m;x=(x*x)%m;n/=2;}return result;}
dd log_a_to_base_b(dd a, dd b){return log(a) / log(b);}
bool comparesort(pair<ll,ll> a,pair<ll,ll> b){if(a.first<b.first)return a.first>b.first;else return b.first<a.first;}
bool isTriangle(dd a,dd b,dd c){if(a+b>c&&a+c>b&&c+b>a)return true;return false;}
bool isRightbycoordinates(dd x1,dd y1,dd x2,dd y2,dd x3,dd y3){dd a1=p(abs(x2-x1),2)+p(abs(y2-y1),2),a2=(p(abs(x2-x3),2)+p(abs(y2-y3),2)),a3=(p(abs(x3-x1),2)+p(abs(y3-y1),2));if(a1==0||a2==0||a3==0)return false;if( max({a1,a2,a3}) ==  min({a1,a2,a3}) +  ((a1+a2+a3)-(max({a1,a2,a3})+min({a1,a2,a3})) ))return true;return false;}
int nCr(int n, int r){
    return (fact(n) / (fact(n - r) * fact(r)));
}
int bitsSet(int x) {
    return __builtin_popcount(x);
}



template<class T, class U>
struct SegTree {
    ll n;
    vector<T> seg;
    vector<U> lazy;
    T id_ele;
    U id_upd;
    bool isRupd;
    //functions to be defined
    T (*mergeChilds)(T, T);
    U (*mergeUpd)(ll, ll, U, U);
    T (*applyUpd)(ll, ll, T, U);
    //constructor
    SegTree(ll n, T id_ele = 0, U id_upd = 0, bool isRupd = 0) {
        this->n = n;
        this->id_ele = id_ele;
        this->id_upd = id_upd;
        this->seg.resize(4 * n, id_ele);
        if(isRupd)
            this->lazy.resize(4 * n, id_upd);
        this->isRupd = isRupd;
        // this->build(0, 0, n-1, v);
    } 
    //init function to assign undefiend functions
    void init(T (*mergeChilds)(T, T), U (*mergeUpd)(ll, ll, U, U), T (*applyUpd)(ll, ll, T, U)){
        this->mergeChilds = mergeChilds;
        this->mergeUpd = mergeUpd;
        this->applyUpd = applyUpd;
    }
    //init function to assign mergeChilds
    void initMergeChilds(T (*mergeChilds)(T, T)){
        this->mergeChilds = mergeChilds;
    }
    //init function to assign mergeUpd
    void initMergeUpd(U (*mergeUpd)(ll, ll, U, U)){
        this->mergeUpd = mergeUpd;
    }
    //init function to assign applyUpd
    void initApplyUpd(T (*applyUpd)(ll, ll, T, U)){
        this->applyUpd = applyUpd;
    }
    //tree utils
    void handleLaziness(ll node, ll l, ll r)
    {
        //for the below line to work, make sure the "==" operator is defined for U. if U is struct
        if(this->lazy[node] == this->id_upd) return;
        //handle
        this->seg[node] = this->applyUpd(l, r, this->seg[node], this->lazy[node]);
        if(l < r)
        {
            this->lazy[2*node + 1] = this->mergeUpd(l, r, this->lazy[node * 2 + 1], this->lazy[node]);
            this->lazy[2*node + 2] = this->mergeUpd(l, r, this->lazy[node * 2 + 2], this->lazy[node]);            
        }
        this->lazy[node] = this->id_upd;
    }
    void buildUtil(int node, int l, int r, vector<T>& v){
        if(l == r){
            this->seg[node] = v[l];
            return;
        }
        int mid = (l + r) >> 1;
        this->buildUtil(node * 2 + 1, l, mid, v);
        this->buildUtil(node * 2 + 2, mid + 1, r, v);
        this->seg[node] = this->mergeChilds(this->seg[node * 2 + 1], this->seg[node * 2 + 2]);
    }
    void updateUtil(ll node, ll l, ll r,  ll st, ll ed, ll upd){
        //handle lazy updates
        if(this->isRupd)
            this->handleLaziness(node, l, r); 
        // no over lap
        if(l > ed || st > r) 
            return;
    
        // complete over lap when the tree seg l, r is completely in required range st, ed
        if(st <= l && ed >= r) {
            if(this->isRupd){
                this->lazy[node] = this->mergeUpd(l, r, this->lazy[node], upd);
                this->handleLaziness(node, l, r);
            }else
                this->seg[node] = this->applyUpd(l, r, this->seg[node], upd);
            return;
        }
            
        //partial over lap
        ll mid = (l + r) >> 1;
        this->updateUtil(node * 2 + 1, l, mid, st, ed, upd);
        this->updateUtil(node * 2 + 2, mid + 1, r, st, ed, upd);
        this->seg[node] = this->mergeChilds(this->seg[node * 2 + 1], this->seg[node * 2 + 2]);
    }
    T queryUtil(ll node, ll l, ll r,  ll st, ll ed){
        //handle lazy updates
        if(this->isRupd)
            this->handleLaziness(node, l, r); 
        // no over lap
        if(l > r || l > ed || st > r) 
            return id_ele;
    
        // complete over lap when the tree seg l, r is completely in required range st, ed
        if(st <= l && ed >= r) 
            return this->seg[node];
        
            
        //partial over lap
        ll mid = (l + r) >> 1;
        T lhs = this->queryUtil(node * 2 + 1, l, mid, st, ed);
        T rhs = this->queryUtil(node * 2 + 2, mid + 1, r, st, ed);
        return this->mergeChilds(lhs, rhs);
    }
    //funcs
    void build(vector<T>v)
    {
        assert((ll)v.size() == this->n);
        this->buildUtil(0, 0, this->n - 1, v);
        // cout(this->seg);
    }
    T query(ll l, ll r)
    {
        return this->queryUtil(0, 0, n - 1, l, r);
    }
    void update(ll l,ll r, U upd)
    {
        this->updateUtil(0, 0, n - 1, l, r, upd);
    }
};

#define STT ull
#define STU ull
const int N = 2e5 + 10;
int n, m, q, x, y, a, b, k;
vector<deque<int>> answers;


void app(){
    cin>>n;
    vector<STT> v(n+1);
    for(int i = 1 ; i <= n; i++)cin>>v[i];
    SegTree<STT, STU> tree(n + 1, LONG_LONG_MAX, LONG_LONG_MAX);
    tree.initMergeChilds([](STT a, STT b) -> STT {
        return (a & b);
    });
    tree.build(v);
    cin>>q;
    while(q-- && cin>>a>>b){
        // a--;
        int ans = -1, l = a, r = n, k = b;
        while(l <= r){
            int m = (l + r) / 2;
            int tmp = tree.query(a, m);
            // cout<<"jdksh: "<< tmp<<endl;
            if(tmp >= k){
                ans = m;
                l = m + 1;
            }else r = m - 1;
        }
        cout<<ans<<' ';

    }
    cout<<endl;
}
 
main(){
    Zhran;
    fix(0);
    apps;
    return 0;
}


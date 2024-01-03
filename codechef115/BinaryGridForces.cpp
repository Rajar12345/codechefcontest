
#include "bits/stdc++.h"
using namespace std;

#define int int64_t
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pp pair<int, int>

template <typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>istream& operator >> (istream &is, T_container &v) {for(T &x : v) is >> x; return is;}
template <typename A, typename B>ostream &operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.first << ", " << p.second << ')';}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>ostream &operator<<(ostream &os, const T_container &v){    os << '{';string sep;for (const T &x : v)os << sep << x, sep = ", ";return os << '}';}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){static priority_queue<P, Q, R> U;U = M;out << "{ ";while(!U.empty())out << U.top() << " ", U.pop();return (out << "}");}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){static queue<P> U;U = M;out << "{ ";while(!U.empty())out << U.front() << " ", U.pop();return (out << "}");}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T){cerr << ' ' << H; dbg_out(T...);}
#ifdef LOCAL
    #define dbg(...) cerr << "\e[91m" << __func__ << " : " << __LINE__ << " " << "(" << #__VA_ARGS__ << ") : ",dbg_out(__VA_ARGS__);cerr << "\e[39m";
#else
    #define dbg(...) 2529;
#endif

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >;

const int mod = 1e9 + 7, inf = 1e18L + 5, N = 2e5 + 5;
const string yes = "YES", no = "NO";

namespace mod_operations {
    int madd(int a, int b) {
        return (a + b) % mod;
    }
    int msub(int a, int b) {
        return (((a - b) % mod) + mod) % mod;
    }
    int mmul(int a, int b) {
        return ((a % mod) * (b % mod)) % mod;
    }
    int mpow(int base, int exp) {
        int res = 1;
        while (exp) {
            if (exp % 2 == 1){
                res = (res * base) % mod;
            }
            exp >>= 1;
            base = (base * base) % mod;
        }
        return res;
    }
    int minv(int base) {
        return mpow(base, mod - 2);
    }
    int mdiv(int a, int b) {
        return mmul(a, minv(b));
    }

    const int FACTORIAL_SIZE = 1.1e6;
    int fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
    bool __factorials_generated__ = 0;
    void gen_factorial(int n) {
        __factorials_generated__ = 1;
        fact[0] = fact[1] = ifact[0] = ifact[1] = 1;

        for (int i = 2; i <= n; i++) {
            fact[i] = (i * fact[i - 1]) % mod;
        }
        ifact[n] = minv(fact[n]);
        for (int i = n - 1; i >= 2; i--) {
            ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
        }
    }
    int ncr(int n, int k) {
        if (!__factorials_generated__) {
            cerr << "Call gen_factorial you dope" << endl;
            exit(1);
        }
        if (k < 0 || n < k) return 0;
        int den = (ifact[k] * ifact[n - k]) % mod;
        return (den * fact[n]) % mod;
    }
}
using namespace mod_operations;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string>a(n);
    cin >> a;
    if(n == 1){
        cout << 1 << endl;return;
    }
    dbg(a);
    set<int> pos;
    for(int i = n - 2; i > 0; i--) {
        for(int j = 0; j < m; j++) {
            if(a[i + 1][j] == '1') {
                pos.insert(j);
            }
        }
        int ones = count(all(a[i]), '1');
        if(ones <= 1){
            pos.clear();
            continue;
        }
        bool ok = false;
        for(auto &x : pos) {
            if(a[i][x] == '1') {
                ok = true;
            }
        }
        if(ok) {
        //     for(auto &x : pos) {
        //         a[i][x] = '1';
        //     }
        }
        else{
            pos.clear();
        }
    }
    for(int j = 0; j < m; j++) {
        if(a[1][j] == '1') {
            pos.insert(j);
        }
    }
    int cnt = 0;
    for(auto &x : pos) {
        cnt += (a[0][x] == '1');
    }
    cout << ncr(sz(pos), cnt) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    std::cout << std::fixed << std::setprecision(25);
    std::cerr << std::fixed << std::setprecision(10);
#ifdef LOCAL
    auto start = std::chrono::high_resolution_clock::now();
#endif
    gen_factorial(1e6);
    int cases = 1;
    cin >> cases;

    for (int tc = 1; tc <= cases; tc++) {
        solve();
    }
    #ifdef LOCAL
        auto stop = std::chrono::high_resolution_clock::now();
        long double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
        cerr << "Time taken : " << duration / 1e9 << "s" << endl;
    #endif
    return 0;
}


#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll                      long long int
#define ull                     unsigned long long int
#define lll                     __int128
#define lld                     long double
#define loop(i, a, b)           for(ll i = a; i <= b; i++)
#define loop2(i, b, a)          for(ll i = b; i >= a; i--)
#define ini(x, y)               memset(x, y, sizeof(x))
#define all(x)                  x.begin(), x.end()
#define all2(x)                 x.rbegin(), x.rend()
#define sz(x)                   (ll)x.size()
#define pb                      push_back
#define ppb                     pop_back
#define mp                      make_pair
#define ff                      first
#define ss                      second
#define M                       1000000007
#define endl                    '\n'
#define bits(x)                 __builtin_popcountll(x)
#define zrbits(x)               __builtin_ctzll(x)
#define vl                      vector<ll>
#define pll                     pair<ll,ll>
#define vpll                    vector<pll>
#define uni(x)                  x.erase(unique(all(x)), x.end())
#define ordered_set             tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define mxheap                  priority_queue<ll>
#define mnheap                  priority_queue<ll, vector<ll>, greater<ll>>
#define mxheap2                 priority_queue<pair<ll,ll>>
#define mnheap2                 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>

const int N = 2e5 + 5;
const int L = 20;
const int MX = 1e9 + 10;
const ll INF = 1e18;

const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

using namespace std;
using namespace __gnu_pbds;

inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
inline ll mod(ll x) {return ( (x % M + M) % M );}
ll ulog(ll val, ll base) {ll cnt = 0; val /= base; while(val) {cnt++; val /= base;} return cnt;}
ll power(ll a, ll b) {ll res = 1; while (b) {if (b & 1) res = res * a; a = a * a; b >>= 1;} return res;}
ll modpow(ll a, ll b) {ll res = 1; while (b) {if (b & 1) res = res * a % M; a = a * a % M; b >>= 1;} return res;}

#ifdef FARHAN
#define deb(x)                  cerr << #x << " = " << x << endl;
#define deb2(x, y)              cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define deb3(x, y, z)           cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define deb4()                  cerr << endl;
#define done                    cerr << "Line " << __LINE__ << " is done" << endl;
#else
#define deb(x)
#define deb2(x, y)
#define deb3(x, y, z)
#define deb4()
#define done
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for(auto& x : v) os << x << " "; return os;}
template<typename T> ostream& operator<<(ostream& os, const set<T>& v) {for(auto& x : v) os << x << " "; return os;}
template<typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& p) {os << p.first << ' ' << p.second; return os;}
template<typename... T> void in(T&... args) {((cin >> args), ...);}
template<typename... T> void out(T&&... args) {((cout << args << endl), ...);}
template<typename... T> void out2(T&&... args) {((cout << args << " "), ...);}
template<typename... T> void out3(T&&... args) {((cout << args << " "), ...); cout << endl;}

ll seg[4*N];

ll query(ll node, ll start, ll end, ll l, ll r) {
        if(start >= l && end <= r) return seg[node];

        if(start > r || end < l) return 0;

        ll mid = (start + end) >> 1;
        ll left = query(2 * node + 1, start, mid, l, r);
        ll right = query(2 * node + 2, mid + 1, end, l, r);

        return (left + right);
}

void update(ll node, ll start, ll end, ll ind, ll val) {
        if(start == end) {
                seg[node] = val;
                return;
        }

        ll mid = (start + end) >> 1;
        if(ind <= mid) update(2 * node + 1, start, mid, ind, val);
        else update(2 * node + 2, mid + 1, end, ind, val);

        seg[node] = (seg[2 * node + 1] + seg[2 * node + 2]);
}

void gabbarIsBack() {
        ll n;
        cin >> n;
        ll q;
        cin >> q;

        loop(i, 0, 4 * n + 5) {
                seg[i] = 0;
        }

        vector<ll> a(n);
        for(auto &x : a) cin >> x;
        loop(i, 0, n - 1) {
                update(0, 0, n - 1, i, a[i]);
        }

        ll id = n - 1;
        ll val = a[n - 1];
        ll sum = a[n - 1];
        vector<ll> ans;
        ll f = 0;
        loop2(i, n - 2, 0) {
                if(a[i] <= val / 2) {
                        id = i;
                        val = a[i];
                } else {
                        if(a[i] < val) {
                                val -= a[i];
                        } else {
                                sum += a[i];
                                sum -= val;
                                sum += query(0, 0, n - 1, 0, i - 1);
                                ans.pb(sum);
                                f = 1;
                                break;
                        }
                }
        }
        if(f == 0) ans.pb(sum);

        while(q--) {
                ll index, value;
                cin >> index >> value;
                index--;
                a[index] = value;
                update(0, 0, n - 1, index, value);

                ll id = n - 1;
                ll val = a[n - 1];
                ll sum = a[n - 1];
                ll f = 0;
                loop2(i, n - 2, 0) {
                        if(a[i] <= val / 2) {
                                id = i;
                                val = a[i];
                        } else {
                                if(a[i] < val) {
                                        val -= a[i];
                                } else {
                                        sum += a[i];
                                        sum -= val;
                                        sum += query(0, 0, n - 1, 0, i - 1);
                                        ans.pb(sum);
                                        f = 1;
                                        break;
                                }
                        }
                }
                if(f == 0) ans.pb(sum);
        }
        for(auto e : ans) cout << e << endl;
}

signed main () {
        #ifdef FARHAN
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        FIO;
        int tc = 1;
        cin >> tc;
        for(int i = 1; i <= tc; i++) {
                gabbarIsBack();
        }
        return 0;
}

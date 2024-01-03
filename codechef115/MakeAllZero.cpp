#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output1.txt", "w", stdout);
#endif

    ll T;
    cin >> T;
    while (T--)
    {
        ll N;
        cin >> N; 
        vector<ll> A(N);
        
        ll ans = N;
        set<ll> st;
        map<ll,ll>mp;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            st.insert(A[i]);
            mp[A[i]]++;
        }

        ll count = 0;
        ll small = *st.begin();
        ll maxi = small;        
        for (int i = N - 1; i >= 0; --i) {
            if (A[i] == small) {
                count++;
                if (mp[small] == 1) {
                    maxi = small;
                    st.erase(st.begin());
                    ans = min(ans, maxi + N - count);
                    if (st.size() == 0) break;
                    while(st.size()) {
                        small = *st.begin();
                        if (mp[small] == 0) {
                            st.erase(st.begin());
                        }
                        else break;
                    }
                }
            }
            mp[A[i]]--;
        }

        cout << min(ans, maxi + N - count) << "\n";

      
      
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

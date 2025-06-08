// // #include <bits/allocator.h>
// // #pragma GCC optimize("O3,unroll-loops")
// // #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #include "bits/stdc++.h"
// using namespace std;
// using ll = long long int;
// mt19937_64 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());

// int main()
// {
//     ios::sync_with_stdio(false); cin.tie(0);

//     int t; cin >> t;
//     while (t--) {
//         ll n, x; cin >> n >> x;
//         vector a(n, 0ll);
//         for (auto &y : a) cin >> y;
//         vector b(n, 0);
//         for (auto &y : b) cin >> y;
        
//         const ll inf = 1e18;
//         vector pre(n, -inf), suf(n, -inf);
//         vector mxl(n, -inf), mxr(n, -inf);
//         for (int i = 0; i < n; ++i) {
//             if (i) pre[i] = pre[i-1], mxl[i] = mxl[i-1];
//             if (pre[i] < 0) pre[i] = max(pre[i], a[i]);
//             else pre[i] += max(0ll, a[i]);
//             if (b[i] == 1) mxl[i] = max(mxl[i], a[i]);
//         }
//         for (int i = n-1; i >= 0; --i) {
//             if (i < n-1) suf[i] = suf[i+1], mxr[i] = mxr[i+1];
//             if (suf[i] < 0) suf[i] = max(suf[i], a[i]);
//             else suf[i] += max(0ll, a[i]);
//             if (b[i] == 1) mxr[i] = max(mxr[i], a[i]);
//         }

//         ll ans = inf;
//         for (int i = 1; i+1 < n; ++i) {
//             ll lt = pre[i-1], rt = suf[i+1];
//             if (lt + rt >= x) {
//                 ans = 0;
//                 break;
//             }
//             // Increase on left
//             if (mxl[i-1] > -inf) {
//                 ans = min(ans, x - rt - max(0ll, lt) - min(0ll, mxl[i-1]));
//             }
//             // Increase on right
//             if (mxr[i+1] > -inf) {
//                 ans = min(ans, x - lt - max(0ll, rt) - min(0ll, mxr[i+1]));
//             }
//         }
//         cout << ans << '\n';
//     }
// }

// #include <bits/allocator.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
using namespace std;
using ll = long long int;
mt19937_64 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        ll n, x; cin >> n >> x;
        vector a(n, 0ll);
        for (auto &y : a) cin >> y;
        vector b(n, 0);
        for (auto &y : b) cin >> y;
        
        const ll inf = 1e18;
        vector pre(n, -inf), suf(n, -inf);
        vector mxl(n, -inf), mxr(n, -inf);
        for (int i = 0; i < n; ++i) {
            if (i) pre[i] = pre[i-1], mxl[i] = mxl[i-1];
            if (pre[i] < 0) pre[i] = max(pre[i], a[i]);
            else pre[i] += max(0ll, a[i]);
            if (b[i] == 1) mxl[i] = max(mxl[i], a[i]);
        }
        for (int i = n-1; i >= 0; --i) {
            if (i < n-1) suf[i] = suf[i+1], mxr[i] = mxr[i+1];
            if (suf[i] < 0) suf[i] = max(suf[i], a[i]);
            else suf[i] += max(0ll, a[i]);
            if (b[i] == 1) mxr[i] = max(mxr[i], a[i]);
        }

        ll ans = inf;
        for (int i = 1; i+1 < n; ++i) {
            ll lt = pre[i-1], rt = suf[i+1];
            if (lt + rt >= x) {
                ans = 0;
                break;
            }
            // Increase on left
            if (mxl[i-1] > -inf) {
                ans = min(ans, x - rt - max(0ll, lt) - min(0ll, mxl[i-1]));
            }
            // Increase on right
            if (mxr[i+1] > -inf) {
                ans = min(ans, x - lt - max(0ll, rt) - min(0ll, mxr[i+1]));
            }
        }
        cout << ans << '\n';
    }
}
//  Tester's code (C++)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define endl '\n'
#define sz(a) (int)a.size()
#define setbits(x) __builtin_popcountll(x)
#define ff first
#define ss second
#define conts continue
#define ceil2(x,y) ((x+y-1)/(y))
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl

#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define rev(i,s,e) for(int i = s; i >= e; --i)
#define trav(i,a) for(auto &i : a)

template<typename T>
void amin(T &a, T b) {
    a = min(a,b);
}

template<typename T>
void amax(T &a, T b) {
    a = max(a,b);
}

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

/*



*/

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int inf1 = int(1e9) + 5;
const ll inf2 = ll(1e18) + 5;

void solve(int test_case){
    ll n,k; cin >> n >> k;
    vector<ll> a(n+5), b(n+5);
    rep1(i,n) cin >> a[i];
    rep1(i,n) cin >> b[i];

    ll dp[n+5][2][2][2]; // dp[i][started][gap][bi=1 taken?]
    memset(dp,-0x3f,sizeof dp);
    dp[1][0][0][0] = 0;
    ll ans = inf2;

    rep1(i,n){
        rep(started,2){
            rep(gap,2){
                rep(one_taken,2){
                    ll curr = dp[i][started][gap][one_taken];

                    // pick curr guy
                    amax(dp[i+1][1][gap][one_taken|b[i]],curr+a[i]);
                    
                    if(gap){
                        // gap and take --> upd ans
                        ll val = curr+a[i];
                        ll ot = one_taken|b[i];
                        if(val >= k){
                            ans = 0;
                        }
                        else if(ot){
                            amin(ans,k-val);
                        }
                    }

                    // ignore curr guy
                    amax(dp[i+1][started][gap|started][one_taken],curr);
                }
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    fastio;

    int t = 1;
    cin >> t;

    rep1(i, t) {
        solve(i);
    }

    return 0;
}

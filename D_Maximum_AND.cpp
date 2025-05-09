#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double doo;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<ll, ll, std::less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<ll, null_type, less_equal <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// find_by_order : returns an iterator to the k-th smallest element (0-based index) 
//order_of_key(value): Returns the count of elements strictly smaller than value.
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define ll_max INT64_MAX
#define ll_min INT64_MIN
ll N = 1e5;
ll inf = 1e17;
ll MOD = 1e9+7;
ll power(ll a, ll b){
    ll result = 1;
    while (b)
    {
        if (b & 1)
            result = result * a;
        a = a * a;
        b >>= 1;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //sieve();
    ll tc=1;
    cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll>> a(n,{0,0}),b(n,{0,0});
        for(ll i = 0; i <n; i++)
        {
            cin>>a[i].second;
        }
                for(ll i = 0; i <n; i++)
        {
            cin>>b[i].second;
        }
        set<ll> s;
        vector<ll> aprev(n,0), bprev(n,0);
        ll ans = 0;
        for(ll i = 29; i>=0; i--)
        {
            s.clear();
            ll initial = 1;
            ll number_for_prev =0;
            for(ll j = 0; j <n; j++)
            {
                s.insert(aprev[j]);
                if (s.size() == 1+initial)
                {
                    number_for_prev+=2;
                    initial++;
                }

                if (aprev[j] == bprev[j])
                {
                    if ((a[j].second & power(2,i)) == power(2,i))
                    {
                        a[j].first = number_for_prev;
                    }
                    else
                    {
                        a[j].first = number_for_prev+1;
                    }
                    if ((b[j].second & power(2,i)) == power(2,i))
                    {
                        b[j].first = number_for_prev+1;
                    }
                    else
                    {
                        b[j].first = number_for_prev;
                    }
                }
            }
            vector<pair<ll,ll>> avec = a, bvec = b;
            sort(avec.begin(), avec.end());
            sort(bvec.begin(), bvec.end());
            ll ch = 0;
            for(ll j = 0; j <n; j++)
            {
                if (avec[j].first == bvec[j].first)
                {
                    ch++;
                }
            }
            if (ch < n)
            {
                for(ll j = 0; j <n; j++)
                {
                    b[j].first =0;
                    a[j].first =0;
                }
                continue;
            }
            ans += power(2,i);
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            
            for(ll j = 0; j <n; j++)
            {
                aprev[j] = a[j].first;
                bprev[j] = b[j].first;
                b[j].first =0;
                a[j].first =0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
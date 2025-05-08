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
        map<pair<ll,ll>, ll> vertex_number;
        vector<vector<ll>> adj(n+1);
        for(ll i = 0; i <n-1; i++)
        {
            ll u,v;
            cin>>u>>v;
            vertex_number[{u,v}] = i+1;
            vertex_number[{v,u}] = i+1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        

    }
    return 0;
}
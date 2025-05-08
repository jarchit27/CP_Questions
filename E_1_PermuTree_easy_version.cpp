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

    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i = 2; i <=n; i++)
    {
        ll u ;
        cin>>u;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    ll ans = 0;
    vector<ll> subtree(n+1,1);
    vector<ll> parent(n+1, 0);
    vector<bool> visited(n+1, false);
    function<void(ll)> dfs = [&](ll src) -> void {
        visited[src] = true;
        for (auto it = adj[src].begin(); it != adj[src].end(); it++) {
            if (!visited[*it]) {
                parent[*it] = src;
                dfs(*it);
                subtree[src]+= subtree[*it];
            }
        }
    };

    dfs(1);
    
    for(ll k = 1; k <=n; k++)
    {
        if (adj[k].size() == 1)
        {
            continue;
        }
        vector<ll> values;
        for( auto& ele : adj[k])
        {
            if (ele != parent[k])
            {
                values.push_back(subtree[ele]);
            }
        }

        vector<vector<ll>> dp(values.size()+1 , vector<ll>(subtree[k],0));
        for(ll i = 0; i <values.size()+1; i++)
        {
            dp[i][0] = 1;
        }
        for(ll i = 1; i < values.size()+1; i++)
        {
            for(ll j = 1; j < subtree[k]; j++)
            {
                if (values[i-1]>j)
                {
                    dp[i][j]= dp[i-1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-values[i-1]]); 
                }
            }
        }
        ll max_val = 0;
        for(ll i = 1; i < subtree[k]; i++)
        {
            if(dp[values.size()][i] == 1)
                max_val = max(max_val, (subtree[k]-1-i)*i );
        }
        ans+= max_val;
    }
    cout<<ans<<endl;
        
    return 0;
}
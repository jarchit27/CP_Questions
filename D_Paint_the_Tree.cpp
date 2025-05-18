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
ll power_mod(ll a, ll b, ll modulo){
    ll result = 1;
    while (b)
    {
        if (b & 1)
            result = (result * a) % modulo;
        a = (a * a) % modulo;
        b >>= 1;
    }
    return result;
}
string num_tobin(ll n){
    string s = bitset<32>(n).to_string();
    return s;
}
vector<bool> is_prime(1e5+1, true);
vector<ll> prime_number;
void sieve()
{
    ll N = 1e5;
    is_prime[0] = false;
    is_prime[1] = false;
    for(ll i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
            for(ll j = i * i; j <= N; j += i)
                is_prime[j] = false;
    }
    for (int p = 2; p <= N; p++)
        if (is_prime[p])
            prime_number.push_back(p);
}
ll mod_inverse(ll a, ll m)
{
    return power_mod(a, m - 2, m);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //sieve();
    ll tc=1;
    cin>>tc;
    while(tc--)
    {
        ll n,a,b;
        cin>>n>>a>>b;

        vector<vector<ll>> adj(n+1);
        for(ll i = 0; i <n-1; i++)
        {
            ll u ,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n+1, false);
        vector<ll> parent(n+1, -1);
        vector<ll> dist(n+1, 0);
        function<void(ll)> dfs = [&](ll src) -> void {
            stack<ll> q;
            q.push(src);
            visited[src] = true;
            while (!q.empty()) {
                ll curr = q.top();
                q.pop();
                
                for (auto it = adj[curr].begin(); it != adj[curr].end(); it++) {
                    if (!visited[*it]) {
                        q.push(*it);
                        parent[*it] = curr;
                        visited[*it] = true;
                        dist[*it] = dist[curr]+1;
                    }
                }
            }
        };
        ll ans =0;
        dfs(a);
        ans += (dist[b]+1)/2 + 2*(n-1);
        if (a == b)
        {
            cout<<ans- *max_element(dist.begin(), dist.end())<<endl;
            continue;
        }
        ll distt = dist[b];
        visited.assign(n+1, false);
        ll pare = b;
        while (parent[pare] != -1)
        {
            pare= parent[pare];
            if (dist[pare] == (distt)/2)
            {
                break;   
            }
        }
        dist.assign(n+1, 0);
        dfs(pare);
        cout<<ans- *max_element(dist.begin(), dist.end())<<endl;

    }
    return 0;
}
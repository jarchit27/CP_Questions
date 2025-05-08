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

void bfs(vector<vector<ll>> &adj, ll n , ll start, vector<ll> &dist )
{
    vector<bool> visited(n+1, false);
    queue<ll> q;
    q.push(start);
    dist[start] =0;
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();
        visited[curr]  = true;
        for( auto& ele : adj[curr])
        {
            if (!visited[ele])
            {
                dist[ele] = dist[curr]+1;
                q.push(ele);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //sieve();
    ll tc=1;
    // cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n;
        vector<vector<ll>> adj(n+1);
        for(ll i = 0; i <n-1; i++)
        {
            ll u ,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<ll> distance_from_root(n+1,0);
        bfs(adj,n,1,distance_from_root);
        ll sec_start= 0;
        ll root_dist = *max_element(distance_from_root.begin(), distance_from_root.end());
        for(ll i = 0; i <n; i++)
        {
            if (root_dist == distance_from_root[i+1])
            {
                sec_start = i+1;
                break;
            }
        }
        vector<ll> distance_from_sec(n+1,0);
        bfs(adj,n,sec_start,distance_from_sec);

        ll thr_start= 0;
        root_dist = *max_element(distance_from_sec.begin(), distance_from_sec.end());
        for(ll i = 0; i <n; i++)
        {
            if (root_dist == distance_from_sec[i+1])
            {
                thr_start = i+1;
                break;
            }
        }
        vector<ll> distance_from_thr(n+1,0);
        bfs(adj,n,thr_start,distance_from_thr);
        // vector<ll> max_distance(n+1,0);
        ordered_multiset s;
        for(ll i = 0; i <n; i++)
        {
            s.insert(max(distance_from_sec[i+1], distance_from_thr[i+1]));
        }
        ll tree_diameter = root_dist;
        for(ll i = 1; i <=n; i++)
        {
            if (i> tree_diameter)
            {
                cout<<n<<" ";
                continue;
            }
            cout<<s.order_of_key(i)+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
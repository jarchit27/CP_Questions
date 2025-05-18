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
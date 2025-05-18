#include<bits/stdc++.h>
using namespace std;\

long long dijkstra(vector<vector<pair<int ,long long>>>& adj, vector<long long> &slownesfactor , int n)
{
    vector<vector<long long>> bikedistan(n+1,vector<long long> (1+ *max_element(slownesfactor.begin(), slownesfactor.end()), 1e15));
    bikedistan[1][slownesfactor[1]] = 0;
    set<pair<pair<long long,long long>,int>> s;
    s.insert({{0,slownesfactor[1]},1});
    while (!s.empty())
    {
        pair<pair<long long,long long>,int> p = *s.begin();
        int u = p.second;
        long long slowness = p.first.second;
        s.erase(s.begin());
        for( auto& ele : adj[u])
        {
            int v = ele.first;
            long long wt = ele.second;

            if (bikedistan[v][min(slowness,slownesfactor[v])]> bikedistan[u][slowness]+ slowness*wt )
            {
                if (bikedistan[v][min(slowness,slownesfactor[v])]!= 1e15)
                {
                    s.erase({{bikedistan[v][min(slowness,slownesfactor[v])],(long long)(min(slowness,slownesfactor[v]))},v});
                }
                bikedistan[v][min(slowness,slownesfactor[v])] =  bikedistan[u][slowness]+ slowness*wt;
                s.insert({{bikedistan[v][min(slowness,slownesfactor[v])],(long long)(min(slowness,slownesfactor[v]))},v});
            }
        }
    }
    return *min_element(bikedistan[n].begin(), bikedistan[n].end());
}

int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<pair<int ,long long>>>adj(n+1);
        for(int i = 0; i < m; i++)
        {
            int u,v;
            long long w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long> slownesfactor(n+1);
        for(int i = 0; i <n; i++)
        {
            cin>>slownesfactor[i+1];
        }      
        long long  dist = dijkstra(adj,slownesfactor,n);
        cout<<dist<<endl;
    }
    
    return 0;
}
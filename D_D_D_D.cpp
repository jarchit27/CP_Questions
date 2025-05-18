#include<bits/stdc++.h>
using namespace std;


void bfs(vector<vector<int >>& adj, vector<vector<long long>>& distance_even_odd, int n )
{
    vector<vector<bool>> visited(2, vector<bool>(n+1,false));
    distance_even_odd[0][1] = 0;
    // visited[1][1] = true;
    visited[0][1] = true;

    queue<pair<int,int>> q;
    q.push({1,0});
    while (!q.empty())
    {
        int curr = (q.front()).first;
        int evenodd = (q.front()).second;
        q.pop();
        visited[evenodd][curr] = true;
        if (evenodd == 1)
        {
            for( auto& ele : adj[curr])
            {
                if (!visited[0][ele])
                {
                    q.push({ele,0});
                    visited[0][ele] = true;
                    distance_even_odd[0][ele] = distance_even_odd[1][curr]+1;
                }
            }
        }
        else
        {
            for( auto& ele : adj[curr])
            {
                if (!visited[1][ele])
                {
                    visited[1][ele] = true;

                    q.push({ele,1});
                    distance_even_odd[1][ele] = distance_even_odd[0][curr]+1;
                }
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //sieve();
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        int n,m,l;
        cin>>n>>m>>l;
        long long sum = 0;
        vector<int> a(l);
        int mineven = 1e9 ,minodd =1e9;
        for(int i = 0; i <l; i++)
        {
            cin>>a[i];
            if (a[i]%2 == 0)
            {
                mineven = min(mineven,a[i]);
            }
            else
            {
                minodd = min(minodd,a[i]);
            }
            sum+= a[i];
        }
        vector<vector<int >> adj(n+1);
        for(int i = 0; i < m; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<long long>> distance_even_odd(2, vector<long long>(n+1,1e9));
        bfs(adj,distance_even_odd,n);
        long long oddsum =-1,evensum=-1;
        if (sum %2 == 0)
        {
            evensum =sum;
            if (minodd!= 1e9)
            {
                oddsum =  sum - minodd;
            }
        }
        else
        {
            oddsum = sum;
            if (minodd != 1e9)
            {
                evensum = sum-minodd;
            }
        }
        cout<<1;
        for(int i = 2; i <=n; i++)
        {
            if ((distance_even_odd[0][i] != 1e9 && evensum>= distance_even_odd[0][i])|| (distance_even_odd[1][i]!= 1e9 && oddsum>= distance_even_odd[1][i]))
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
        cout<<endl;

    }
    return 0;
}
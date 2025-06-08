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
ll const N = 1e5;
ll const inf = 1e17;
ll const MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<vector<ll>> char_to_ind(k);
    for(int i =0;i< n;i++)
    {
        char_to_ind[s[i]-'a'].push_back(i);
    }
    // cout<<endl;
    vector<int> dp(n+1,1e7);
    vector<pair<int,int>> storee(k);
    set<char> ss;
    int ind = -1;
    for(ll i = n-1; i>=0; i--)
    {
        ss.insert(s[i]);
        if (ss.size() == k)
        {
            ind = i;
            dp[i] =2;
            storee[s[i]-'a'].first = 2;
            storee[s[i]-'a'].second = 0;

            break;
        }
        else
        {
            dp[i] = 1;
            storee[s[i]-'a'].first = 1;
            storee[s[i]-'a'].second = 1;
        }
    }
    for(int i = ind-1;i>=0;i--)
    {
        for(int j=0;j<k;j++)
        {
            char c = 'a'+j;
            if (c == s[i])
            {
                dp[i] = min(dp[i], storee[j].first + storee[j].second +1);
                continue;
            }
            dp[i] = min(dp[i], storee[j].first + storee[j].second);
        }
        if (dp[i] == storee[s[i]-'a'].first+ storee[s[i]-'a'].second+1)
        {
            storee[s[i]-'a'].first = dp[i];
            storee[s[i]-'a'].second =0;
        }
        else
        {
            storee[s[i]-'a'].first = dp[i];
            storee[s[i]-'a'].second =1;
        }
    }
    // for(ll i = 0; i <n; i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    ll m ;
    cin>>m;


    for(ll i = 0; i < m; i++)
    {
        string t;
        cin>>t;
        int last = -1;
        bool ans = true;
        for(int j =0;j<t.length();j++)
        {
            if (upper_bound(char_to_ind[t[j]-'a'].begin(),char_to_ind[t[j]-'a'].end(),last) ==  char_to_ind[t[j]-'a'].end())
            {
                ans = false;
                cout<<0<<endl;
                break;
            }
            else
            {
                
                last = *upper_bound(char_to_ind[t[j]-'a'].begin(),char_to_ind[t[j]-'a'].end(),last);
            }
        }
        if (ans)
        {
            if(last == n-1)
                cout<<1<<endl;
            else
                cout<<dp[last+1]<<endl;
        }
    }



    return 0;
}
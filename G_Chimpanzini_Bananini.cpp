#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc=1;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        map<long long , long long> array;
        int left=0, right=0;
        long long sum_of_arr = 0, ans = 0;
        long long p =0;
        cin>>p;
        cin>>p;
        array[0] = p;
        ans+= p;
        sum_of_arr+=p;
        cout<<p<<endl;
        for(int i = 1; i <n; i++)
        {
            int s;
            cin>>s;
            if (left<= right)
            {
                long long size_of_arr =  right-left+1;
                if (s ==1 )
                {
                    ans += (-size_of_arr*array[right]);
                    ans += sum_of_arr;
                    left--;
                    array[left] = array[right];
                    array[right] =0;
                    right--;
                }
                else if (s == 2)
                {
                    ans = abs(ans - (size_of_arr+1)*sum_of_arr);
                    swap(left, right);
                }
                else if (s == 3)
                {
                    long long k;cin>>k;
                    sum_of_arr+= k;
                    ans+= (size_of_arr+1)*k;
                    right++;
                    array[right] = k;
                }
                cout<<ans<<endl;
            }
            else
            {
                long long size_of_arr =  left- right+1;
                if (s ==1 )
                {
                    ans += (-size_of_arr*array[right]+ sum_of_arr);
                    left++;
                    array[left] = array[right];
                    array[right] =0;
                    right++;
                }
                if (s == 2)
                {
                    ans = abs(ans - (size_of_arr+1)*sum_of_arr);
                    swap(left, right);
                }
                if (s == 3)
                {
                    long long k;cin>>k;
                    sum_of_arr+= k;
                    ans+= (size_of_arr+1)*k;
                    right--;
                    array[right] = k;
                }
                cout<<ans<<endl;

            }
        }
        
    }
    return 0;
}
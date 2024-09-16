#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<bool> vis(65,false);

    vector<int> v(n);
    for(auto &i:v) cin>>i;

    for(auto it:v)
    {
        if(it==0) continue;
        int temp=it;
        int pos=0;
        while(temp)
        {
            int rem=temp%k;
            if(rem==0) {temp/=k;pos++;continue;}
            if(vis[pos])
            {
                cout<<"NO"<<endl;
                return;
            }
            if(rem!=1)
            {
                cout<<"NO"<<endl;
                return;
            }
            vis[pos]=true;
            pos++;
            temp/=k;
        }
    }
    cout<<"YES"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}
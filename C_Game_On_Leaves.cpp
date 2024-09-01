#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<vector<int>> g(n);
    int neigh=0;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        neigh+=(u==x);
        neigh+=(v==x);
    }

    if(neigh==1 || neigh==0)
    {
        cout<<"Ayush"<<endl;
        return;
    }

    n-=3;
    if(n&1)
    cout<<"Ayush"<<endl;
    else
    cout<<"Ashish"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}
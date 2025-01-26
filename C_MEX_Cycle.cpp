#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,x,y;
    cin>>n>>x>>y;

    vector<int> v(n);
    x--;y--;
    for(int i=0;i<n;i++)
    v[(x+i)%n]=i%2;

    if(n&1 || abs(x-y)%2==0) v[x]=2;

    for(auto it:v)
    cout<<it<<' ';
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}
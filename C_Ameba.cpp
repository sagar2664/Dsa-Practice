#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    vector<int> v(2*n+1,0);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        x--;
        v[2*i+1]=v[x]+1;
        v[2*i+2]=v[x]+1;
    }
    for(auto it:v)
    cout<<it<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}
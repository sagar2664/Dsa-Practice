#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n,m;
string a,b,c;
vector<vector<int>> dp;

int rec(int i,int j)
{
    //cout<<i<<' '<<j<<endl;
   
}

void solve()
{
    cin>>a>>b>>c;
    n=a.length();
    m=b.length();
    dp.clear();
    dp.resize(n+1,vector<int>(m+1,-1));
    cout<<rec(0,0)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;cin >> _t;while (_t--)
        solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    string s,t;
    cin>>s>>t;
    int cnt=0;
    int n=s.length();
    int m=t.length();
    for(int i=0;i<min(n,m);i++)
    {
        if(s[i]==t[i]) cnt++;
        else break;
    }
    if(cnt==0) cout<<n+m<<endl;
    else cout<<cnt+1+(n-cnt)+(m-cnt)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}
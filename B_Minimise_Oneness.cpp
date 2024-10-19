#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    if(n==1) {cout<<"0"<<endl;return;}

    string s;
    bool done=false;
    for(int i=0;i<n;i++)
    {
        if(i==n/2 && !done) s+='1',done=true;
        else s+='0';
    }
    cout<<s<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}
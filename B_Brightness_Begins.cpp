#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve() {
    int k;
    cin>>k;

    int l=0;
    int r=2e18;
    int ans=0;
    while(r-l>1)
    {
        int m=(l+r)>>1;
        int n= m - (int)sqrtl(m);
        if(n>=k)
        {
            ans=m;
            r=m;
        }
        else l=m;
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int _t;
    cin >> _t;
    while (_t--) {
        solve();
    }
}

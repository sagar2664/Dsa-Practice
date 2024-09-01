#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n, m, k;
   cin >> n >> m >> k;

   for (int i = n; i > m; i--) {
      cout << i << ' ';
   }

   for (int i = 1; i <= m; i++) {
      cout << i << ' ';
   }
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
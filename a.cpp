#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int N=10;
    int C[N+1][N+1];
    memset(C,0,sizeof(C));
    for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
            C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        cout<<C[i][j]<<' ';
        cout<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}
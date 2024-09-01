#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    string a,b;
    cin>>a>>b;

    int n=a.length();
    int m=b.length();

    int ans=0;
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            int k=j;
            if(a[i]==b[k])
            {
                int len=0;
                int t=i;
                while(t<n && k<m)
                {
                    if(a[t]==b[k])
                    len++,k++;
                    t++;
                }
                ans=max(ans,len);
            }  
        }
    }
    cout<<(n+m-ans)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}
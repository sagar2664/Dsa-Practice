#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int bs(int lo,int h,int k,int cnt)
{
    int l=lo;
    int ans=l;
    while(l<=h)
    {
        int m=(l+h)/2;
        if(cnt*(m-lo)<=k)
        {
            ans=m;
            l=m+1;
        }
        else
        {
            h=m-1;
        }
    }
    return ans;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    cin>>v[i];

    sort(v.begin(),v.end());

    int mid=n/2+1;
    int cnt=1;
    for(int i=mid+1;i<=n;i++)
    {
        int l=v[mid],h=v[i];
        v[mid]=bs(l,h,k,cnt);
        k-=cnt*(v[mid]-l);
        
        cnt++;
        if(k==0) break;
    }
    v[mid]=bs(v[mid],2e9,k,cnt);
    cout<<v[mid]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}
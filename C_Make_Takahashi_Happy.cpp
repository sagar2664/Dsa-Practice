#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int h,w;
    cin>>h>>w;
    int g[h][w];
    for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
    cin>>g[i][j];

    int l=h+w-2;

    vector<int> p(l);
    for(int i=0;i<l;i++)
    {
        if(i>=w-1) p[i]=1;
        else p[i]=0;
    }

    int paths=0;
    do{
        int x=0,y=0;
        set<int> st;
        st.insert(g[0][0]);
        for(int i=0;i<l;i++)
        {
            if(p[i]==1) x++;
            else y++;
            st.insert(g[x][y]);
        }
        if(st.size()==l+1) paths++;
    }while(next_permutation(p.begin(),p.end()));

    cout<<paths<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}
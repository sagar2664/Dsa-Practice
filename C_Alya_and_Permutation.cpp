#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;

    if(n==5)
    {
        cout<<5<<endl;
        cout<<"2 1 3 4 5"<<endl;
        return;
    }
    else if(n==6)
    {
        cout<<7<<endl;
        cout<<"1 2 4 6 5 3"<<endl;
        return;
    }
    else if(n==7)
    {
        cout<<7<<endl;
        cout<<"2 4 5 1 3 6 7"<<endl;
        return;
    }

    int k;
    vector<int> ans;
    if(!(n&1))
    {
        set<int> st;
        int msb=0;
        for(int i=32;i>=0;i--)
        {
            if((1LL<<i)&n)
            {
                msb=i;
                break;
            }
        }

        int t=1LL<<msb;
        st.insert(t);
        st.insert(t-1);
        st.insert(t-2);
        st.insert(3);
        st.insert(1);

        for(int i=2;i<=n;i++)
        {
            if(st.count(i)) continue;
            ans.push_back(i);
        }

        for(auto it:st)
        ans.push_back(it);

        k=1LL<<(msb+1);
        k--;
    }
    else
    {
        k=n;
        set<int> st;
        int msb=0;
        for(int i=32;i>=0;i--)
        {
            if((1LL<<i)&n)
            {
                msb=i;
                break;
            }
        }

        int t=1LL<<msb;
        st.insert(n);
        st.insert(t);
        st.insert(t-1);
        st.insert(t-2);
        st.insert(3);
        st.insert(1);

        for(int i=2;i<=n;i++)
        {
            if(st.count(i)) continue;
            ans.push_back(i);
        }

        for(auto it:st)
        ans.push_back(it);
    }

    cout<<k<<endl;
    for(auto it:ans)
    cout<<it<<' ';
    cout<<endl;

    // int c=0;
    // for(int i=1;i<=n;i++)
    // {
    //     if(i&1)
    //     c&=(ans[i-1]);
    //     else
    //     c|=ans[i-1];
    // }
    // cout<<c<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}
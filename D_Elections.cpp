// Problem: C. Manhattan Permutations
// URL: https://codeforces.com/contest/1978/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';

inline void solve();

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   int TC = 1;
   cin >> TC;
   for (int i = 0; i < TC; i++)
   {
      // cout<<"case "<<(i+1)<<": ";
      solve();
      cout << '\n';
   }

   return 0;
}

void solve()
{
   int n;
   cin >> n;

   ll k;
   cin >> k;

   int ar[n];
   for (int i = 0; i < n; i++)
   {
      ar[i] = i + 1;
   }

   int l = 1, r = n;
   while (l < r)
   {
      if (2 * (r - l) <= k)
      {
         k -= 2 * (r - l);
         swap(ar[r - 1], ar[l - 1]);
         l++, r--;
      }
      else
         l++;
   }

   if (k > 0)
   {
      cout << "No";
      return;
   }

   cout << "Yes" << el;
   for (int i = 0; i < n; i++)
   {
      cout << ar[i] << sp;
   }

   return;
}
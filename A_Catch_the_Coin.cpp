#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const char el = '\n';
const char sp = ' ';
#define int long long

#define TC testcase

inline void solve();

int32_t main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);

   int TC = 1;
   cin >> TC;
   for (int i = 0; i < TC; i++) {
      solve();
      cout << '\n';
   }

   return 0;
}

void solve() {
   int n;
   cin >> n;

   int ar[n], br[n];
   for (int i = 0; i < n; i++) {
      cin >> ar[i];
   }

   for (int i = 0; i < n; i++) {
      cin >> br[i];
   }

   int two =0,threat = 0, ff = 0, ss = 0;
   for (int i = 0; i < n; i++) {
      if (ar[i] == br[i]) {
         if (ar[i] == 1) {
            two++;
         } else if (ar[i] == -1) {
            threat++;
         }
      } else {
         if (ar[i] > br[i]) {
            ff += ar[i];
         } else {
            ss += br[i];
         }
      }
   }


   int ans;

   if (ff < ss) swap(ff, ss);

   int diff = ff - ss;

   if (diff < two + threat) {
      ans = (ff - threat + ss + two);
      if (ans < 0) {
         ans = (ans - 1) / 2;
      } else {
         ans = ans / 2;
      }
   } else {
      ans = ss + two;
   }

   cout << ans;

   return;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

#include <iostream>

using namespace std;

// int countSetBits(int n) {
//     int count = 0;
//     while (n) {
//         count += n & 1;
//         n >>= 1;
//     }
//     return count;
// }

int countEvenSetBitTriplets(int input1[], int input2, int input3[], int input4, int input5[], int input6)
{
    int count = 0;
    for (int i = 0; i < input2; ++i)
    {
        for (int j = 0; j < input4; ++j)
        {
            for (int k = 0; k < input6; ++k)
            {
                int xorValue = input1[i] ^ input3[j] ^ input5[k];
                int cnt = 0;
                while (xorValue)
                {
                    cnt += xorValue & 1;
                    xorValue >>= 1;
                }
                if (cnt % 2 == 0)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

void solve()
{
    int A[] = {1, 2};
    int B[] = {3};
    int C[] = {2, 3};
    int len1 = sizeof(A) / sizeof(A[0]);
    int len2 = sizeof(B) / sizeof(B[0]);
    int len3 = sizeof(C) / sizeof(C[0]);

    int result = countEvenSetBitTriplets(A, len1, B, len2, C, len3);
    cout << "Number of triplets with an even number of set bits after XOR: " << result << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int _t;cin >> _t;while (_t--)
    solve();
}
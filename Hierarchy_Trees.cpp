#include <iostream>
#include <vector>
#define MOD 100000007

using namespace std;

// Precompute BST counts up to 1000 nodes
vector<int> precomputeBSTCounts(int maxN) {
    vector<int> bst_count(maxN + 1, 0);
    bst_count[0] = 1;
    bst_count[1] = 1;
    
    for (int n = 2; n <= maxN; n++) {
        for (int i = 0; i < n; i++) {
            bst_count[n] = (bst_count[n] + ((long long)bst_count[i] * bst_count[n - 1 - i]) % MOD) % MOD;
        }
    }
    return bst_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcases;
    cin >> testcases;

    // Precompute BST counts for up to 1000 nodes
    vector<int> bst_count = precomputeBSTCounts(100100);

    // Process each test case
    while (testcases--) {
        int n;
        cin >> n;
        cout << bst_count[n] << endl;
    }

    return 0;
}

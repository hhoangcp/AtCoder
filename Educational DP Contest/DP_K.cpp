/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, a[106];
bool dp[100006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];

    dp[0] = false;
    for(int i=1; i<=k; ++i) {
        dp[i] = true;

        for(int j=1; j<=n; ++j)
        if (i >= a[j]) dp[i] &= dp[i-a[j]];

        dp[i] = !dp[i];
    }

    if (dp[k]) cout << "First"; else cout << "Second";

    return 0;
}

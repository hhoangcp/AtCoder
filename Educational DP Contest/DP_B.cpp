/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, k, h[100006];
llong dp[100006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> k;
    for(int i=1; i<=n; ++i) {
        cin >> h[i]; dp[i] = 1e18;

        if (i == 1) dp[i] = 0;
        for(int j=i-1; j>=max(1, i-k); --j) dp[i] = min(dp[i], dp[j] + abs(h[j] - h[i]));
    }

    cout << dp[n];

    return 0;
}

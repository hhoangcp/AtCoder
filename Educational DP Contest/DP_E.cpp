/// hhoangcpascal
/// DP - relable

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[100006];
int n, W;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    for(int i=1; i<=100000; ++i) dp[i] = 1e18;

    cin >> n >> W;
    while (n--) {
        int w, v; cin >> w >> v;
        for(int i=100000; i>=v; --i)
        if (dp[i-v] < 1e18) dp[i] = min(dp[i], dp[i-v] + w);
    }

    for(int i=100000; i>=0; --i)
    if (dp[i] <= W) {
        cout << i;
        break;
    }

    return 0;
}

/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, W;
llong dp[100006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> W;
    while (n--) {
        int w, v; cin >> w >> v;
        for(int i=W; i>=w; --i) dp[i] = max(dp[i], dp[i-w] + v);
    }

    cout << dp[W];

    return 0;
}

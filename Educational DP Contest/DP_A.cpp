/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, h[100006];
llong dp[100006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> h[i];

        if (i == 2) dp[i] = abs(h[i] - h[1]);
        else if (i >= 3) dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]), dp[i-2] + abs(h[i-2] - h[i]));
    }

    cout << dp[n];

    return 0;
}

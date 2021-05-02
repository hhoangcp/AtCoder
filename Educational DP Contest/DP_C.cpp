/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n;
llong dp[100006][3];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) {
        int a, b, c; cin >> a >> b >> c;

        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a;
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b;
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c;
    }

    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]);

    return 0;
}

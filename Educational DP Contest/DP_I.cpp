/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define ldouble long double

using namespace std;

ldouble dp[3006][3006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;
    for(int i=1; i<=n; ++i) {
        double p; cin >> p;

        if (i == 1) dp[1][0] = 1 - p, dp[1][1] = p;
        else {
            dp[i][0] = dp[i-1][0] * (1 - p);
            for(int j=1; j<=i; ++j)
                dp[i][j] = dp[i-1][j] * (1 - p) + dp[i-1][j-1] * p;
        }
    }

    ldouble res = 0;
    for(int i=(n+1)/2; i <= n; ++i) res += dp[n][i];

    (cout << fixed).precision(12);
    cout << res;

    return 0;
}

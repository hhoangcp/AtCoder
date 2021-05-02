/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

const int mod = 1e9+7;
llong dp[100006], pre[100006];
int n, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    dp[0] = 1;

    for(int i=1; i<=n; ++i) {
        int a; cin >> a;

        pre[0] = dp[0];
        for(int j=1; j<=k; ++j) pre[j] = (pre[j-1] + dp[j]) % mod;

        for(int j=0; j<=k; ++j)
        if (j > a) dp[j] = (pre[j] - pre[j-a-1] + mod) % mod; else dp[j] = pre[j] % mod;
    }

    cout << dp[k];

    return 0;
}

/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define getbit(state, i) ((state >> (i-1)) & 1)
#define llong long long

using namespace std;

llong dp[100006], sum[100006];
int a[18][18], n;

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j) scanf("%d", &a[i][j]);

    for(int state=0; state<(1<<n); ++state) {
        for(int i=1; i<=n; ++i)
        if (getbit(state, i))
            for(int j=i+1; j<=n; ++j)
            if (getbit(state, j)) sum[state] += a[i][j];

        dp[state] = sum[state];
        for(int t = state; t > 0; t = (t - 1) & state)
            dp[state] = max(dp[state], sum[t] + dp[state ^ t]);
    }

    cout << dp[(1<<n) - 1];

    return 0;
}

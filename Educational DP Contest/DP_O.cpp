/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
int dp[22][2097156];
int a[22][22], n;
bool avail[22][2097156];

int DP(int i, int state) {
    if (state == (1<<n) - 1) return 1;
    if (i > n) return 0;

    if (avail[i][state]) return dp[i][state];
    avail[i][state] = true;

    for(int j=1; j<=n; ++j)
    if (a[i][j] == 1 && ((state >> (j-1)) & 1) == 0) {
        int new_state = state | (1 << (j-1));
        dp[i][state] = (dp[i][state] + DP(i+1, new_state)) % mod;
    }

    return dp[i][state];
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j) scanf("%d", &a[i][j]);

    cout << DP(1, 0);

    return 0;
}

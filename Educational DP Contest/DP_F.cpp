/// hhoangcpascal

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, dp[3006][3006];
int trace[3006][3006];
char S1[3006], S2[3006], ans[3006];

int main() {
    scanf("%s%s", S1+1, S2+1);
    n = strlen(S1+1), m = strlen(S2+1);

    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j) {
        if (S1[i] == S2[j]) dp[i][j] = dp[i-1][j-1] + 1, trace[i][j] = 0;
        else if (dp[i][j-1] > dp[i-1][j]) trace[i][j] = 1, dp[i][j] = dp[i][j-1];
        else trace[i][j] = 2, dp[i][j] = dp[i-1][j];
    }

    int len = dp[n][m];
    while (n > 0 && m > 0) {
        if (trace[n][m] == 0) {
            ans[len--] = S1[n--];
            --m;
        } else if (trace[n][m] == 1) --m;
        else --n;
    }

    cout << ans+1;

    return 0;
}

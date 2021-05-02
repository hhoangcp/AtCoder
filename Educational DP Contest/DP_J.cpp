/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define ldouble long double

using namespace std;

ldouble dp[306][306][306];
int n, num[3];
bool visited[306][306][306];

ldouble DP(int A, int B, int C) {
    if (A == 0 && B == 0 && C == 0) return 0;
    if (visited[A][B][C]) return dp[A][B][C];

    int del = A + B + C;
    ldouble &cur = dp[A][B][C]; visited[A][B][C] = true;

    cur = 1.0L * n / del;

    if (A > 0) cur += (1.0L * A / del) * DP(A-1, B, C);
    if (B > 0) cur += (1.0L * B / del) * DP(A+1, B-1, C);
    if (C > 0) cur += (1.0L * C / del) * DP(A, B+1, C-1);

    return dp[A][B][C];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) {
        int a; cin >> a; --a;
        ++num[a];
    }

    (cout << fixed).precision(15);
    cout << DP(num[0], num[1], num[2]);

    return 0;
}

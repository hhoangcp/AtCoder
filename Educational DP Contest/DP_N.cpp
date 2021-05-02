/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[406][406], S[406];
bool visited[406][406];
int n;

llong getS(int l, int r) {
    if (l == 0) return S[r];
    return S[r] - S[l-1];
}

llong DP(int l, int r) {
    if (l >= r) return 0LL;
    if (visited[l][r]) return dp[l][r];

    llong &cur = dp[l][r] = 1e18; visited[l][r] = true;
    for(int i=l; i<r; ++i) cur = min(cur, getS(l, i) + getS(i+1, r) + DP(l, i) + DP(i+1, r));

    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) {
        int a; cin >> a;
        S[i] = S[i-1] + a;
    }

    cout << DP(1, n);

    return 0;
}

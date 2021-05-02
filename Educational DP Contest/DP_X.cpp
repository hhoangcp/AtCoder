/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Data {
    int w, s, v;

    bool operator < (const Data &other) const {
        return w + s < other.w + other.s;
    }
} P[1006];

llong dp[20006];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) cin >> P[i].w >> P[i].s >> P[i].v;

    sort(P+1, P+n+1);

    for(int i=1; i<=n; ++i)
    for(int j=P[i].s; j>=0; --j) dp[j+P[i].w] = max(dp[j+P[i].w], dp[j] + P[i].v);

    llong res = 0;
    for(int i=0; i<=P[n].s + P[n].w; ++i) res = max(res, dp[i]);

    cout << res;

    return 0;
}

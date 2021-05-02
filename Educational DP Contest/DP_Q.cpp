/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong BIT[200006];
int n, h[200006];

void update(int u, llong val) {
    for(; u <= n; u += (u & (-u))) BIT[u] = max(BIT[u], val);
}

llong query(int u) {
    llong val = 0;
    for(; u > 0; u -= (u & (-u))) val = max(val, BIT[u]);
    return val;
}

int main() {
    llong res = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &h[i]);

    for(int i=1; i<=n; ++i) {
        int a; scanf("%d", &a);

        llong best = query(h[i]-1) + a;
        res = max(res, best);
        update(h[i], best);
    }

    cout << res;

    return 0;
}

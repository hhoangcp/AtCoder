/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

vector<int> V[100006];
vector<llong> dp[100006];
int n, m, lab[100006];

llong DFS(int u) {
    llong tmp = 1;

    for(int i=0; i<(int) V[u].size(); ++i) {
        int v = V[u][i];

        if (lab[u] != v) {
            lab[v] = u;
            dp[u][i] = DFS(v);

            tmp = (tmp * (dp[u][i] + 1)) % m;
        }
    }

    return tmp;
}

void Rev(int u, llong del) {
    for(int i=0; i<(int) V[u].size(); ++i) {
        int v = V[u][i];

        if (lab[u] == v) {
            dp[u][i] = del;
            break;
        }
    }

    int sz = V[u].size();
    vector<llong> pre(sz, 0LL), suf(sz, 0LL);
    for(int i=0; i < sz; ++i) suf[i] = pre[i] = (dp[u][i] + 1) % m;
    for(int i=1; i < sz; ++i) pre[i] = pre[i-1] * pre[i] % m;
    for(int i=sz-2; i>=0; --i) suf[i] = suf[i+1] * suf[i] % m;

    for(int i=0; i<sz; ++i) {
        int v = V[u][i];
        if (lab[u] == v) continue;

        llong del_v = 1LL;
        if (i > 0) del_v = del_v * pre[i-1] % m;
        if (i < sz - 1) del_v = del_v * suf[i+1] % m;

        Rev(v, del_v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;

        V[u].push_back(v);
        V[v].push_back(u);
    }

    for(int u=1; u<=n; ++u) dp[u].assign(V[u].size(), 0LL);

    DFS(1), Rev(1, 0);

    for(int u=1; u<=n; ++u) {
        llong res = 1;
        for(llong del: dp[u]) res = res * (del + 1) % m;
        cout << res << '\n';
    }

    return 0;
}

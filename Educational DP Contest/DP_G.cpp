/// hhoangcpascal
/// DP on DAG

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V_inv[100006];
int n, m, dp[100006];
bool visited[100006];

int DFS(int u) {
    if (visited[u]) return dp[u];

    dp[u] = 0; visited[u] = true;
    for(int v: V_inv[u]) dp[u] = max(dp[u], DFS(v) + 1);

    return dp[u];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        V_inv[v].push_back(u);
    }

    int res = 0;
    for(int u=1; u<=n; ++u)
    if (!visited[u]) res = max(res, DFS(u));

    cout << res;

    return 0;
}

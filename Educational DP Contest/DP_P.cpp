/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

vector<int> V[100006];
const int mod = 1e9+7;
llong dp[100006][2];
int n;
bool visited[100006];

void DFS(int u) {
    visited[u] = true;
    dp[u][0] = dp[u][1] = 1;

    for(int v: V[u])
    if (!visited[v]) {
        DFS(v);

        dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % mod;
        dp[u][1] = dp[u][1] * dp[v][0] % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;

        V[u].push_back(v);
        V[v].push_back(u);
    }

    DFS(1);
    cout << (dp[1][0] + dp[1][1]) % mod;

    return 0;
}

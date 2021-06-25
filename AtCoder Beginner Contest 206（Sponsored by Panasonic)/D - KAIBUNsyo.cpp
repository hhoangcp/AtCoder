/// hhoangcpascal

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> V[200006];
int n, a[200006], res = 0;
bool visited[200006];

void DFS(int u) {
    visited[u] = true; ++res;

    for(int v: V[u])
    if (!visited[v]) DFS(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 1; i <= n; ++i)
    if (i != n - i + 1) {
        V[a[i]].push_back(a[n-i+1]);
        V[a[n-i+1]].push_back(a[i]);
    }

    for(int i = 1; i <= n; ++i)
    if (!visited[a[i]]) {
        DFS(a[i]);
        --res;
    }

    cout << res;

    return 0;
}

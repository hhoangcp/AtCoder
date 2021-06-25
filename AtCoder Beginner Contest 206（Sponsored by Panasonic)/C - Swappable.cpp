/// hhoangcpascal

#include <iostream>
#include <algorithm>
#include <map>
#define llong long long

using namespace std;

llong ans = 0;
map<int, int> M;
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int a; cin >> a;

        if (!M.count(a)) M[a] = 1;
        else ans += M[a]++;
    }

    ans = 1LL * n * (n - 1) / 2 - ans;
    cout << ans;

    return 0;
}

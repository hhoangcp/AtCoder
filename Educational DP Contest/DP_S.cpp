/// hhoangcpsacal

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
int dp[10006][106][2], n, d;
char S[10006];
bool visited[10006][106];

int DP(int cur, int sum, int eq) {
    if (cur == 0) return sum == 0;
    if (eq == 0 && visited[cur][sum]) return dp[cur][sum][0];

    int &del = dp[cur][sum][eq] = 0;
    if (eq == 0) {
        visited[cur][sum] = true;
        for(int i=0; i<=9; ++i) del = (del + DP(cur-1, (sum+i) % d, 0)) % mod;
    } else for(int i=0; i<=(int) S[cur]-'0'; ++i) del = (del + DP(cur-1, (sum+i)%d, (int) i == (int) S[cur]-'0')) % mod;

    return dp[cur][sum][eq];

}

int main() {
    scanf("%s%d", S+1, &d); n = strlen(S+1);
    reverse(S+1, S+n+1);

    int res = 0;
    for(int i=0; i<=(int) S[n] - '0'; ++i) res = (res + DP(n-1, i % d, (int) i == (int) S[n] - '0')) % mod;

    res = (res - 1 + mod) % mod;
    cout << res;

    return 0;
}

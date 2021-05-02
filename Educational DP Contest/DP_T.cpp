/// hhoangcpascal

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;
int f[3006], n, tmp[3006];
char S[3006];

int main() {
    scanf("%d%s", &n, S+2);

    f[1] = 1;
    for(int i=2; i<=n; ++i) {
        for(int j=0; j<=n+1; ++j) tmp[j] = f[j], f[j] = 0;

        if (S[i] == '<')
            for(int j=2; j<=i; ++j) f[j] = (f[j-1] + tmp[j-1]) % mod;
        else
            for(int j=i-1; j>=1; --j) f[j] = (f[j+1] + tmp[j]) % mod;
    }

    int res = 0;
    for(int i=1; i<=n; ++i) res = (res + f[i]) % mod;

    cout << res;

    return 0;
}

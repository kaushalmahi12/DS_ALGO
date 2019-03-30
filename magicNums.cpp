#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m, d;
char a[2007], b[2007];
int len;
int dp[2007][2007][2][2];
const int MOD = 1e9 + 7;
int dfs(int p, int r, int x, int y) {
	// cout << p << " " << r << " " << x << " " << y << endl;
	if (p == len) return r == 0;
	int &ret = dp[p][r][x][y];
	if (ret != -1) return ret;
	ret = 0;
	int L = x == 1 ? a[p] - '0' : 0;
	int R = y == 1 ? b[p] - '0' : 9;
	for (int i = L; i <= R; ++ i) {
		if ((p & 1) && i != d) continue;
		if (!(p & 1) && i == d) continue;
		ret += dfs(p + 1, (r * 10 + i) % m, x && i == L, y && i == R);
		if (ret >= MOD) ret -= MOD;
	}
	return ret % MOD;
}
int main() {
	scanf("%d%d%s%s", &m, &d, a, b);
	len = strlen(a);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(0, 0, 1, 1));
}
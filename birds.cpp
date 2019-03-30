#include<iostream>
#include<cstring>
using namespace std;
const int mx = 1e4 + 2;
long long c[mx], cost[mx];
long long X, W, B, n;
long long dp[mx/10 + 1][mx];

int main() {
    cin >> n >> W >> B >> X;
    for (int i=0; i<n; i++) cin >> c[i];
    for (int i=0; i<n; i++) cin >> cost[i];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = W;
    for (int i=0; i<n; i++) {
        for (int j=0; dp[i][j]!=-1 && j<=10000; j++) {
            for (int k=0; k<=c[i] && (dp[i][j]-k*cost[i])>=0; k++) {
                dp[i+1][j+k] = max(dp[i+1][j+k], min(dp[i][j]-k*cost[i]+X, W+(k+j)*B));
            }
        }
    }
    int ans = 0;
    for (int j=0; j<mx; j++) if (dp[n][j]>=0) ans = j;
    cout << ans << "\n";
    return 0;
}
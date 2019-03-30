#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; 
    int dp[n+1][m+1];
    for (int i=0; i<=m; i++) dp[0][i] = 0;
    for (int i=0; i<=n; i++) dp[i][0] = 0;
    string s;
    for (int i=1; i<=n; i++) {
        cin >> s;
        for (int j=1; j<=m; j++) {
            dp[i][j] = s[j-1]-'0';
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            for (int k=i; k<=n; k++) {
                for (int l=j; l<=m; l++) {
                    int isOk = !(dp[k][l] - dp[k][j-1] - dp[i-1][l] + dp[i-1][j-1]); 
                    if (isOk) {
                        ans = max(ans, 2*(k-i+1 + l-j+1));
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
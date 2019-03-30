#include<iostream>
using namespace std;

int main() {
    int n, d;
    string s;
    cin >> n >> d >> s;
    // cout << s << "\n";
    int dp[n+1];
    for (int i=0; i<=n; i++) dp[i] = 1234567890;
    dp[0] = dp[1] = 0;
    for (int i=1; i<=n; i++) {
        if (s[i-1] == '1') {
            for (int j=max(1, i-d); j<i; j++) {
                if (s[j-1] == '1') {
                    // cout << i << " " << j << " " << dp[j] << "\n"; 
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
    }
    cout << (dp[n] == 1234567890 ? -1 : dp[n]) << "\n";
    return 0;
}
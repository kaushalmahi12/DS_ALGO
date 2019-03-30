#include<iostream>
using namespace std;
int f[5003][5003];
bool dp[5001][5001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        dp[i][i]=true;
        f[i][i]=1;
        if (i+1 < s.size() and s[i]==s[i+1]) dp[i][i+1] = true, f[i][i+1]=3;
        else if (i+1<s.size()) f[i][i+1] = 2;
    }
    int q;
    cin >> q;
    for (int l=3; l<=s.size(); l++) {
        for (int i=0; i<s.size()-l+1; i++) {
            int j = i+l-1;
            if (s[i]==s[j] and dp[i+1][j-1]) {
                dp[i][j]=true;
            }
            f[i][j] = f[i][j-1] + f[i+1][j] - f[i+1][j-1] + dp[i][j];
            // cout << i << " " << j << " : " << f[i][j] << "\n";
        }
    }
    // for (int i=1; i<=s.size(); i++) f[i] += f[i-1];
    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << (f[l-1][r-1]) << "\n";
    }
    return 0;
}
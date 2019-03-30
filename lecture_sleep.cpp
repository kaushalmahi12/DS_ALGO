#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long a[n+1], a_[n+1];
    int t[n];
    a[0] = a_[0] = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i+1];
        a[i+1] += a[i];
        a_[i+1] = 0;
    }
    long ans = 0;
    for (int i=0; i<n; i++) {
        cin >> t[i];
        // t[i+1] += t[i];
        if (t[i]) ans += (a[i+1]-a[i]);
        else a_[i+1] += (a[i+1]-a[i]);
        a_[i+1] += a_[i];
        // cout << a_[i+1] << " \n"[i==n-1];
    }
    // cout << ans << "\n";
    long total = ans;
    for (int i=1; i<=n-k+1; i++) {
        ans = max(ans, total + a_[i+k-1] - a_[i-1]);
        // cout << i << " : " << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}
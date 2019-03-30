#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, u;
    cin >> n >> u;
    ll E[n];
    for (int i=0; i<n; i++) {
        cin >> E[i];
    }
    
    ll i=0, j = 1;
    long double eff = 0, eps = 1e-9;
    while (i < n) {
        while (j<n and E[j]-E[i]<u) {
            j++;
        }
        if (j==n) j--;
        if (j-i+1 >= 3) {
            // cout << i << " " << j << " " << E[j]-E[i];
            if (E[j]-E[i] <= u) {
                long double tmp = 1.0f * (E[j]-E[i+1]) / (E[j]-E[i]);
                if (eps + eff < tmp ) eff = tmp;
            }
            if (E[j-1]-E[i] <= u and (j-i)>=3) {
                long double tmp = 1.0f * (E[j-1]-E[i+1]) / (E[j-1]-E[i]);
                if (eps + eff < tmp ) eff = tmp;
            }
            // cout << " " << eff  << "\n";
        }
        i++;
    }
    if (eff == 0.0f) eff = -1.0;
    printf("%.12Lf\n", eff);
    return 0;
}
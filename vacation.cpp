#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int evg=0,oddg=0,evs=0,odds=0, bothe=0, bothodd=0;
    for (int i=0;i<n; i++) {
        if (i&1) {
            evg += a[i]&1;
            evs += (a[i]>>1)&1;
            if ((a[i]&3) ==3) bothe++;
        } else {
            oddg +=a[i]&1;
            odds += (a[i]>>1)&1;
            if ((a[i]&3)==3) bothodd++;
        }
    }
    // cout << evg << " " << evs << " "<<bothe << "\n";
    // cout << oddg << " " << odds << " "<<bothodd << "\n";
    int ans = (n-(oddg+odds-bothodd));
    ans = min(ans, n-(evs+evg-bothe));
    ans = min(ans, n-(evs+oddg));
    ans = min(ans, n-(evg+odds));
    cout << ans <<"\n";
    return 0;
}
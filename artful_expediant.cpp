#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a(n), b(n);
    for (int& x: a) {
        cin >> x;
        mp[x] = 1;
    }
    for (int& y: b) {
        cin >> y;
        mp[y] = 1;
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (mp.count(a[i]^b[j])) cnt++; 
        }
    }
    // cout << cnt << "\n";
    if (cnt & 1) {
        cout << "Koyomi\n";
    } else {
        cout << "Karen\n";
    }
    return 0;
}
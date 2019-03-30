#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, j=0; 
    cin >> n;
    string s;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    cin >> s;
    for (int i=0; i+1<n; i++) {
        if (s[i]=='0') continue;
        j = max(i+1, j);
        bool ch = false;
        while (j<n and s[j-1]=='1') {
            j++;
            ch = true;
        }
        if (ch) sort(a+i, a+j);
        // i = max(i+1, j);
    }
    if (is_sorted(a, a+n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
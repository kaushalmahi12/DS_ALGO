#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> st;
    int ans = 0;
    for (int i=0; i<n; i++) {
    	if (s[i]>='A' and s[i]<='Z') {
    		ans = max(ans, (int)st.size());
    		st.clear();
    	} else {
    		st.insert(s[i]);
    	}
    }
    if (st.size() > 0) ans = max(ans, (int)st.size());
    cout << ans << endl;
    return 0;
}
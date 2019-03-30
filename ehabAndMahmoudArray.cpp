#include<bits/stdc++.h>

using namespace std;
const int mx = 2e6 + 5;
vector<int> mul[mx];
bool prime[mx], erased[mx];
int main() {
    int n;
    cin >> n;
    set<int> poss;
    for (int i=2; i<mx; i++) {
        if (!prime[i]) {
        	for (int j=i; j<mx; j+=i) {
        		prime[j] = 1;
        		mul[j].push_back(i);
        	}
        }
        poss.insert(i);
    }
    bool gt = true;
    while (n--) {
    	int in;
    	cin >> in;
    	int out = *poss.begin();
    	if (gt) {
    		out = *poss.lower_bound(in);
    		if (out != in) gt = false;
    	}
    	
    	cout << out << " ";
    	for (int u: mul[out]) {
    		for (int v=u; v<mx; v+=u)
    		if (!erased[v]) {
    			poss.erase(v);
    			erased[v] = true;
    		}
    	}
    }
    return 0;
}
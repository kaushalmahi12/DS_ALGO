#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int nax = (int)1e3 + 5;
int par[nax][23], mx[nax][23], level[nax];
int LG;
vector<pair<int, int> > g[nax];

void dfs(int s, int p, int w) {
    par[s][0] = p, mx[s][0] = w;
    for (int lg=1; lg<LG; lg++) {
        if (par[s][lg-1] != 0) {
            par[s][lg] = par[par[s][lg-1]][lg-1];
            mx[s][lg] = max(mx[s][lg], max(mx[par[s][lg-1]][lg-1], mx[s][lg-1]));
            // cout << (1<<lg) << "th parent of " << s << " is " << par[s][lg] << "\n";
            // cout << "max from " << s << " to " << par[s][lg] << " is " << mx[s][lg]  << "\n";
        }
    }

    for (auto& x: g[s]) {
        int v = x.first, w_ = x.second;
        if (p != v) {
            level[v] = level[s] + 1;
            dfs(v, s, w_);
        }
    }
}

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);
    // cout << level[u] << " " << level[v] << "\n";
    int diff = level[u] - level[v];
    for (int i=LG; i>=0; i--) {
        if (diff & (1<<i)) {
            u = par[u][i];
        }
    }
    if(u == v) return u;
    for (int i=LG; i>=0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i], v = par[v][i];
        }
    }
    return par[u][0];
}

// u -> from, v -> to
int max_query(int u, int v) {
    if (level[u] < level[v]) swap(u, v);
    int diff = level[u] - level[v];
    int ans = 0;
    for (int i=LG; i>=0; i--) {
        if (diff & (1<<i)) {
            ans = max(ans, mx[u][i]);
            u = par[u][i];
        }
    }
    if(u == v) return ans;
    for (int i=LG; i>=0; i--) {
        if (par[u][i] != par[v][i]) {
            ans = max(ans, max(mx[u][i], mx[v][i]));
            u = par[u][i], v = par[v][i];
        }
    }
    return max(ans, mx[u][0]);
}

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    while ((1 << LG) < n) LG += 1;
    dfs(1, 0, 0);
    cin >> u >> v;
    while (u != -1) {
        int _lca = lca(u, v);
        int ans = max(max_query(u, _lca), max_query(v, _lca));
        cout << _lca << " max: " << ans << "\n";

        cin >> u >> v;
    }
    return 0;
}
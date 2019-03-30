#include<bits/stdc++.h>
using namespace std;

struct rmq {
    vector<int> a;
    vector<int> tr1, tr2;
    int n;
    rmq(vector<int> b) {
        n = b.size();
        a = b;
        tr1.resize(4*n);
        tr2.resize(4*n);
        build(1, 0, n-1);
    }
    
    int getSize(int x) {
        int i=1;
        while (i<<1 <= n) i<<=1;
        return i<<1;
    }
    
    bool f1(int i, int j) {
        return a[i] < a[j];
    }
    
    bool f2(int i, int j) {
        return a[i] > a[j];
    }
    
    void build(int node, int l, int r) {
        if (l==r) {
            tr1[node] = tr2[node] = l;
            return;
        }
        int left = node<<1, right = left|1;
        build(left, l, (l+r)>>1);
        build(right, ((l+r)>>1) + 1, r);
        tr1[node] = f1(tr1[node<<1], tr1[(node<<1)|1]) ? tr1[left] : tr1[right];
        tr2[node] = f2(tr2[node<<1], tr2[(node<<1)|1]) ? tr2[left] : tr2[right];
    }
    
    int mn(int l, int r) {
        return mn(1, 0, n-1, l, r);
    }
    
    int mx(int l, int r) {
        return mx(1, 0, n-1, l, r);
    }
    
    int mn(int p, int l, int r, int i, int j) {
        if (i>r || j<l) return -1;
        if (i<=l and j>=r) return tr1[p];
        int left = p << 1, right = left|1, mid = (l+r)>>1;
        int lans = mn(left, l, mid, i, j);
        int rans = mn(right, mid+1, r, i, j);
        if (lans != -1 and rans!=-1) {
            return f1(lans, rans) ? lans : rans;
        } else if(lans == -1) return rans;
        else return lans;
    }
    
    int mx(int p, int l, int r, int i, int j) {
        if (i>r || j<l) return -1;
        if (i<=l and j>=r) return tr2[p];
        int left = p << 1, right = left|1, mid = (l+r)>>1;
        int lans = mx(left, l, mid, i, j);
        int rans = mx(right, mid+1, r, i, j);
        if (lans != -1 and rans!=-1) {
            return f2(lans, rans) ? lans : rans;
        } else if(lans == -1) return rans;
        else return lans;
    }
};

int main() {
    vector<int> a;
    srand(time(0));
    for (int i=0; i<10; i++) {
        a.push_back((rand()%100 + 1));
        cout << a.back() << " ";
    }
    cout << "\n";
    rmq ds(a);
    for (int i=0; i<10; i++) {
        int l = rand()%10;
        int r = rand()%10;
        if (l > r) swap(l, r);
        int mn = rand()%2;
        if (mn) {
            cout << "min from " << l+1 << " to " << r+1 << " is " << a[ds.mn(l, r)] << "\n"; 
        } else {
            cout << "max from " << l+1 << " to " << r+1 << " is " << a[ds.mx(l, r)] << "\n"; 
        }
    }
    return 0;
}
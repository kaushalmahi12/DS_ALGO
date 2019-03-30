#include<fstream>
#include<vector>
#include<queue>
using namespace std;

vector<int> suc[100002];
int n;
int pred[100002], result[100002];
vector<pair<int,int> > edge[50004];

bool can(int k) {
    for (int i=0; i<n; i++) {
        pred[i] = 0;
        suc[i].clear();
    }

    for (int i=0; i<k; i++) {
        for (auto it: edge[i]) {
            suc[it.first].push_back(it.second);
            pred[it.second]++;
        }
    }
//   std::cout << "done here\n";
    priority_queue<int> q;
    for (int i=0; i<n; i++) {
        if(pred[i] == 0) q.push(-i);
    }
    int i=0;
    while(i<n) {
        if(q.empty()) return false;
        int top = -q.top();
        q.pop();
        result[i++] = top;
        for (int it: suc[top]) {
            pred[it]--;
            if (pred[it]==0) {
                q.push(-it);
            }
        }
    }
    return true;
}


int main() {
  int m;
   ifstream cin("milkorder.in");
   ofstream cout("milkorder.out");
   cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int d;
    cin >> d;
    int last;
    for (int j = 0; j < d; j++) {
      int e;
      cin >> e;
      e--;
      if (j > 0) {
        edge[i].push_back(make_pair(last, e));
      }
      last = e;
    }
  }

  // Binary search
  // Invariant: lo <= ans < hi
  int lo = 0;
  int hi = m+1;
  while (hi > lo+1) {
    int mid = (lo + hi) / 2;
    if (can(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  int ans = lo;

  // Run this again, to get the answer
  // into the `result` array.
  can(ans);

  for (int i = 0; i < n; i++) {
      cout << result[i]+1 << " \n"[i==n-1];
  }
  return 0;
}

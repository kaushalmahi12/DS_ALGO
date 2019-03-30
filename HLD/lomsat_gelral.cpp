#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e5+12;
int n,col[maxn],sz[maxn],maxx,cnt[maxn];
long long ans[maxn],can;
bool badboy[maxn];
vector<int>g[maxn];
void computeSubtreeSize(int v=0,int p=-1){
  sz[v]=1;
  for(auto &u:g[v])
    if(u!=p)computeSubtreeSize(u,v),sz[v]+=sz[u];
}

void relax(int x){
  if(maxx<++cnt[x])
    maxx=cnt[x],can=x;
  else if(maxx==cnt[x])
    can+=x;
}
void merge(int v,int p=-1){
  relax(col[v]);
  for(auto &u:g[v])
    if(u!=p && !badboy[u])
      merge(u,v);
}
void remove(int v,int p=-1){
  cnt[col[v]]--;
  for(auto &u:g[v])
    if(u!=p && !badboy[u])
      remove(u,v);
}
void dfs(int v=0,int p=-1,bool hrh=0){//HRH?! mipasandam!
  int mx=0,big=-1;
  for(auto &u:g[v])
    if(u!=p && sz[u]>mx)
      mx=sz[u],big=u;
  for(auto &u:g[v])
    if(u!=p && u!=big)
      dfs(u,v,1);
  if(big+1)
    dfs(big,v),badboy[big]=1;
  merge(v,p);
  if(big+1)
    badboy[big]=0;
  ans[v]=can;
  if(hrh)
    remove(v,p),maxx=can=0;
}
int main(){
  scanf("%d",&n);
  for_each(col,col+n,[](int &x){scanf("%d",&x);});
  for(int i=1,v,u;i<n;i++)scanf("%d%d",&v,&u),g[--v].pb(--u),g[u].pb(v);
  computeSubtreeSize(),dfs();
  for_each(ans,ans+n,[](long long &x){printf("%lld ",x);});putchar('\n');
  return 0;
}
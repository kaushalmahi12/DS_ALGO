#include <bits/stdc++.h>
using namespace std;

#define LL long long

#define maxn 20100
#define INF 0x33333333

int v[maxn];

int main()
{
    freopen("B-small-practice.in", "r", stdin);
    int t, cas = 0;
    scanf("%d", &t);
    while(t--){
        cas++;
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }
        sort(v, v + n);
        double ans = 0;

        auto f = [](double a, double b){return a + b;};
        double s = accumulate(v, v + n, 0.0, f);
        double mid = (n & 1) ? v[n / 2]: (v[n / 2] + v[n / 2 - 1]) / 2;
        double av = s * 1.0 / n;
        if(k == 0){
                ans = av;
        }else{
            double prev = av;
            for(int draw = 1; draw <= k; draw++){
                double cur = 0.0;
                for(int i = 0; i < n; i++){
                    if(v[i] <= prev){
                        cur += prev;
                    }else{
                        cur += v[i];
                    }
                }
                cur /= n;
                prev = cur;
            }
            ans = prev;
        }
        printf("Case #%d: %.6f\n", cas, ans);
    }
    return 0;
}
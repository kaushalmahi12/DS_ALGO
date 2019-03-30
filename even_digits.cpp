#include<bits/stdc++.h>
using namespace std;

#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",&a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define INF 1000000000000000000
vector<int> digits;
ll p10[20];
int main()
{
	// freopen("A1.in","r",stdin);
	// freopen("A1.out","w",stdout);
	int t,i;
	p10[0] = 1;
	for(i=1;i<18;i++)
		p10[i] = p10[i-1]*10;
	sd(t);
	for(int tt=1;tt<=t;tt++)
	{
		ll n, n1,l = 0, r = 0;
		digits.clear();
		sl(n);
		n1 = n;
		while(n>0)
		{
			digits.PB(n%10);
			n/=10;
		}
		for(i=(int)digits.size()-1;i>=0;i--)
		{
			if(digits[i]&1)
				break;
			l += digits[i]*p10[i];
			r += digits[i]*p10[i];
		}
		if(i>=0)
		{
			l += (digits[i]-1)*p10[i];
			r += (digits[i]+1)*p10[i];
			if(digits[i] == 9)	r = INF;
			i--;
			for(;i>=0;i--)
				l += 8*p10[i];
		}
		ll ans = min(llabs(n1-l),llabs(n1-r));
		printf("Case #%d: %lld\n",tt,ans);
	}
}

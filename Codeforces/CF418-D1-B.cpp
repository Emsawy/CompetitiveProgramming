#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define sz(v)			((int)((v).size()))
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
#define clr(v,d)		memset(v, d, sizeof(v))
#define sf(x)			scanf("%d", &x)
#define sf2(x,y)		scanf("%d %d", &x, &y)
#define sf3(x,y,z)		scanf("%d %d %d", &x, &y, &z)
#define sfll(x)			scanf("%I64d", &x)
#define sfll2(x,y)		scanf("%I64d %I64d", &x, &y)
#define sfll3(x,y,z)		scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)		(atan2((a).imag(), (a).real()))
#define vec(a,b)		((b)-(a))
#define length(a)		(hypot((a).imag(), (a).real()))
#define dp(a,b)			((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)			((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)		(dp(vec(p1,p2),vec(p1,p2)) <= EPS)
#define rotate0(p,ang)		((p)*exp(Point(0,ang)))
#define rotateA(p,ang,about)	(rotate0(vec(about,p),ang)+about)
#define reflect0(v,m)		(conj((v)/(m))*(m))
#define normalize(a)		(a)/length(a)
#define lengthSqr(p)		dp(p,p)
#define pii			pair<int,int>
#define V			vector
#define MP			make_pair
#define X			real()
#define Y			imag()

typedef complex<double> 	point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-10;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
int n, m, k, t, c,b;
ll dp[1 << 20][2],save[100];


struct Node{
	int msk, rub, scr;
	Node(){
		msk = rub = scr = 0;
	}
	bool operator<(const Node & a) const {
		if (scr <= a.scr) return 0;
		return 1;
	}
};

int main()
{
	Emsawy();
	while (cin >> n >> m >> b){
		V < Node > v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i].rub >> v[i].scr >> t;
			for (int j = 0; j < t; j++){
				cin >> c;
				v[i].msk |= (1 << (c - 1));
			}
		}
		sort(all(v));
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < (1 << m) - 1; j++)
				dp[j][i] = 1.1e18;

		bool alt = 0;
		for (int nd = n - 1; nd >= 0; nd--){
			for (int msk = (1 << m) - 1; msk >= 0; msk--){
				dp[msk][alt] = min(dp[msk][!alt], dp[msk | v[nd].msk][!alt] + v[nd].rub);
			}
			save[nd] = dp[0][alt];
			alt = !alt;
		}
		ll ans = 1.1e18;
		for (int i = 0; i < n; i++)
			ans = min(ans, save[i] + v[i].scr * 1LL * b);
		if (ans == 1.1e18) ans = -1;
		cout << ans << endl;
	}
	return 0;
}

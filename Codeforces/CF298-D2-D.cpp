#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1e17;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<int> > adj;
const ll N = 4000 + 5;
int n, m, k, w;
string s;
int main() {

	Emsawy();
	while (cin >> n >> m >> k){
		bool l = 1, r = 1;
		V<int>a(n), b(m);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}	
		for (int i = 0; i < m; i++){
			cin >> b[i];
		}
		if (n > m ){
			cout << "YES" << endl;
			continue;
		}
		V<pair<int, int > > ord;
		for (int i = 0; i < n; i++){
			ord.push_back(MP(a[i], -1));
		}
		for (int i = 0; i < m; i++){
			ord.push_back(MP(b[i], 1));
		}
		sort(allr(ord));
		int now = 0, ok = 0;
		for (int i = 0; i < ord.size(); i++){
			now += ord[i].second;
			if (now < 0){
				ok = 1;
				break;
			}
		}
		if (ok)puts("YES");
		else puts("NO");
	}
	return 0;
}

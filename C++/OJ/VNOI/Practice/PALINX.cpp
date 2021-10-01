// https://oj.vnoi.info/problem/palinx
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7, BASE = 311;
const int N = 1e6 + 5;

typedef long long ll;

map <ll, int> suf, pre;
ll Pow[N], res = 0;
string s[N];
int n;

void buildPow()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Pow[0] = 1; 
	for (int i = 1; i < N; i++)
		Pow[i] = Pow[i - 1] * BASE % MOD;
}

struct HASH 
{
	vector <ll> h, H;
	int m;

	void init(string s) 
	{
		m = s.size(); s = " " + s;
		h.resize(m + 1); H.resize(m + 2);

		for (int i = 1; i <= m; i++) h[i] = (h[i - 1] * BASE + s[i]) % MOD;
		for (int i = m; i; i--)      H[i] = (H[i + 1] * BASE + s[i]) % MOD;
	}

	ll get1(int i, int j) {return (h[j] - h[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;}
	ll get2(int i, int j) {return (H[j] - H[i + 1] * Pow[i - j + 1] + MOD * MOD) % MOD;}
} H[N];


void init()
{
	buildPow(); cin >> n;
	for (int i = 1, m; i <= n; i++) 
	{
		cin >> m >> s[i];
		H[i].init(s[i]);
		for (int j = 1; j < m; j++)
			if (H[i].get1(1, j) == H[i].get2(j, 1)) 
				suf[H[i].get2(m, j + 1)]++;
		pre[H[i].get2(m, 1)]++;
	}
}

int solve() 
{
	init();
	for (int i = 1; i <= n; i++) 
	{
		int m = H[i].m;
		res += pre[H[i].get1(1, m)] + suf[H[i].get1(1, m)];
		for (int j = m - 1; j; j--) 
			if (H[i].get1(j + 1, m) == H[i].get2(m, j + 1)) 
				res += pre[H[i].get1(1, j)];
	}
	return cout << res, 0;
}

int main() {solve();}

// https://oj.vnoi.info/problem/dtksub
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long MOD = 503509, BASE = 31;

typedef long long ll;

string s, t;
int n, m;
ll Hash[N], Pow[N], cnt[N];

ll get(int i, int j)
{
	return (Hash[j] - Hash[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;
}

void buildpow_hash()
{
    Pow[0] = 1;
	for (int i = 1; i <= n; i++)
		Hash[i] = (Hash[i - 1] * BASE + s[i] - 'a' + 1) % MOD,
		Pow[i] = Pow[i - 1] * BASE % MOD;
}

bool ok(int x)
{
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n - x + 1; i++)
		if (++cnt[get(i, i + x - 1)] >= m)
			return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	s = " " + s;
	buildpow_hash();
	int l = 0, r = n, res = 0;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (ok(mid)) l = mid, res = mid;
		else r = mid - 1;
	}
	cout << res;
	return 0;
}

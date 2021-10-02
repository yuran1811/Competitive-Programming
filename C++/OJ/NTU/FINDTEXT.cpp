// http://ntucoder.net/Problem/Details/5548
#include <bits/stdc++.h>
#define sz(x) (int (x.size()))
using namespace std;

vector <int> KMP;
string s;
int n;

void KMP_Build(string s)
{
	KMP.resize(n, 0);
	for (int i = 1, k; i < n; i++)
	{
		k = KMP[i - 1];
		while (k && s[i] != s[k]) k = KMP[k - 1];
		if (s[i] == s[k]) k++;
		KMP[i] = k;
	}
}

int Use_KMP(string s)
{
	KMP_Build(s);
	vector <int> f(n + 1, 0);
	int MaxL = -1, Num = int (1e9 + 7);

	for (int i : KMP) f[i]++;
	for (int i = n - 1; i; i--) f[KMP[i - 1]] += f[i];
	for (int i = 1; i <= n / 2; i++)
		if (++f[i] <= Num)
			if (f[i] > 1 && f[i] + 1 != f[f[i] + 1])
				Num = f[i], MaxL = i;

	if (MaxL == -1) return cout << "0 1", 0;
	string res = s.substr(0, MaxL);
	for (int i = MaxL; i <= n - MaxL; i++)
		if (s.substr(i, MaxL) == res)
			return cout << MaxL << " " << i + 1, 0;
	return 0;
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s; n = s.size();
}

int Solve()
{
	Load_Data();
	Use_KMP(s);
	return 0;
}

int main() {Solve();}

// https://oj.vnoi.info/problem/votree
#include <bits/stdc++.h>
using namespace std;

const int N = 7e4 + 5, LOG = 20;

int par[N][LOG + 1], Min[N][LOG + 1], Max[N][LOG + 1];
int n, q, u, v, cnt = 0;
int high[N], label[N];
vector <int> a[N];

int TheSmall(int u, int v) {return label[u] < label[v] ? u : v;}
int TheLarge(int u, int v) {return label[u] > label[v] ? u : v;}
int GetMin(int l, int r) {int k = log2(r - l + 1); return TheSmall(Min[l][k], Min[r - (1 << k) + 1][k]);}
int GetMax(int l, int r) {int k = log2(r - l + 1); return TheLarge(Max[l][k], Max[r - (1 << k) + 1][k]);}

void dfs(int u)
{
	label[u] = ++cnt;
	for (int v : a[u])
		if (v != par[u][0])
		{
			high[v] = high[u] + 1;
			par[v][0] = u;
			dfs(v);
		}
}

void SPARSE_TABLE()
{
	high[0] = -1; dfs(1); 
	for (int i = 1; i <= n; i++) Min[i][0] = Max[i][0] = i;
	for (int j = 1; j <= LOG; j++)
	{
		for (int i = 1; i <= n; i++) par[i][j] = par[par[i][j - 1]][j - 1];
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			Min[i][j] = TheSmall(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]),
			Max[i][j] = TheLarge(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
	}
}

int lca(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);
	for (int i = LOG; i >= 0; i--)
		if (high[par[u][i]] >= high[v])
			u = par[u][i];
	if (u == v) return u;
	for (int i = LOG; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i], 
			v = par[v][i];
	return par[u][0];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q; 
	for (int i = 1; i < n; i++)
		cin >> u >> v, 
		a[u].push_back(v),
		a[v].push_back(u);
	SPARSE_TABLE();
	while (q--)
		cin >> u >> v, 
		cout << lca(GetMin(u, v), GetMax(u, v)) << '\n';
	return 0;
}

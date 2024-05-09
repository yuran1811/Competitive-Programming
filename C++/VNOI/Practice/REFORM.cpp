// https://oj.vnoi.info/problem/reform
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 5;

vector <int> a[N], Bridge;

int NumChild[N], C[N];
int Num[N], Low[N];
int Cpn, Cnt;
int n, m;

int mnz(int &a, int b) {return a > b ? a = b, 1 : 0;}

void DFS(int u, int p)
{
	Num[u] = Low[u] = ++Cnt;
	NumChild[u] = 1;
	++C[Cpn];

	for (int v : a[u]) 
	{
		if (v == p) continue;
		if (!Num[v])
		{
			DFS(v, u);
			mnz(Low[u], Low[v]);
			NumChild[u] += NumChild[v];
			if (Low[v] > Num[u]) Bridge.push_back(NumChild[v]);
		} else mnz(Low[u], Num[v]);
	}
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);
}

int Solve()
{
	Load_Data();
	for (int u = 1; u <= n; ++u)
		if (!Num[u])
		{
			if (++Cpn > 2) return cout << 0, 0;
			DFS(u, u);
		}

	if (Cpn == 1)
	{
		long long res = (1LL * n * (n - 1) / 2 - m) * (m - Bridge.size());
		for (int x : Bridge) res += 1LL * x * (n - x) - 1;   
		cout << res;
	} else cout << 1LL * C[1] * C[2] * (m - Bridge.size());
	return 0;
}

int main() {Solve();}

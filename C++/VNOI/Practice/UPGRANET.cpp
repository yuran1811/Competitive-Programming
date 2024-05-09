// https://oj.vnoi.info/problem/upgranet
#include <algorithm>
#include <iostream>
#include <vector>
#define fi first
#define se second
using namespace std;

typedef pair <int,int> pii;

const int N = 1e5 + 5, oo = 1e9 + 7, LOG = 19;

vector <pii> g[N];
pii p[N][LOG + 1];
int n, m, high[N];
bool MST[N];

int mnz(int &a, int b) {return a > b ? a = b, 1 : 0;}

struct Edge
{
	int u, v, w;
	bool operator < (const Edge &x) const {return w > x.w;}
};
vector <Edge> e;

struct DSU
{
	vector <int> f;
	void Init(int n) {f.assign(n + 5, -1);}
	int Root(int u) {return f[u] < 0 ? u : f[u] = Root(f[u]);}
	bool Mer(int u, int v)
	{
		u = Root(u), v = Root(v);
		if (u == v) return false;
		if (f[u] > f[v]) swap(u, v);
		f[u] += f[v], f[v] = u;
		return true;
	}
} dsu;

void DFS(int u)
{
	for (pii x : g[u])
    {
    	int v = x.fi, w = x.se;
    	if (v != p[u][0].fi)
	    {
	        high[v] = high[u] + 1;
	        p[v][0] = {u, w};
	        DFS(v);
	    }
	}
}

void Sparse_Table()
{
    DFS(1);
    high[0] = -1;
    for (int j = 1; j <= LOG; j++)
    	for (int i = 1; i <= n; i++)
	        p[i][j] = {p[p[i][j - 1].fi][j - 1].fi, min(p[i][j - 1].se, p[p[i][j - 1].fi][j - 1].se)};
}

int LCA(int u,int v)
{
    if (high[u] < high[v]) swap(u, v);
    int res = oo;
    for (int i = LOG; i >= 0; i--)
    	if (high[p[u][i].fi] >= high[v])
    	{
	        mnz(res, p[u][i].se);
	        u = p[u][i].fi;
	    }
    if (u == v) return res;

    for (int i = LOG; i >= 0; i--)
    	if (p[u][i].fi!=p[v][i].fi)
    	{
	        mnz(res, min(p[u][i].se, p[v][i].se));
	        u = p[u][i].fi;
	        v = p[v][i].fi;       
	    }
    mnz(res, min(p[u][0].se, p[v][0].se));
    return res;
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v, w; i <= m; i++)
		cin >> u >> v >> w,
		e.push_back({u, v, w});
	sort(e.begin(), e.end());
	
    dsu.Init(n);
	for (int i = 0; i < m; i++)
        if (dsu.Mer(e[i].u, e[i].v))
        {
            int u = e[i].u, v = e[i].v, w = e[i].w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        } else MST[i] = 1;
}

int Solve()
{
    Load_Data();
    Sparse_Table();
    long long res = 0;
    for (int i = 0; i < m; i++)
    	if (MST[i])
    	{
            int u = e[i].u, v = e[i].v, w = e[i].w;
	        res += LCA(u, v) - w;
	    }
    cout << res;
    return 0;
}

int main() {Solve();}

// http://ntucoder.net/Problem/Details/5589
#include <iostream>
#define BIT(x, i) (((x) >> (i)) & 1)
using namespace std;

typedef long long ll;

const int N = 1e3 + 5;

int n, a[N];
ll res = 0;

bool mxm(ll &a, ll b) {return a < b ? a = b, 1 : 0;}

struct Trie
{
	struct Node
	{
		Node *child[2];
		int val;
		Node()
		{
			for (int i = 0; i < 2; i++)
				child[i] = nullptr;
			val = 0;
		}
	} *root = new Node();

	void Add(int &x)
	{
		Node *p = root;
		for (int i = 30; i >= 0; i--)
		{
			int c = BIT(x, i);
			if (p -> child[c] == nullptr)
				p -> child[c] = new Node();
			p = p -> child[c];
		}
		p -> val = x;
	}

	ll Find(int Sum)
	{
		Node *p = root;
		for (int i = 30; i >= 0; i--)
		{
			int c = BIT(Sum, i);
			if (p -> child[c ^ 1] != nullptr)
				p = p -> child[c ^ 1];
			else p = p -> child[c];
		}
		return Sum ^ p -> val;
	}
} T;

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], T.Add(a[i]);
}

int Scorpio()
{
	Load_Data();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mxm(res, T.Find(a[i] ^ a[j]));
	cout << res;
	return 0;
}

int main() {Scorpio();}

// https://oj.vnoi.info/problem/orderset
#include <iostream>
#define BIT(x, i) (((x) >> (i)) & 1)
using namespace std;

const int DELTA = 1e9, oo = 1e9 + 7;

int n;

struct Trie
{
	int sz = 0;
	struct Node
	{
		Node *child[2];
		int cnt, val;
		Node()
		{
			this -> cnt = 0; this -> val = oo;
			child[0] = child[1] = nullptr;
		}
	} *root = new Node();

	bool Valid(int x)
	{
		Node *p = root;
		for (int i = 31; i >= 0; i--)
		{
			p = p -> child[BIT(x, i)];
			if (p == nullptr) return false;
		}
		return p -> val != oo;
	}

	void Add(int x)
	{
		int val = x + DELTA;
		if (Valid(val)) return;
		Node *p = root;
		for (int i = 31; i >= 0; i--)
		{
			int c = BIT(val, i);
			if (p -> child[c] == nullptr)
				p -> child[c] = new Node();
			p = p -> child[c];
			++p -> cnt;
		}
		p -> val = x; sz++;
	}

	void Del(int x)
	{
		int val = x + DELTA;
		if (!Valid(val)) return;
		Node *p = root;
		for (int i = 31; i >= 0; i--)
			p = p -> child[BIT(val, i)], --p -> cnt;
		p -> val = oo; sz--;
	}

	void Find(int k, int res = 0)
	{
		if (this -> sz < k) return void (cout << "invalid\n");
		Node *p = root;
		for (int i = 31; i >= 0; i--)
		{
			Node *l = p -> child[0];
			if (l != nullptr && k <= l -> cnt) p = l; else
			p = p -> child[1], k -= (l == nullptr) ? 0 : l -> cnt;
		}
		if (p -> val == oo) cout << "invalid\n";
		else cout << p -> val << '\n';
	}

	void Count(int x, int cnt = 0)
	{
		int val = x + DELTA;
		Node *p = root;
		for (int i = 31; i >= 0; i--)
		{
			int c = BIT(val, i);
			Node *l = p -> child[0];

			if (c && l != nullptr)
				cnt += l -> cnt;

			if (p -> child[c] == nullptr) break;
			p = p -> child[c];
		}
		cout << cnt << '\n';
	}
} T;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, val; i <= n; i++)
	{
		char c; cin >> c >> val;
		if (c == 'I') T.Add(val); else
		if (c == 'D') T.Del(val); else
		if (c == 'K') T.Find(val);				
		else T.Count(val);
	}
	return 0;
}

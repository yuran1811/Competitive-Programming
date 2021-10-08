// http://ntucoder.net/Problem/Details/5621
#include <iostream>
#include <string>
#define sz(s) (int (s.size()))
using namespace std;

string n, m, k, Min, Max;

bool mnz(string &a, string b) {return a > b ? a = b, 1 : 0;}
bool mxm(string &a, string b) {return a < b ? a = b, 1 : 0;}

void Btr(int i, int j, string &s)
{
	if (i == sz(n) && j == sz(m))
	{
		mnz(Min, s);
		mxm(Max, s);
		return;
	}
	if (i < sz(n)) s[i + j] = n[i], Btr(i + 1, j, s);
	if (j < sz(m)) s[i + j] = m[j], Btr(i, j + 1, s);
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	k.assign(sz(n) + sz(m), '0');
	Max.assign(sz(n) + sz(m), '0');
	Min.assign(sz(n) + sz(m), '9');
}

int Scorpio()
{
	Load_Data();
	Btr(0, 0, k);
	cout << Min << '\n' << Max;
	return 0;
}

int main() {Scorpio();}

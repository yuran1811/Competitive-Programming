// http://ntucoder.net/Problem/Details/136
#include <iostream>
using namespace std;

int n, k, a, b, c;

void Btr(int i, int &a, int &b, int &c)
{
	if (!k) return;
	if (i == 1) {k--; a--; c++; return;}
	Btr(i - 1, a, c, b);
	Btr(1, a, b, c);
	Btr(i - 1, b, a, c);
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k; a = n;
}

int Scorpio()
{
	Load_Data();
	Btr(n, a, b, c);
	cout << a << " " << c << " " << b;
	return 0;
}

int main() {Scorpio();}

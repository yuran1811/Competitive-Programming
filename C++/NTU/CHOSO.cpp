// http://ntucoder.net/Problem/Details/4402
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

map <int, ll> mp[3];
ll res = 0;
vector <int> a;
int n;

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
    for (int i = 0; i < 3; i++)
        for (int j = 1, x; j <= n; j++)
            cin >> x, mp[i][x]++, a.push_back(x);
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
}

int Solve()
{
	Load_Data();
	for (int x : a)
        	res += 1LL * mp[0][x] * mp[1][x] * mp[2][x];
	cout << res;
	return 0;
}

int main() {Solve();}

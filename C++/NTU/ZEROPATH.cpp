// http://ntucoder.net/Problem/Details/5558
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

vector <int> kt(N, 0);
set <int> f;
int n;

void findd(int n)
{
    if (n == 0) return;
    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0 && kt[(i - 1) * (n / i + 1)] == 0)
        {
            kt[(i - 1) * (n / i + 1)]++;
            f.insert((i - 1) * (n / i + 1));
            if (kt[(i - 1) * (n / i + 1)] == 1) 
                findd((i - 1) * (n / i + 1));
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; findd(n);
    cout << f.size() << '\n';
    for (auto x : f) cout << x << " ";
    return 0;
}

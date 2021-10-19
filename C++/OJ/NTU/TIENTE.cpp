// http://ntucoder.net/Problem/Details/4420
#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    int a[n + 7];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    bool x[n + 7];
    set <string> res;
    for (int mask = 0; mask < (1 << n); mask ++)
    {
        int suma = 0, sumb = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                x[i] = 1, suma += a[i];
            else
                x[i] = 0, sumb += a[i];
  
		    if (suma == sumb)
        {
            string s;
            for (int j = 0; j<n; j++)
                s += (x[j] ? "B " : "A ");
            res.insert(s);
        }
	}

	if (res.empty()) cout << "khong chia duoc";	else
  {
      cout << res.size() << '\n';
		  for (string i: res) cout << i << '\n';
	}
	return 0;
}

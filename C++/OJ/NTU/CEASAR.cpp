// http://ntucoder.net/Problem/Details/90
#include<bits/stdc++.h>
using namespace std;

int n, m;
char c;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> n;
    for (int i=0; i<s.size(); i++)
    {
    	c = s[i];
    	if (c - n < 97)
    		c = c - n + 26;
    	else c -= n;
    	cout << c;
    }
    cerr << endl;
    return 0;
}

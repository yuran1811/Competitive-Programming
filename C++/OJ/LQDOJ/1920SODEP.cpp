// https://lqdoj.edu.vn/problem/1920sodep
#include <bits/stdc++.h>

using namespace std;

void solve(const string &t) {
    int res = 0;

    for (int i = 0; i < int (t.size()); i++) 
        res += t[i] - '0';

    if (res < 10) return void (cout << res);

    while (res > 9) {
        int tmp = res;
        res = 0;

        while (tmp != 0)
            res += tmp % 10,
            tmp /= 10;
    }

    cout << res;
}

int main() {
    string s;
    cin >> s;

    solve(s);

    return 0;
}
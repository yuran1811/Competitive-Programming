#include <iostream>

using namespace std;

int n, c, b;
int row[101];
int a[21][21];
int kt1[101], kt2[101];

void backtracking(int i) {
	for (int j = 1; j <= 8; j++)
		if (a[j][i] == 0 && row[j] == 0 && kt1[i - j + 8] == 0 && kt2[i + j] == 0) {
			a[j][i] = row[j] = kt1[i - j + 8] = kt2[i + j] = 1;

			if (i >= 8) {
				if (a[c][b] == 1) {
					for (int l = 1; l <= 8; l++, cout << '\n')
						for (int k = 1; k <= 8; k++)
							cout << (a[l][k] == 1 ? "w" : ".");
					exit(0);
				}
			} else backtracking(i + 1);

			a[j][i] = row[j] = kt1[i - j + 8] = kt2[i + j] = 0;
		}
}

int main() {
	cin >> c >> b;

	backtracking(1);
	
	return 0;
}
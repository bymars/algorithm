#include <iostream>
#include <queue>
using namespace std;
int bfs(bool* map, int n, int m) {

	queue<int> Q;
	int i, count = 0;
	for (i = 0; i < m * n; i++)	{
		if (map[i]) {
			count++;
			Q.push(i);
			map[i] = false;
			while (!Q.empty()) {
				int point = Q.front();
				Q.pop();
				int row = point / m;
				int column = point % m;
				for (int p = row - 1; p <= row + 1; p++) {
					for (int q = column - 1; q <= column + 1; q ++) {
						if (p >= 0 && p < n && q >= 0 && q < m && map[p * m + q]) {
							Q.push(p * m + q);
							map[p * m + q] = false;
						}
					}
				}
			}
		}
	}
	return count;
}
int main(int argc, char** argv) {
	int m, n, i = 0;
	char c;
	cin >> n >> m;
	bool *field = new bool[n * m];
	while (cin >> c) {
		field[i++] = (c == 'W' ? true : false);
	}
	if (argc > 1) {
		for (int j = 0; j < n; j ++) {
			for (int k = 0; k < m; k++) {
				cout << (field[j * m + k] ? 'W' : '.') << " ";
			}
			cout << endl;
		}
	}
	cout << bfs(field, n, m) << endl;
	
}

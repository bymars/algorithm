#include <iostream>
#include "graph.h"

using namespace std;

const int INF = 100000;
int floyd(const Graph &g, int n, int start, int end) {
	const int N = n;
	int map[N][N], i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			map[i][j] = g.dist(i, j);
		}
	}
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (map[i][k] + map[k][j] < map[i][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	return map[start][end];
}
int main() {
	int m, n, i, j, d;
	while (cin >> n >> m && (m || n)) {
		Graph g(n, INF);
		while (m--) {
			cin >> i >> j >> d;
			g.insert(i - 1, j - 1, d);
		}
		cout << floyd(g, n, 0, n - 1) << endl;
	}
}

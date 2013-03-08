#include <iostream>
#include <graph.h>

using namespace std;

const int N = 100;
const int INF = 100000;
int dijkstra(const Graph &g, int n, int start, int end) {
	bool mark[N];
	int dist[N];
	int i, j;
	for (i = 0; i < n; i++) mark[i] = false;
	mark[start] = true;
	for (i = 0; i < n; i++) dist[i] = g.dist(start, i);

	for (i = 1; i < n; i++) {
		int min_dist = INF, point;
		for (j = 0; j < n; j++) {
			if (!mark[j] && min_dist > dist[j]) {
				min_dist = dist[j];
				point = j;
			}
		}
		mark[point] = true;
		for (j = 0; j < n; j++) {
			if (!mark[j] && dist[j] > dist[point] + g.dist(point, j)) {
				dist[j] = dist[point] + g.dist(point, j);
			}
		}
	}
	return dist[end];
}
int main(int argc, char** argv) {
	int map[N][N];
	int i, j, n, m, d;
	while (cin >> n >> m && !(n == 0 && m == 0)) {
		Graph g(n, INF);
		while (m--) {
			cin >> i >> j >> d;
			g.insert(i - 1, j - 1, d);
		}
		g.print();
//		cout << dijkstra(g, n, 0, n - 1) << endl;
	}
}

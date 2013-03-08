#include <iostream>
#include <queue>
#include <graph.h>

using namespace std;

const int INF = 100000;
int spfa(const Graph &g, int n, int start, int end) {
	bool *mark = new bool[n];
	int *dist = new int[n];
	queue<int> Q;
	int i, j;
	for (i = 0; i < n; i++) {
		mark[i] = false;
		dist[i] = INF;
	}
	mark[start] = true;
	dist[start] = 0;
	Q.push(start);
	while (!Q.empty()) {
		int point = Q.front();
		Q.pop();
		mark[point] = false;
		
		Edge *edge = g.adj(point);
		while (edge) {
			int v = edge->vertex, w = edge->weight;
			if (dist[v] > dist[point] + w) {
				dist[v] = dist[point] + w;
				if (!mark[v]) {
					mark[v] = true;
					Q.push(v);
				}
			}
			edge = edge->next;
		}
	}
	int ret = dist[end];
	delete[] dist;
	delete[] mark;
	return ret;
}
int main(int argc, char** argv) {

	int m, n, i, j, d;
	while (cin >> n >> m && (m || n)) {
		Graph g(n, INF);
		while (m--) {
			cin >> i >> j >> d;
			g.insert(i - 1, j - 1, d);
		}
		if (argc > 1) g.print();
		cout << spfa(g, n, 0, n - 1) << endl;
	}
}

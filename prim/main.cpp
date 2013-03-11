#include <iostream>
#include <queue>
#include <cmath>
#include "graph.h"
using namespace std;

const int INF = 30000000;
struct Node{
	Node(int v, int d) : vertex(v), dist(d) {}
	int vertex;
	int dist;
	friend bool operator> (const Node &l, const Node &r);
};

bool operator> (const Node &l, const Node &r) {
	return l.dist > r.dist;
}

int prim(const Graph &g, int src) {

	int sum = 0, i, j;
	const int N = g.size();
	bool mark[N];
	int dist[N];
	priority_queue<Node, vector<Node>, greater<Node> > Q;
	for (i = 0; i < N; i++) {
		mark[i] = false;
		dist[i] = INF;
	}
	dist[src] = 0;

	Q.push(Node(src, dist[src]));
	while (!Q.empty()) {
		Node node = Q.top();
		Q.pop();
		if (!mark[node.vertex]) {
			mark[node.vertex] = true;
			sum += node.dist;
			Edge *edge = g.adj(node.vertex);
                	while (edge) {
                        	if (!mark[edge->vertex] && dist[edge->vertex] > edge->weight) {
                                	dist[edge->vertex] = edge->weight;
                                	Q.push(Node(edge->vertex, dist[edge->vertex]));
                        	}
				edge = edge->next;
                	}
		}
	}
	return sum;
}
int main(int argc, char** argv) {
	int m, n, i, j, dist;
	char ci, cj;
	while (cin >> n && n) {
		Graph g(n, INF);
		while (--n) {			
			cin >> ci >> m;
			while (m--) {
				cin >> cj >> dist;
				i = ci - 'A';
				j = cj - 'A';
				g.insert(i, j, dist);
			}
		}
		if (argc > 1) g.print();
		cout << prim(g, 0) << endl;
	}
}

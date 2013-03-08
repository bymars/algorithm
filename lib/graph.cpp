#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

Graph::Graph(int n, int inf) : N(n), INF(inf) {
	for (int i = 0; i < N; i++) {
		Edge *edge = NULL;
		edges.push_back(edge);
	}
}
Graph::~Graph() {
	for (vector<Edge*>::iterator it = edges.begin(); 
		it != edges.end(); ++it) {
		Edge *edge = *it;
		while (edge) {
			delete edge;
			edge = edge->next;
		}
	}
}

void Graph::insert(int i, int j, int d) {

	edges.at(i) = new Edge(j, d, edges.at(i));
        edges.at(j) = new Edge(i, d, edges.at(j));
}

int Graph::dist(int i, int j) const {

        Edge *edge = edges.at(i);
        int dist = INF;
        while (edge) {
                if (edge->vertex == j && edge->weight < dist) {
			dist = edge->weight;
                }
                edge = edge->next;
        }

        return dist;
}

Edge* Graph::adj(int vertex) const {
	return edges.at(vertex);
}

void Graph::print() const {

	int i, j;
	cout << N << "\t";
	for (i = 0; i < N; i++) {
		cout << i << "\t";
	}
	cout << endl;
	for (i = 0; i < N; i++) {
		Edge *edge = edges.at(i);
		cout << i << "\t";
		for (j = 0; j < N; j++) {
			int d = dist(i, j);
			if (d == INF) cout << "INF\t";
			else cout << dist(i, j) << "\t";
		}
		cout << endl;
	} 
	cout << endl;

}


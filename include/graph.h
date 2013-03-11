#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

struct Edge {
	int vertex;
	int weight;
	Edge *next;
	Edge(int v, int w, Edge *n) : vertex(v), weight(w), next(n) {}
};

class Graph {
private:
	const int N;
	const int INF;
	std::vector<Edge*> edges;
public: 
	Graph(int, int);
	~Graph();
	int size() const;
//	Graph(int n, int max) : dimension(n), INF(max) {
//		edges = new Node*[n];
//		for (int i = 0; i < n; i++) {
//			edges[i] = NULL;		
//		}
//	}
	void insert(int i, int j, int dist);
	int dist(int i, int j) const;
	Edge* adj(int i) const;
	void print() const;
//	~Graph() {
//		for (int i = 0; i < dimension; i++) {
//			Node *edge = edges[i];
//			while (edge) {
//				delete edge;
//				edge = edge->next;
//			}
//		}
//		delete[] edges;
//	}
};
#endif

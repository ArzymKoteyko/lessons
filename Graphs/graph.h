#pragma once
#include <vector>

using namespace std;

class Graph {

	public:

	Graph(int n, int m);
	// Class constructor
	// n is ammount of nodes and m is ammount of connections
	
	int size(char mode);
	// Returns node's or connection's ammount
	// takes 'n' for node's ammount
	// takes 'c' for connection's ammount
	
	void read();
	// Reads graph
	// takes pares of ints (node_1, node_2) from stdin
	
	void repr();
	// Prints graph
	
	void bfs(int start_node, int target_node);
	// For node(i) returns minimal distance from start node

	void add_rib(int node_1, int node_2);
	// Creats rib between first and second nodes
	
	void del_rib(int node_1, int node_2);
	// Deletes rib between first and second nodes
	
	private:

	int ammount_of_nodes;
	int ammount_of_connections;
	vector<int> *graph;
};
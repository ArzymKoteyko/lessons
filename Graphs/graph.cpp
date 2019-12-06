#include "graph.h"
#include <vector>
#include <queue>


using namespace std;

Graph::Graph(int n, int m){
	ammount_of_nodes = n;
	ammount_of_connections = m;
	graph = new vector<int>[ammount_of_nodes];
}

int Graph::size(char mode){
	if (mode == 'n')  return ammount_of_nodes;
	if (mode == 'c')  return ammount_of_connections;
	else 			  return 0;
}

void Graph::read(){
	int first_node, last_node;
	for (int i = 0; i < ammount_of_connections; i++){
		scanf("%d%d", &first_node, &last_node); first_node--; last_node--;
		graph[first_node].push_back(last_node);
		graph[last_node].push_back(first_node);
	}
}

void Graph::repr(){
	printf("\nNodes ammount: %d    Connections ammount: %d\n\n", 
	        ammount_of_nodes,    ammount_of_connections);
	
	for (int i = 0; i < ammount_of_nodes; i++){
		printf("Connectiosn of %d node: ", i+1);
		for (int j = 0; j < int(graph[i].size()); j++){
			printf("%d ", graph[i][j]+1);
		}
		printf("\n");
	}
}

void Graph::bfs(int start_node, int target_node){
	int current_node = start_node - 1;
	bool is_found = false;
	int *distances = new int[ammount_of_nodes];
	queue<int> node_queue;
	for (int i = 0 ; i < ammount_of_nodes; i++){
		distances[i] = 0;
	}
	distances[current_node] = 1;
	node_queue.push(current_node);
	while (node_queue.empty() == false) {
		for (int i = 0; i < int(graph[current_node].size()); i++){
			if (distances[graph[current_node][i]] == 0){
				node_queue.push(graph[current_node][i]);
				distances[graph[current_node][i]] = distances[current_node] + 1;
				if (graph[current_node][i] == target_node-1){
					is_found = true;
					break;
				}
			}
		}
		if (is_found) break;
		node_queue.pop();
		if (node_queue.empty() == false) current_node = node_queue.front();
	}
	for (int i = 0; i < ammount_of_nodes; i++) printf("%d ", distances[i]);
	printf("\n%d\n", distances[target_node-1]-1);
	
}

void Graph::add_rib(int node_1, int node_2){
	node_1--; node_2--;
	graph[node_1].push_back(node_2);
	graph[node_2].push_back(node_1);
}

void Graph::del_rib(int node_1, int node_2){
	node_1--; node_2--;
	for (int i = 0; i < int(graph[node_1].size()); i++){
		if (graph[node_1][i] == node_2){
			swap(graph[node_1][i], graph[node_1][int(graph[node_1].size()-1)]);
			graph[node_1].pop_back();
		}
	}
	for (int i = 0; i < int(graph[node_2].size()); i++){
		if (graph[node_2][i] == node_1){
			swap(graph[node_2][i], graph[node_2][int(graph[node_2].size()-1)]);
			graph[node_2].pop_back();
		}
	}
	ammount_of_connections--;
}













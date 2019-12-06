#include <stdio.h>
#include <vector>
#include "graph.h"

using namespace std;

void swap(int &a, int &b){
	int cell = a;
	a = b;
	b = cell;
}

int main(){
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	Graph test = Graph(n, m);
	test.repr();
	test.read();
	test.repr();
	while (true) {
		char mode;
		int node_1, node_2;
		scanf("%c", &mode);
		if (mode == '-'){
			scanf("%d%d", &node_1, &node_2);
			test.del_rib(node_1, node_2);
		}
		else if (mode == '+'){
			scanf("%d%d", &node_1, &node_2);
			test.add_rib(node_1, node_2); 
		}
		else if (mode == '?'){
			scanf("%d%d", &node_1, &node_2);
			test.bfs(node_1, node_2);
		}
		else if (mode == 'r'){
			test.repr();
		}
		else if (mode == 'q'){
			break;
		}
	}
}
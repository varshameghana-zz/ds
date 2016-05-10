/*DFS: The graph can be both a directed graph and a non directed graph and can also contain cycles.

In DFS or Depth First Search we have to keep track of vertices that are visited in order to prevent revisiting them. For this we use an array to mark visited and unvisited vertices. In DFS we also take help of a STACK. When a vertex is visited, we push it into the stack. The process ends when the stack becomes empty.

We start the process by considering any one of the vertex as the starting vertex.*/

#include <stdio.h>
#include<stdbool.h>
#define STACK_SIZE 20
#define MAX 20

void dfs(int Adj[][MAX], int n, int source);

int main(void) {
	//Adj matrix
	int Adj[][MAX] = {
		{0,1,0,0},
		{0,1,1,1},
		{1,0,0,1},
		{0,0,1,0}
	};
	
	int n = 4;	//no. of vertex
	int starting_vertex = 3;
	
	dfs(Adj, n, starting_vertex);
	
	return 0;
}

void dfs(int Adj[][MAX], int n, int source) {
	//variables
	int i, j;
	bool change = false;

	//visited array to flag the vertex that
	//were visited
	int visited[MAX];

	//top of the stack
	int tos = 0;

	//stack
	int stack[STACK_SIZE];
	
	//set visited for all vertex to 0 (means unvisited)
	for(i = 0; i < MAX; i++) {
		visited[i] = 0;
	}
	
	//mark the visited source
	visited[source] = 1;
	
	//push the vertex into stack
	stack[tos] = source;
	
	//print the vertex as result
	printf("%d ", source);
	
	//continue till stack is not empty
	while(tos >= 0) {
		//to check if any vertex was marked as visited
		change = false;
		
		//get vertex at the top of the stack
		i = stack[tos];
		
		for(j = 0; j < n; j++) {
			if(visited[j] == 0 && Adj[i][j] == 1) {
				//mark vertex as visited
				visited[j] = 1;
				
				//push vertex into stack
				tos++;
				stack[tos] = j;
				
				//print the vertex as result
				printf("%d ", j);
				
				//vertex visited
				change = true;
				
				break;
			}
		}
		if(change == false) {
			tos--;
		}
	}
	printf("\n");
}

/*Time complexity
The time complexity of Depth First Search (DFS) is O(V+E) where, V is the total number of vertices in the graph and E is the total number of edges in the graph.
V is time taken to mark vertices ad visited..and e is for neighboring edges (2e for undirected)*/

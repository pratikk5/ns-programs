#include <stdio.h>
#include <limits.h>
#include <conio.h>
#define MAX_NODES 10

int minDistance(int dist[], int visited[], int nodes) {
  int min = INT_MAX, min_index;
  int v;
  for ( v = 0; v < nodes; v++) {
    if (visited[v] == 0 && dist[v] <= min) {
      min = dist[v];
      min_index = v;
    }
  }
  return min_index;
}

void printPath(int parent[], int j) {
  if (parent[j] == -1)
    return;

  printPath(parent, parent[j]);

  printf("%d ", j);
}

void printSolution(int dist[], int nodes, int parent[], int source) {
  //printf("Shortest path from node %d\n", source);
  int i;
  printf("Node \t Distance \t Path\n");
  for (i = 0; i < nodes; i++) {
    printf("\n %d -> %d \t %d \t\t %d ", source, i, dist[i], source);
    printPath(parent, i);
    printf("\n");
  }
}

void linkStateRouting(int graph[MAX_NODES][MAX_NODES], int nodes, int source) {
  int dist[MAX_NODES];
  int visited[MAX_NODES];
  int parent[MAX_NODES];
  int i,v,count;
  for (i = 0; i < nodes; i++) {
    dist[i] = INT_MAX;
    visited[i] = 0;
    parent[i] = -1;
  }

  dist[source] = 0;

  for (count = 0; count < nodes - 1; count++) {
    int u = minDistance(dist, visited, nodes);
    visited[u] = 1;

    for ( v = 0; v < nodes; v++) {
      if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
	dist[v] = dist[u] + graph[u][v];
	parent[v] = u;
      }
    }
  }
  printSolution(dist, nodes, parent, source);
}

int main() {
  int graph[MAX_NODES][MAX_NODES];
  int nodes, source;
  int i,j;

  printf("Enter the number of nodes: ");
  scanf("%d", &nodes);

  printf("Enter the adjacency matrix:\n");
  for (i = 0; i < nodes; i++) {
    for (j = 0; j < nodes; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  printf("Enter the source node: ");
  scanf("%d", &source);

  linkStateRouting(graph, nodes, source);
  getch();
  return 0;
}
//sample output
/*
Enter the number of nodes: 5
Enter the adjacency matrix:
0 10 0 5 0
0 0 1 2 0
0 0 0 0 4
0 0 3 0 2
0 0 0 0 0
Enter the source node: 0

Shortest path from node 0
Node    Distance        Path
0       0               0 
1       10              0 1 
2       12              0 1 2 
3       5               0 3 
4       7               0 3 4 
*/
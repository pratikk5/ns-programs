#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
  unsigned dist[20];
  unsigned from[20];
} rt[10];

int main() {
  int dmat[20][20], n, i, j, k, count = 0;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the cost matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &dmat[i][j]);
      dmat[i][j]=0;
      rt[i].dist[j] = dmat[i][j];
      rt[i].from[j] = j;
    }
  }

  do {
    count = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
	for (k = 0; k < n; k++) {
	  if (rt[i].dist[j] > rt[i].dist[k] + rt[k].dist[j]) {
	    rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
	    rt[i].from[j] = k;
	    count++;
	  }
	}
      }
    }
  } while (count != 0);

  for (i = 0; i < n; i++) {
    printf("\n\n State value for router %d \n", i + 1);
    for (j = 0; j < n; j++) {
      printf("\t\n node %d via %d distance %d ", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
    }
  }
  printf("\n\n");
  getch();
  return 0;
}
/* sample Output
/*
Enter the number of nodes: 4
Enter the cost matrix:
0 2 7 1
2 0 3 6
7 3 0 5
1 6 5 0

For router 1
 node 1 via 1 distance 0 
 node 2 via 2 distance 2 
 node 3 via 2 distance 5 
 node 4 via 4 distance 1 

 For router 2
 node 1 via 1 distance 2 
 node 2 via 2 distance 0 
 node 3 via 2 distance 3 
 node 4 via 1 distance 3 

 For router 3
 node 1 via 2 distance 5 
 node 2 via 2 distance 3 
 node 3 via 3 distance 0 
 node 4 via 4 distance 5 

 For router 4
 node 1 via 1 distance 1 
 node 2 via 1 distance 3 
 node 3 via 4 distance 5 
 node 4 via 4 distance 0 
*/
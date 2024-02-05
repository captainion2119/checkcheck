// Lab program: Write a C Program to detect Cycle in a Directed Graph.
// Lab program: Write a C Program to detect Cycle in a Directed Graph.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int N, adj[MAX][MAX], vi[MAX], dfsVi[MAX];

void dfs(int node)
{
 vi[node] = 1;
 dfsVi[node] = 1;
 for (int i = 0; i < N; i++)
 {
 if (adj[node][i] && !vi[i])
 {
 dfs(i);
 }
 else if (adj[node][i] && dfsVi[i])
 {
 printf("Cycle Detected\n");
 exit(0);
 }
 }
 dfsVi[node] = 0;
}

int isCyclic() {
 for (int i = 0; i < N; i++)
 {
 vi[i] = 0;
 dfsVi[i] = 0;
 }
 for (int i = 0; i < N; i++)
 {
 if (!vi[i] && dfsVi[i] == 0)
 {
 dfs(i);
 }
 }
 return 0;
}

void createGraph() {
 printf("Enter the number of vertices (N): ");
 scanf("%d", &N);
 printf("Enter the adjacency matrix:\n");
 for (int i = 0; i < N; i++)
 for (int j = 0; j < N; j++)
 scanf("%d", &adj[i][j]);
}

int main() {
 createGraph();
 isCyclic();
 printf("No Cycle Detected\n");
 return 0;
}
/*Enter the number of vertices (N): 6
Enter the adjacency matrix:
0 1 0 0 0 0
0 0 1 0 0 1
0 0 0 0 1 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
Cycle Detected
Enter the number of vertices (N): 4
Enter the adjacency matrix:
0 1 0 0
0 0 0 0
0 1 0 0
0 1 1 0
No Cycle Detected*/

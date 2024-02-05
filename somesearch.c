#include <stdio.h>
#define MAX 20
int a[MAX][MAX], q[MAX], visited[MAX], reach[MAX], n, i, j, f = 0, r = 0;

void bfs(int v) {
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            q[++r] = i;
            visited[i] = 1; // Mark the node as visited when enqueued
        }
    }
    if (f <= r) {
        bfs(q[++f]);
    }
}

void dfs(int v) {
    int i;
    reach[v] = 1;
    //Print the reachable node during DFS
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !reach[i]) {
            dfs(i);
        }
    }
}

void createGraph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
}

int main() {
    int choice, start;
    do {
        printf("\n1. Create Graph\n");
        printf("2. DFS Traversal\n");
        printf("3. BFS Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createGraph();
                break;
            case 2:
                printf("Enter the starting vertex for DFS traversal: ");
                scanf("%d", &start);
                printf("DFS Traversal from %d: ", start);
                for (int k = 1; k <= n; k++)
                    reach[k] = 0;
                dfs(start);
                printf("\n");
                break;
            case 3:
                printf("Enter the starting vertex for BFS traversal: ");
                scanf("%d", &start);
                for (i = 1; i <= n; i++) {
                    q[i] = 0;
                    visited[i] = 0;
                }
                f = 0; // Reset the front pointer
                r = 0; // Reset the rear pointer
                visited[start] = 1; // Mark the starting vertex as visited
                bfs(start);
                printf("BFS Traversal from %d: ", start);
                for (i = 1; i <= n; i++)
                    if (visited[i])
                printf("%d ", i);
                printf("\n");
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);
}

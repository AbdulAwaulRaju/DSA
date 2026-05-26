#include <stdio.h>

int adj[100][100];
int visited[100];
int n;

void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int start;
    scanf("%d", &start);

    dfs(start);

    return 0;
}

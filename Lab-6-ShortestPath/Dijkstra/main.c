#include <stdio.h>

#define INF 999999

int minDistance(int dist[], int visited[], int V) {
    int min = INF, index;

    for(int i = 0; i < V; i++) {
        if(!visited[i] && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int graph[100][100];

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            graph[i][j] = 0;

    for(int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    int src;
    scanf("%d", &src);

    int dist[100], visited[100];

    for(int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int i = 0; i < V - 1; i++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for(int v = 0; v < V; v++) {
            if(!visited[v] && graph[u][v] && dist[u] != INF &&
               dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", src);

    for(int i = 0; i < V; i++) {
        if(dist[i] == INF)
            printf("%d: INF\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }

    return 0;
}

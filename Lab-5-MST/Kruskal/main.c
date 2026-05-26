#include <stdio.h>

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int x) {
    if(parent[x] == x)
        return x;
    return find(parent[x]);
}

void unionSet(int a, int b) {
    parent[a] = b;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    struct Edge edges[100];

    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    for(int i = 0; i < n; i++)
        parent[i] = i;

    for(int i = 0; i < e - 1; i++) {
        for(int j = i + 1; j < e; j++) {
            if(edges[i].w > edges[j].w) {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    for(int i = 0; i < e; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if(u != v) {
            printf("%d - %d\n", edges[i].u, edges[i].v);
            unionSet(u, v);
        }
    }

    return 0;
}

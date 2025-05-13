#include <stdio.h>

#define V 4
#define INF 9999

int tsp(int graph[V][V], int v[], int pos, int n, int count, int cost, int ans) {
if (count == n && graph[pos][0])
return (cost + graph[pos][0] < ans) ? (cost + graph[pos][0]) : ans;

for (int i = 0; i < n; i++) {
if (!v[i] && graph[pos][i]) {
v[i] = 1;
ans = tsp(graph, v, i, n, count + 1, cost + graph[pos][i], ans);
v[i] = 0;
}
}
return ans;
}

int main() {
    int graph[V][V] ,n;
    printf("Enter order of graph matrix:\n");
    scanf("%d",&n);
    printf("Enter graph matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

int v[V] = {0};
v[0] = 1;
int ans = tsp(graph, v, 0, V, 1, 0, INF);
printf("Minimum cost of TSP = %d\n", ans);
return 0;
}

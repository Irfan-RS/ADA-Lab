#include <stdio.h>

#define N 3

void assignmentProblem(int cost[N][N]) {
int assigned[N] = {0};

for (int i = 0; i < N; i++) {
int min = 9999, index = -1;
for (int j = 0; j < N; j++) {
if (!assigned[j] && cost[i][j] < min) {
min = cost[i][j];
index = j;
}
}
assigned[index] = 1;
printf("Assign worker %d to job %d with cost %d\n", i, index, cost[i][index]);
}
}

int main() {
int cost[N][N] ,n;
printf("Enter order of cost matrix:\n");
scanf("%d",&n);
//= { {9, 2, 7}, {6, 4, 3}, {5, 8, 1} };
printf("Enter cost matrix:\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&cost[i][j]);
    }
}

assignmentProblem(cost);
return 0;
}

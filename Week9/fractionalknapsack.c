#include <stdio.h> 
#define MAX 100
void fractionalKnapsack(int n, float weight[], float profit[], float capacity) { 
    float ratio[MAX],
    temp; int i, j;
    
    for (i = 0; i < n; i++)
    ratio[i] = profit[i] / weight[i];
    
    for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
    if (ratio[i] < ratio[j]) {
    temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
    temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
    temp = profit[i]; profit[i] = profit[j]; profit[j] = temp;
    }
    }
    }
    
    float totalProfit = 0;
    for (i = 0; i < n; i++) {
    
    if (capacity >= weight[i]) {
    capacity -= weight[i];
    totalProfit += profit[i];
    } else {
    totalProfit += ratio[i] * capacity;
    break;
    }
    }
    printf("Total Profit = %.2f\n", totalProfit);
    
    }
    
    int main() {
        int n;
        float weight[MAX], profit[MAX], capacity;
        printf("Enter the number of items: ");
        scanf("%d", &n);
        
        printf("Enter the weights of the items: ");
        for (int i = 0; i < n; i++) {
            scanf("%f", &weight[i]);
        }
        
        printf("Enter the profits of the items: ");
        for (int i = 0; i < n; i++) {
            scanf("%f", &profit[i]);
        }
        
        printf("Enter the capacity of the knapsack: ");
        scanf("%f", &capacity);
        
        fractionalKnapsack(n, weight, profit, capacity);
        
        return 0;
    }

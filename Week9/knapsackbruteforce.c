#include<stdio.h>
#include <math.h>
    
 void knapsackBruteforce(int n, int weight[], int profit[], int capacity) { 
    int maxProfit = 0; int subset, bestSubset = 0; 
    for (subset = 0; subset < (1 << n); subset++) { 
        int totalWeight = 0,totalProfit = 0; 
        for (int i = 0; i < n; i++) { 
            if (subset & (1 << i)) { 
                totalWeight += weight[i];
                totalProfit += profit[i]; 
            } 
        } 
        if (totalWeight <= capacity && totalProfit > maxProfit) { maxProfit =
            totalProfit; bestSubset = subset; } } printf("Maximum Profit = %d\nitems taken: ",maxProfit);
            for (int i = 0; i < n; i++) { 
                if (bestSubset & (1 << i)) printf("%d ", i); 
            } 
    printf("\n"); 
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    
    printf("Enter the profits of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    knapsackBruteforce(n, weight, profit, capacity);
    
    return 0;
}
    

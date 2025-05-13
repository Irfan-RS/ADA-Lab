/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int* result = (int*)malloc(pricesSize * sizeof(int));
    *returnSize = pricesSize;
    for (int i = 0; i < pricesSize; i++) {
        result[i] = prices[i]; 
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[j] <= prices[i]) {
                result[i] -= prices[j]; 
                break; 
            }
        }
    }
    
    return result; 
}

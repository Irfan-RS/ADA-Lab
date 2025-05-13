#include <stdio.h>
#include <stdlib.h>  // for rand()
#include <time.h>    // for clock()

#define MAX 5000

void quicksort(int[], int, int);
int partition(int[], int, int);

int main() {
    int i, n, a[MAX], ch;
    clock_t start, end;

    while (1) {
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);

        // Generate random array elements
        for (i = 0; i < n; i++) {
            a[i] = rand() % 200;  // Random number between 0 and 199
        }

        // Display the random array
        printf("The random generated array is:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        // Measure the time taken for sorting
        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        // Display the sorted array
        printf("\nThe sorted array elements are:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        // Calculate and print the time taken for sorting
        printf("Time taken = %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        // Ask user if they want to continue
        printf("\nDo you wish to continue? (0/1): ");
        scanf("%d", &ch);
        if (ch == 0) {
            break;
        }
    }

    return 0;
}

// QuickSort function
void quicksort(int a[], int low, int high) {
    if (low < high) {
        int mid = partition(a, low, high);
        quicksort(a, low, mid - 1);  // Recursively sort the left part
        quicksort(a, mid + 1, high); // Recursively sort the right part
    }
}

// Partition function: Returns the partition index
int partition(int a[], int low, int high) {
    int pivot = a[low]; // Pivot is the first element in the array
    int i = low + 1;
    int j = high;
    int temp;

    while (i <= j) {
        // Find an element greater than the pivot
        while (i <= high && a[i] <= pivot) {
            i++;
        }

        // Find an element less than the pivot
        while (a[j] > pivot) {
            j--;
        }

        // If there are elements to swap, swap them
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Swap the pivot element with a[j]
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;  // Return the partition index
}

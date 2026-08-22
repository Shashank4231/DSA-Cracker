#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x, int *iterations)
{
    while (low <= high) {
        (*iterations)++;
        int mid = low + (high - low) / 2;
 if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    
    return -1;
}


int main()
{
    int arr[] = { 7, 13, 19, 110, 150 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 110;
    int iterations = 0;
    int result = binarySearch(arr, 0, n - 1, x, &iterations);
   if(result == -1){printf("Element is not present in array");}
   else {printf("Element is present at index %d",result);}
   printf("Number of iterations: %d\n", iterations);
   return 0;
}
//quick_sort.c:
#include "quick_sort.h"

void quick_sort(int *a, int n) { //Ammeraal, "Programs and Data Structures in C"
    // a is a pointer to the first element in the array, and n is the length of the array
    int i = 0; // first index
    int j = n - 1; // last index
    int x = a[j / 2]; // middle index, used as partition value 
    int temp; // used in swap
    do {
        while (a[i] < x) {
            i++;
        } // set i to the index of the first value that is greater than partition value 
        
        while (a[j] > x) {
            j--;
        } // set j to the last value that is less than partition value
        
        if (i < j) { // if there are values to swap, swap them
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (++i <= --j); // continue until partition is done
    
    if (i == j + 3) { 
        i--, j++; 
    } // if partition was done, need to undo the increment and decrement from the while condition
    
    if (j > 0) {
        quick_sort(a, j + 1);
    } // sort a[0]...a[j] recursively
    
    if (i < n - 1) {
        quick_sort(a + i, n - i);
    } // sort a[i]...a[n-1] recursively
}


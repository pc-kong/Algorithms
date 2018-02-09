/**
    selection_sort.cpp
    Purpose: Apply comparison-based sorting algorithm to sort numeric elements
             given through the standard input.
    Description: The algorithm proceeds by finding the smallest (or largest, depending on sorting order)
                 element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element 
                 (putting it in sorted order), and moving the sublist boundaries one element to the right.
                 [https://en.wikipedia.org/wiki/Selection_sort].
    Complexity: O(n^2).
    
   @author Miguel Concha Vázquez mconcha@ciencias.unam.mx
   @version 1.0 08/02/18.
*/   

#include <cstdio>
using namespace std;

/**
    Interchanges two numeric values in an array.
    
    @params The values to be swapped.
*/
void swap(int* a, int* b){ 
  int temp = *a;
  *a = *b;
  *b = temp;
}

/**
    Prints the numeric values in an array.
    
    @param The array to be printed.
    @param The length of the array.
*/
void print_array(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int n, min_elem_index;
  printf("%s", "Number of elements to be sorted: ");
  scanf("%d", &n);
  int number_array[n];
  printf("%s", "Space-separated numbers to be sorted: ");
  for(int i = 0; i < n; i++) { //Storing the input values in the array.
    scanf("%d", &number_array[i]);
  }
  for(int i = 0; i < n-1; i++) {  //We need to perform at most n-1 passes.
    min_elem_index = i; //The candidate to the smallest index is always the position at which we start.
    for(int j = i+1; j < n; j++) { //We traverse the rest of the array and try to find an index whose number is lesser to update it.
      if(number_array[j] < number_array[min_elem_index]) {
	min_elem_index = j;
      }
    }
    swap(&number_array[i], &number_array[min_elem_index]); //We perform the swap between the minimum element in this part of the array and the number located where we found it.
  }
  printf("%s\n", "Sorted input numbers: ");
  print_array(number_array, n); //Printing the sorted array.
  printf("\n");  
  return 0;
}

/**
    bubble_sort.cpp
    Purpose: Apply comparison-based sorting algorithm to sort numeric elements
             given through the standard input.
    Description: Repeatedly steps through the list to be sorted, compares each pair of adjacent items and
                 swaps them if they are in the wrong order. The pass through the list is repeated until no 
                 swaps are needed, which indicates that the list is sorted. [https://en.wikipedia.org/wiki/Bubble_sort].
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
  int n;
  bool swap_exists;
  printf("%s", "Number of elements to be sorted: ");
  scanf("%d", &n);
  int number_array[n];
  printf("%s", "Space-separated numbers to be sorted: ");
  for(int i = 0; i < n; i++) { //Storing the input values in the array.
    scanf("%d", &number_array[i]);
  }
  for(int i = 0; i < n-1; i++) { //We need to perform at most n-1 passes.
    swap_exists = false;
    for(int j = 0; j < n-i-1; j++) { //The last i elements will be in-place. 
      if(number_array[j] > number_array[j+1]){ //We verify if a swap is needed and carry it out.
	swap(&number_array[j], &number_array[j+1]);
	swap_exists = true;
      }
    }
    if(!swap_exists) break; //Optimizing a bit: we do not need more passes if no swap was detected.
  }
  printf("%s\n", "Sorted input numbers: ");
  print_array(number_array, n); //Printing the sorted array.
  printf("\n");  
  return 0;
}

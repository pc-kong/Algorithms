/**
    insertion_sort.cpp
    Purpose: Apply comparison-based sorting algorithm to sort numeric elements
             given through the standard input.
    Description: Insertion sort iterates, consuming one input element each repetition, and growing a
                 sorted output list. At each iteration, insertion sort removes one element from the input data, 
                 finds the location it belongs within the sorted list, and inserts it there. It repeats until no input
                 elements remain. [https://en.wikipedia.org/wiki/Insertion_sort].
    Complexity: O(n^2).

   @author Miguel Concha Vázquez mconcha@ciencias.unam.mx
   @version 1.0 09/02/18.
*/

#include <cstdio>
using namespace std;

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
  int n, value_to_insert, j;
  printf("%s", "Number of elements to be sorted: ");
  scanf("%d", &n);
  int number_array[n];
  printf("%s", "Space-separated numbers to be sorted: ");
  for(int i = 0; i < n; i++) { //Storing the input values in the array.
    scanf("%d", &number_array[i]);
  }
  for(int i = 1; i < n; i++) { //One single element (arr[0]) is trivially already sorted.
    j = i-1; //The index at which we start moving backwards (where sorted sub-array ends).
    value_to_insert= number_array[i]; //We pick the element right to the sorted sub-array.
    while(value_to_insert < number_array[j] && j != 0) {
      number_array[j+1] = number_array[j]; //We move to the left.
      j--;
    }
    number_array[j+1] = value_to_insert; //We put the element in the sorted sub-array where it corresponds.
  }
  printf("%s\n", "Sorted input numbers: ");
  print_array(number_array, n); //Printing the sorted array.
  printf("\n");  
  return 0;
}

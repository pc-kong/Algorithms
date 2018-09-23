#include <bits/stdc++.h>
#define MININT 1e-19

using namespace std;

struct heap {
  vector<int> elems;
  bool min;
};

using p_heap = heap*;

/**
 *A function that will tell us the number of elements
 *from an specific node until the leafs, particularly if we call it
 *at the root will give us the complete heap.
 *Runs at O(1) since we have it stored in the structure.
 */
int number_elements(p_heap ph) {
  return ph != NULL ? ph->elems.size() : 0;
}

/**
 *Gives us the max element or the minimum element of the heap, depending
 *on how did we constructed it.
 *In O(1) time.
 */
int peek(p_heap ph) {
  return ph != NULL ? ph->elems[0] : MININT;
}

/**
 *Classical swap, since its a pointer it will actually modify the 
 *memdirs.
 *O(1)
 */

void swap(p_heap ph, int a, int b) {
  int aux = ph->elems[a];
  ph->elems[a] = ph->elems[b];
  ph->elems[b] = aux;
}

/**
 *This function is equivalent to heapify for an ordinary binary heap.
 *O(log n)
 */
void rebalance(p_heap ph, int pos){
  int i = pos;
  while(i >= 0) {
    int father = floor((pos-1)/2);
    if(ph->min) {
      if(ph->elems[pos] >= ph->elems[father] || father == -1) { return; }
      swap(ph, i, father);
      rebalance(ph, father);
    }else {
      if(ph->elems[pos] <= ph->elems[father] || father == -1) { return; }
      swap(ph, i, father);
      rebalance(ph, father);
    }
  }
}

/**
 *Inserts a new element in the heap, in it's respective order.
 */
void insert(p_heap ph, int elem){
  if(ph == NULL)
    return;
  ph->elems.push_back(elem);
  rebalance(ph, floor(ph->elems.size()-1/2));
}

int main() {
  return 0;
}

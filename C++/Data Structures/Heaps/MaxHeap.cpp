#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y) {
  int aux = *x;
  *x = *y;
  *y = aux;
}

class MaxHeap {

  int *arr;
  int cap;
  int size;

public:

   int parent(int i) {
    return (i-1)/2;
  }

  int left(int i) {
    return 2*i +1;
  }

  int right(int i) {
    return 2*i +2;
  }

  int getHead() {
    return arr[0];
  }

  MaxHeap(int capacity) {
    size = 0;
    cap = capacity;
    arr = new int[cap];
  }

  void insert(int k) {
    if(size == cap)
      return;

    arr[size] = k;
    size++;
    int i = size, fath = parent(i);

    while(i != 0 && arr[fath] < arr[i]) {
      swap(&arr[i], &arr[fath]);
      i = fath;
    }
  }

  void heapify(int i) {
    int l = left(i), r = right(i), g = i;
    if(l < size && arr[l] < arr[i])
      g = l;
    if(r < size && arr[r] < arr[i])
      g = r;
    if(g != i) {
      swap(&arr[i], &arr[g]);
      heapify(g);
    }
  }

  void decreaseKey(int i, int nv) {
    arr[i] = nv;
    int fath = parent(i);
    while(i != 0 && arr[fath] < arr[i]) {
      swap(&arr[i], &arr[fath]);
      i = fath;
    }
  }

  int extractMax() {
    if(size <= 0)
      return INT_MIN;
    if(size == 1) {
      size--;
      return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[size--];
    heapify(0);
    return root;
  }

  void deleteKey(int i) {
    decreaseKey(i, INT_MAX);
    extractMax();
  }
};



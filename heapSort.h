#pragma once 
#include <math.h>
#include <iostream>

int lastParent (int size){ 
    if ((size-1) % 2 == 0) return (size -2) / 2;
    else return (size -1) / 2;
}

int leftChild(int parent){
    return 2*parent + 1;
}

int rightChild(int parent){
    return 2*parent + 2;
}

void heapify(int tab[], int n, int parent){
    int left = leftChild(parent);
    int right = rightChild(parent);

    int largest = parent;

    if (left < n &&tab[left] > tab[largest]){
        largest = left;
	}
    
    if (right < n &&tab[right] > tab[largest]){
        largest = right;
	}
    if (largest != parent){

		int temp = tab[parent];
		tab[parent] = tab[largest];
		tab[largest] = temp;
        heapify(tab, n, largest);
	}
}

void buildMaxHeap(int tab[], int n){

    for (int i =lastParent(n); i >=0; i--){
        heapify(tab, n, i);
	}
}

void heapsort(int tab[], int n){
    buildMaxHeap(tab, n);

    for (int i = n-1; i >=0; i--){
        
		int temp = tab[i];
		tab[i] = tab[0];
		tab[0] = temp;

        heapify(tab, i, 0);
	}
}  
    

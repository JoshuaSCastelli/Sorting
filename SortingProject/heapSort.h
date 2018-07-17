#pragma once

//	SortingProject.cpp
//	Joshua Castelli

class heapSort {
private:
	int left, right, largest;
	
	int parent(int i);
	int leftChild(int i);
	int rightChild(int i);
	
	void maxHeapify(string* heap, int i, int heapSize);
	void buildMaxHeap(string* heap, int heapSize);
	void sortHeap(string* heap, int heapSize);
	void maxHeapInsert();
	string heapExtracMax(string* heap, int heapSize);
	void heapIncreaseKey();
	string heapMaximum(string* heap);

public:
	heapSort();
	void sort(string* list, int size);
};
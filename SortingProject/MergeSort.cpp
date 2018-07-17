//	SortingProject.cpp
//	Joshua Castelli

#include "stdafx.h"
#include "MergeSort.h"
#include <math.h>

string* MergeSort::sortList(string* list, int listLength) {
	int p=0, r = listLength-1;

	sorting(list, p, r);
	return list;
}
void MergeSort::sorting(string* list, int p, int r) {
	if (p < r) {
		int q = floor((p+r)/ 2);
		sorting(list, p, q);
		sorting(list, q + 1, r);
		merge(list, p, q, r);
	}
	return;
}
void MergeSort::merge(string* list, int p, int q, int r) {
	int n = q - p + 1;
	int m = r - q;
	int i = 0;
	int j = 0;

	string* subListA;
	subListA = new string[n+1];
	string* subListB;
	subListB = new string[m+1];
	
	for (i = 0; i < n; i++) {
		subListA[i] = list[p + i];
	}
	for (j = 0; j < m; j++) {
		subListB[j] = list[q + j + 1];
	}

	subListA[n] = 99999999;
	subListB[m] = 99999999;

	i = 0, j = 0;
	for (int k = p; k <= r; k++) {
		if (subListA[i] <= subListB[j]) {
			list[k] = subListA[i];
			i++;
		}
		else {
			list[k] = subListB[j];
			j++;
		}
	}
	return;
}
//	SortingProject.cpp
//	Joshua Castelli

#include "stdafx.h"
#include "InsertionSort.h"


string* InsertionSort::sortList(string* list,int listLength) {
	string key;
	int i;
	for (int j = 1; j < listLength; j++) {
		key = list[j];
		i = j - 1;
		while (i > 0 && list[i] > key) {
			list[i + 1] = list[i];
			i--;
		}
		list[i + 1] = key;
	}
	return list;
}

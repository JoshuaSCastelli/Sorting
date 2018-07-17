#pragma once

class MergeSort {
public:
	string* sortList(string* list, int listLength);
	void sorting(string* list, int p, int r);
	void merge(string* list, int p, int q, int r);

};
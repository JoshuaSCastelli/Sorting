//	SortingProject.cpp
//	Joshua Castelli

#include "stdafx.h"
#include "writeFile.h";
#include <fstream>

void writeFile::write(string* list, string filename, int size) {
	ofstream fout;
	fout.open(filename);

	if (fout.is_open()) {
		for (int i = 0; i <= size; i++) {
			list[i] += "\n";
			fout << list[i];
			
		}
		fout.close();
	}
	else {
		cout << "couldn't open file, make sure file isn't already open" << endl;
	}
};

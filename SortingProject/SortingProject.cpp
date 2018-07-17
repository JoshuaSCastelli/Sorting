//	SortingProject.cpp
//	Joshua Castelli

#include "stdafx.h"

#include "InsertionSort.h"
#include "MergeSort.h"
#include "heapSort.h"
#include <time.h>
#include "writeFile.h"

using namespace std;

int selectAlgorithm() {
	//Begin algorithm selection process.
	string selectionStr;
	int selection;
	bool valid = false;

	while (valid == false) {
		while (true) {

			cout << "Please select the sorthing algorithm you wish to use\n";
			cout << "1 - Insertion Sort\n";
			cout << "2 - Merge Sort\n";
			cout << "3 - Heap Sort\n";
			cout << "4 - Exit\n";
			cout << "Selection(1-4): ";

			getline(cin, selectionStr);

			stringstream myStream(selectionStr);
			if (myStream >> selection){
				if (selection == 4)
					exit(0);
				break;
			}
			system("CLS");
			cout << "!!!INCORRECT SELECTION, TRY AGAIN!!! \n";
		}

		if (selection > 4 || selection < 1) {
			system("CLS");
			cout << "!!!INCORRECT SELECTION, TRY AGAIN!!! \n";
		}
		else {
			valid = true;
		}
	}
	return selection;
}
int selectFileSize() {
	string selectionStr;
	int selection;
	bool valid = false;

	while (valid == false) {
		while (true) {
			system("CLS");
			cout << "Please select the file size you wish to use\n";
			cout << "1 - 30k words\n";
			cout << "2 - 60k words\n";
			cout << "3 - 90k words\n";
			cout << "4 - 120k words\n";
			cout << "5 - 150k words\n";
			cout << "6 - Exit\n";
			cout << "Selection(1-6): ";

			getline(cin, selectionStr);

			stringstream myStream(selectionStr);
			if (myStream >> selection) {
				break;
			}
			system("CLS");
			cout << "!!!INCORRECT SELECTION, TRY AGAIN!!! \n";
		}

		if (selection > 6 || selection < 1) {
			system("CLS");
			cout << "!!!INCORRECT SELECTION, TRY AGAIN!!! \n";
		}
		else {
			switch (selection) {
				case 1: selection = 30000;
					break;
				case 2: selection = 60000;
					break;
				case 3: selection = 90000;
					break;
				case 4: selection = 120000;
					break;
				case 5: selection = 150000;
					break;
				case 6: exit(0);
			}
			valid = true;
		}
	}
	return selection;
}
int selectPermutedOrSorted() {
	string selectionStr;
	int selection;
	bool valid = false;

	while (valid == false) {
		while (true) {
			system("CLS");
			cout << "Please select the sorthing algorithm you wish to use\n";
			cout << "1 - Permuted\n";
			cout << "2 - Sorted\n";
			cout << "3 - Exit\n";
			cout << "Selection(1-3): ";

			getline(cin, selectionStr);

			stringstream myStream(selectionStr);
			if (myStream >> selection) {
				if (selection == 3)
					exit(0);
				break;
			}
			system("CLS");
			cout << "!!!INCORRECT SELECTION, TRY AGAIN!!! \n";
		}

		if (selection > 3 || selection < 1) {
			system("CLS");
			cout << "!!!INCORRECT SELECTION, TRY AGAIN!!! \n";
		}
		else {
			valid = true;
		}
	}
	return selection;
}

int main()
{
begin:
	system("CLS");
	clock_t timerStart;
	int algo = selectAlgorithm();
	int size = selectFileSize();
	int permOrSort = selectPermutedOrSorted();
	string fileName;
	
	//load list from file based on size and sorted/permuted and file size(word count).
	if (permOrSort == 1) {
		fileName = "permuted/";
	}
	else {
		fileName = "sorted/";
	}

	switch (size) {
		case 30000: fileName += "30K.txt";
			break;
		case 60000: fileName += "60K.txt";
			break;
		case 90000: fileName += "90K.txt";
			break;
		case 120000: fileName += "120K.txt";
			break;
		case 150000: fileName += "150K.txt";
			break;
	}

	//opens file and instantiates 'temp' with content
	system("CLS");
	cout << "Loading file..." << endl;
	string* temp;
	getFile inputFile;
	temp = inputFile.loadFromFile(fileName, size);
	

	/*debugging purposes only.
	prints the unsorted/sorted list.
	for (int i = 0; i < size; i++) {
		cout << temp[i] << endl;
	}
	*/


	//sort list based on algorithm selected

	system("CLS");
	cout << "Please wait, processing..." << endl;
	switch (algo) {
		case 1:
			InsertionSort insert;
			fileName = "insertion/" + fileName;
			timerStart = clock();
			temp = insert.sortList(temp, size);
			cout <<"Total Sort Time: "<< ((float)(clock() - timerStart) / CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			break;
		case 2: 
			MergeSort merge;
			fileName = "merge/" + fileName;
			timerStart = clock();
			temp = merge.sortList(temp, size);
			cout << "Total Sort Time: " << ((float)(clock() - timerStart) / CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			break;
		case 3: 
			heapSort heap;
			fileName = "heap/" + fileName;
			timerStart = clock();
			heap.sort(temp, size);
			cout << "Total Sort Time: " << ((float)(clock() - timerStart) / CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			break;
	}
	
	
	cout << "Please wait, writing file..." << endl;
	fileName = "finishedFiles/" + fileName;

	writeFile outputFile;
	outputFile.write(temp, fileName, size-1);

	cout << "File location: SortingProject/SortingProject/" + fileName << endl;
	
	cout << "Finished\n" << endl;
	/*debugging purposes only.
	prints the sorted list.
	for (int i = 0; i < size; i++) {
		cout << temp[i] << endl;
	}
	*/
	//system("PAUSE");
	//system("CLS");

	char ans;
	while (true) {
		cout << "Would you like to run the program again?(y/n)" << endl;
		cout << "ans: ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			goto begin;
		}
		else if (ans == 'n' || ans == 'N') {
			exit(0);
		}
		else {
			system("CLS");
			cout << "!!Incorrect input!!"<<endl;
		}
	}
    return 0;
}
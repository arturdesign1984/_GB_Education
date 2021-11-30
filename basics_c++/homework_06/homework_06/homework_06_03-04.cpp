
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

void fillArray(int *arr, size_t size);
void createTxtFile(string fileName);
int checkForFile(string fileName);
void insertToTxtFile(string fileName, int* arr, size_t size);
void addContents(string, string, string);


int main() {

	const size_t size = 64;
	int array[size];

	cout << "Enter file name #1:" << endl;
	string fileName1;
	getline(cin, fileName1);
	//cout << endl;

	fillArray(array, size);
	insertToTxtFile(fileName1, array, size);
	if (checkForFile(fileName1)) {
		return 0;
	}
	
	cout << "\nEnter file name #2:" << endl;
	string fileName2;
	getline(cin, fileName2);
	//cout << endl;

	fillArray(array, size);
	insertToTxtFile(fileName2, array, size);
	if (checkForFile(fileName2)) {
		return 0;
	}

	cout << "\nEnter the file name to add the contents of the previous files:" << endl;
	string fileNameAdd;
	getline(cin, fileNameAdd);
	createTxtFile(fileNameAdd);
	if (checkForFile(fileNameAdd)) {
		return 0;
	}
	addContents(fileNameAdd, fileName1, fileName2);
	
	cout << "\n\nPress Enter to exit..." << endl;
	cin.get();
	return 0;
}

void fillArray(int *arr, size_t size) {

	int random = time(nullptr);
	for (int i = 0; i < size; i++) {
		srand(random++);
		arr[i] = rand()%100;
	}

};

void createTxtFile(string fileName) {

	ofstream fileOut(fileName + ".txt");
	fileOut.close();

};

int checkForFile(string fileName) {

	if (fs::exists((fileName + ".txt"))) {
		cout << "File \"" + fileName + ".txt\" is created." << endl;
		return 0;
	}
	else {
		cout << "\n\nError creating file!\n\n\nPress Enter to exit..." << endl;
		cin.get();
		return 1;
	}

};

void insertToTxtFile(string fileName, int* arr, size_t size) {

	ofstream fileOut(fileName + ".txt");
	int j = 1;
	for (int i = 0; i<size; i++){

		int element = arr[i];
		fileOut << "Random number " << j++ << " = " << element << endl;
	}
	fileOut.close();

};

void addContents(string fna, string fn1, string fn2) {

	ifstream fin1((fn1 + ".txt"));
	if (fin1.is_open()) {

		string buf;
		while (!fin1.eof()) {
			getline(fin1, buf);
			ofstream fout((fna + ".txt"), ios_base::app);
			if (buf != "\0") {
				fout << buf << endl;
			}
			fout.close();
		}
	}
	fin1.close();

	ofstream fout((fna + ".txt"), ios_base::app);
	fout << endl << "++++++++ Next file ++++++++\n" << endl;
	fout.close();

	ifstream fin2((fn2 + ".txt"));
	if (fin2.is_open()) {

		string buf;
		while (!fin2.eof()) {
			getline(fin2, buf);
			ofstream fout((fna + ".txt"), ios_base::app);
			if (buf != "\0") {
				fout << buf << endl;
			}
			fout.close();
		}
	}
	fin2.close();
};
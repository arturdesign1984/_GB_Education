
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void initArr(int** pptrArray, size_t sizeH, size_t sizeW);
void printArr(int** pptrArray, size_t sizeH, size_t sizeW);

int main() {

	int** pArr;
	const size_t h = 4;
	const size_t w = 4;
	size_t matrixSize = h * w;


	pArr = new (nothrow) int* [h];
	if (pArr != nullptr) {

		pArr[0] = new (nothrow) int[matrixSize];
		if (pArr != nullptr) {

			for (size_t i = 1; i < h; i++) {
				pArr[i] = pArr[0] + w * i;
			}
			
			initArr(pArr, h, w);

			printArr(pArr, h, w);

			delete[] pArr[0];
			delete[] pArr;
			pArr = nullptr;

		}
		else {
			cout << "Error! Can not allocate memory!";
		}
	}
	else {
		cout << "Error! Can not allocate memory!";
	}
	
	return 0;
}

void initArr(int** pptrArray, size_t sizeH, size_t sizeW) {
	int randCount = time(nullptr);
	for (size_t i = 0; i < sizeH; i++) {
		for (size_t j = 0; j < sizeW; j++) {
			srand(randCount *= 3);
			pptrArray[i][j] = rand() % 100;
		}
	}

};

void printArr(int** pptrArray, size_t sizeH, size_t sizeW) {

	for (size_t i = 0; i < sizeH; i++) {
		cout << endl;
		for (size_t j = 0; j < sizeW; j++) {
			cout << setw(3) << left << pptrArray[i][j];
		}
	}
	cout << endl << endl;
};

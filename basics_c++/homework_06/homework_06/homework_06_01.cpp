
#include <iostream>

using namespace std;

void initArr(int* ptrArray, size_t size);
void printArr(int* ptrArray, size_t size);

int main() {

	int* pArr;
	int n;
	cout << "Enter size of your array: ";    
	cin >> n;

	if (n > 0) {
		pArr = new (nothrow) int[n];
		if (pArr != nullptr)
		{
			initArr(pArr, n);

			printArr(pArr, n);

			delete[] ptrArray;
            ptrArray = nullptr;
            
		}
		else
		{
			cout << "Error! Can not allocate memory!";
		}
	}
	return 0;
}

void initArr(int* ptrArray, size_t size) {

	for (int i = 0, j = 1; i < size; i++) {
		ptrArray[i] = j;
		j = j << 1;
	}

};

void printArr(int* ptrArray, size_t size) {

	for (int i = 0; i < size; i++) {
		cout << ptrArray[i] << " ";
	}
	cout << endl;
};

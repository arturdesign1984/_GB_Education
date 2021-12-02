#include <iostream>

using namespace std;

#define SIZE 5
#define SwapINT(a, b) int x = a; \
						  a = b; \
						  b = x;

int main()
{
	int array[SIZE];

	cout << "Enter " << SIZE << " numbers:" << endl;

	for (int k = 0; k < SIZE; k++) {

		cin >> array[k];
	}

	for (int j = 0; j < (SIZE-1); j++) {

		for (int i = 0; i < (SIZE - 1 - j); i++) {

			if (array[i] > array[i + 1]) {
				
				SwapINT(array[i], array[i + 1])
			}
		}
	}

	cout << endl;

	for (int k = 0; k < SIZE; k++) {

		cout << array[k] << " "; 
	}
	return 0;
}

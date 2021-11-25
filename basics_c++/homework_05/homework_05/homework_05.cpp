
#include <iostream>
#include <cstdlib>

using namespace std;

void coutDoubleFunction(double*, size_t);	// 01
void flipArray(int*, size_t);				// 02
void fillingTheArray(int*, size_t);			// 03
void coutIntFunction(int*, size_t);			// вывод интового одномероного массива на экран
void shiftArray(int*, size_t, int);			// 04
bool checkBalance(int*, size_t);				// 05

int main()
{
//////////////////////////////////////////////////////// 01

	const size_t mySize1 = 5;
	double arr1[mySize1] = { 1.,2.,3.,4.,5.678 };

	coutDoubleFunction(arr1, mySize1);
	cout << endl;

//////////////////////////////////////////////////////// 02

	const size_t mySize2 = 10;
	int arr2[mySize2] = { 1,1,0,0,1,0,1,1,0,0 };

	coutIntFunction(arr2, mySize2);
	flipArray(arr2, mySize2);
	coutIntFunction(arr2, mySize2);
	cout << endl;
	
//////////////////////////////////////////////////////// 03 + 04

	const size_t mySize3 = 8;
	int arr3[mySize3];
	int n = -3;

	fillingTheArray(arr3, mySize3);
	coutIntFunction(arr3, mySize3);

	shiftArray(arr3, mySize3, n);
	coutIntFunction(arr3, mySize3);
	cout << endl;

//////////////////////////////////////////////////////// 05

	const size_t mySize5 = 5;
	int arr5[mySize5] = {10,4,3,2,1};

	coutIntFunction(arr5, mySize5);


	cout << checkBalance(arr5, mySize5);
	if (checkBalance(arr5, mySize5)) {
		cout << " - TRUE" << endl;
	}
	else {
		cout << " - FALSE" << endl;
	}

	return 0;
}



void coutDoubleFunction(double* arr, size_t size) {		// 01

	for (size_t i = 0; i < size; i++) {

		cout << arr[i] << " ";
	}
	cout << endl;
};

void flipArray(int* arr, size_t size) {					// 02

	for (size_t i = 0; i < size; i++) {

		if (arr[i]) {
			arr[i] = 0;
		}
		else {
			arr[i] = 1;
		}
	}
};

void fillingTheArray(int* arr, size_t size) {			// 03

	arr[0] = 1;
	for (size_t i = 1; i < size; i++) {

		arr[i] = arr[i - 1] + 3;
	}
};

void coutIntFunction(int* arr, size_t size) {			// вывод на экран

	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
};

void shiftArray(int* arr, size_t size, int numberOfShifts) { // 04

	if (numberOfShifts == 0) {
		
	}
	else if (numberOfShifts > 0) {  // изменить направление сдвига относительно знака переменной n 
									// можно просто поменяв > на < в - else if (numberOfShifts > 0) 
		for (size_t i = 0; i < abs(numberOfShifts); i++) {

			int temp = arr[size - 1];
			for (size_t j = (size - 1); j > 0; j--) {
				arr[j] = arr[j - 1];
			}
			arr[0] = temp;
		}
	}
	else {

		for (size_t i = 0; i < abs(numberOfShifts); i++) {

			int temp = arr[0];
			for (size_t j = 0; j < (size - 1); j++) {
				arr[j] = arr[j + 1];
			}
			arr[size - 1] = temp;
		}
	}
};

bool checkBalance(int* arr, size_t size) {					// 05

	int countUp = 0, countDown = (size-1);	// счетчики
	int summLeft = 0, summRight = 0;			// суммы

	summLeft = arr[countUp];		// присваиваем начальные значения из массива - первый и последний
	summRight = arr[countDown];

	if (size > 2) {				// если размер массива больше 2 то
		for (size_t i = 0; i < (size - 2); i++) {	// запускаем цикл на 2 меньше чем величина массива, так как первое и последнее значения у нас уже есть
			if (summLeft <= summRight) {				// если сумма слева меньше/равна сумме справа то
				countUp++;							// поднимаем восходящий счетчик
				summLeft += arr[countUp];			// и добавляем к левой сумме следующее значение массива
			}
			else {									// если слева больше то
				countDown--;							// опускаем нисходящий счетчик
				summRight += arr[countDown];			// и добавляем к правой сумме значение из массива, что на один ближе к центру
			}
		}
	}
	else {}

	if (summLeft == summRight) {		// сравниваем получившиеся суммы и если они равны то
		return true;					// ввозвращаем истина
	}
	else {							// иначе
		return false;				// возвращаем ложь
	}
};

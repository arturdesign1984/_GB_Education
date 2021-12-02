#include <iostream>
#include "mylib.h"

using namespace mylib;



int main()
{
	int counersPosNeg[2];
	const size_t sizeOfArray = 10;
	float floatArray[sizeOfArray];

	initFloatArray(floatArray, sizeOfArray);

	printFloatArray(floatArray, sizeOfArray);

	countPositiveAndNeganiveNumbersInFloatArray(floatArray, sizeOfArray, counersPosNeg);

	std::cout << "positives = " << counersPosNeg[1] << std::endl << "negatives = " << counersPosNeg[0] << std::endl;

	return 0;
}

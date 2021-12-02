#include <iostream>
#include <random>

namespace mylib
{
	void initFloatArray(float* arr, size_t size) {

		std::random_device random;
		std::default_random_engine eng(random());
		std::uniform_real_distribution<float> distr(0, 10);
		for (size_t k = 0; k < size; k++) {
			
			arr[k] = -5 + distr(eng);
		}
	}

	void printFloatArray(float* arr, size_t size) {

		for (size_t k = 0; k < size; k++) {

			std::cout << arr[k] << std::endl;
		}
	}

	void countPositiveAndNeganiveNumbersInFloatArray(float* arr, size_t size, int* counters) {

		counters[0] = 0;
		counters[1] = 0;
		
		for (size_t k = 0; k < size; k++) {

			if (arr[k] < 0) {

				counters[0]++;
			}
			else if(arr[k] >= 0){

				counters[1]++;
			}
		}
	}
}
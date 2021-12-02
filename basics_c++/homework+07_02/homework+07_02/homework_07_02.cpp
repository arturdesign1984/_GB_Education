#include <string>
#include <iostream>

#define RANGE(num, max_num) ((num >= 0 && num < max_num) ? "true" : "false")

int main()
{
	int yourNumber, maxNumber = 10;

	std::cout << "Enter your number: ";
	std::cin >> yourNumber;

    std::cout << std::endl << RANGE(yourNumber, maxNumber) << std::endl;
}

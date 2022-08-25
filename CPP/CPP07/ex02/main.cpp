#include <iostream>
#include "Array.hpp"

void test_normal()
{
	Array<int> arr(5);

	arr[0] = 5;
	arr[1] = 1;
	arr[2] = 3;
	arr[3] = 76;

	std::cout << "arr's size : " << arr.size() << std::endl;
	std::cout << "arr[0] : " << arr[0] << std::endl;
	std::cout << "arr[1] : " << arr[1] << std::endl;
	std::cout << "arr[2] : " << arr[2] << std::endl;
	std::cout << "arr[3] : " << arr[3] << std::endl;
	std::cout << "arr[4] : " << arr[4] << std::endl;
	try
	{
		std::cout << "arr[10] : " << arr[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "======= Second array ========" << std::endl;
	Array<int> brr(arr);

	arr[0] = 100;
	std::cout << "arr[0] : " << arr[0] << std::endl;
	std::cout << "brr's size : " << brr.size() << std::endl;
	std::cout << "brr[0] : " << brr[0] << std::endl;
	std::cout << "brr[1] : " << brr[1] << std::endl;
	std::cout << "brr[2] : " << brr[2] << std::endl;
	std::cout << "brr[3] : " << brr[3] << std::endl;
	std::cout << "brr[4] : " << brr[4] << std::endl;

	std::cout << std::endl << "======= THIRD array ========" << std::endl;
	Array<int> crr = arr;

	arr[0] = 500;
	std::cout << "arr[0] : " << arr[0] << std::endl;
	std::cout << "crr's size : " << crr.size() << std::endl;
	std::cout << "crr[0] : " << crr[0] << std::endl;
	std::cout << "crr[1] : " << crr[1] << std::endl;
	std::cout << "crr[2] : " << crr[2] << std::endl;
	std::cout << "crr[3] : " << crr[3] << std::endl;
	std::cout << "crr[4] : " << crr[4] << std::endl;
}

int main()
{
	test_normal();
	system("leaks a.out");
}

#include "Array.hpp"

int main()
{
	std::cout << "=== Test 1: Default constructor ===" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	std::cout << "\n=== Test 2: Parameterized constructor ===" << std::endl;
	Array<int> intArr(5);
	std::cout << "Int array size: " << intArr.size() << std::endl;
	std::cout << "Default values: ";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n=== Test 3: Element access (read/write) ===" << std::endl;
	for (unsigned int i = 0; i < intArr.size(); i++)
		intArr[i] = i * 10;
	std::cout << "After assignment: ";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n=== Test 4: Copy constructor (deep copy) ===" << std::endl;
	Array<int> copyArr(intArr);
	std::cout << "Copied array: ";
	for (unsigned int i = 0; i < copyArr.size(); i++)
		std::cout << copyArr[i] << " ";
	std::cout << std::endl;

	copyArr[0] = 999;
	std::cout << "After modifying copy[0] = 999:" << std::endl;
	std::cout << "Original[0]: " << intArr[0] << std::endl;
	std::cout << "Copy[0]: " << copyArr[0] << std::endl;

	std::cout << "\n=== Test 5: Assignment operator (deep copy) ===" << std::endl;
	Array<int> assignArr;
	assignArr = intArr;
	std::cout << "Assigned array: ";
	for (unsigned int i = 0; i < assignArr.size(); i++)
		std::cout << assignArr[i] << " ";
	std::cout << std::endl;

	assignArr[1] = 888;
	std::cout << "After modifying assigned[1] = 888:" << std::endl;
	std::cout << "Original[1]: " << intArr[1] << std::endl;
	std::cout << "Assigned[1]: " << assignArr[1] << std::endl;

	std::cout << "\n=== Test 6: Self-assignment ===" << std::endl;
	intArr = intArr;
	std::cout << "After self-assignment: ";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n=== Test 7: Out of bounds exception ===" << std::endl;
	try
	{
		std::cout << "Trying to access index 10..." << std::endl;
		std::cout << intArr[10] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Trying to access empty array[0]..." << std::endl;
		std::cout << empty[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 8: String array ===" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "World";
	strArr[2] = "42";
	std::cout << "String array: ";
	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n=== Test 9: Const array access ===" << std::endl;
	const Array<int> constArr(intArr);
	std::cout << "Const array: ";
	for (unsigned int i = 0; i < constArr.size(); i++)
		std::cout << constArr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n=== All tests completed ===" << std::endl;

	return 0;
}

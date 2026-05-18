#include "Base.hpp"

int main()
{
	srand(time(0));

	std::cout << "=== Test 1 ===" << std::endl;
	Base* obj1 = generate();
	std::cout << "ptr: ";
	identify(obj1);
	std::cout << "ref: ";
	identify(*obj1);

	std::cout << "\n=== Test 2 ===" << std::endl;
	Base* obj2 = generate();
	std::cout << "ptr: ";
	identify(obj2);
	std::cout << "ref: ";
	identify(*obj2);

	std::cout << "\n=== Test 3 ===" << std::endl;
	Base* obj3 = generate();
	std::cout << "ptr: ";
	identify(obj3);
	std::cout << "ref: ";
	identify(*obj3);

	std::cout << "\n=== Test 4 ===" << std::endl;
	Base* obj4 = generate();
	std::cout << "ptr: ";
	identify(obj4);
	std::cout << "ref: ";
	identify(*obj4);

	std::cout << "\n=== Test 5 ===" << std::endl;
	Base* obj5 = generate();
	std::cout << "ptr: ";
	identify(obj5);
	std::cout << "ref: ";
	identify(*obj5);

	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;
	delete obj5;

	return 0;
}
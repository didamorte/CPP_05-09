#include "Serializer.hpp"

int main()
{
	Data data;
	data.value = 42;
	data.name = "hello";

	std::cout << "=== Original Data ===" << std::endl;
	std::cout << "ptr:   " << &data << std::endl;
	std::cout << "value: " << data.value << std::endl;
	std::cout << "name:  " << data.name << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "\n=== After serialize ===" << std::endl;
	std::cout << "uintptr_t: " << raw << std::endl;

	Data* result = Serializer::deserialize(raw);
	std::cout << "\n=== After deserialize ===" << std::endl;
	std::cout << "ptr:   " << result << std::endl;
	std::cout << "value: " << result->value << std::endl;
	std::cout << "name:  " << result->name << std::endl;

	return 0;
}
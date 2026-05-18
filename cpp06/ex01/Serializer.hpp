#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <string>
#include <iostream>

struct Data {
	int value;
	std::string name;
};

class Serializer {
private:
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();

public:
	static uintptr_t serialize(Data* ptr) {
		return reinterpret_cast<uintptr_t>(ptr);
	}

	static Data* deserialize(uintptr_t raw) {
		return reinterpret_cast<Data*>(raw);
	}
};

#endif
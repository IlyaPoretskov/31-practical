#pragma once
#include <iostream>
#include <string>

class Toy {
public:
	Toy(const std::string& _name) : name(_name) {};
	Toy() : Toy("Nothing") {};
	std::string getName() { return name; }
	Toy(const Toy& other) : name(other.name) {};
	Toy& operator=(const Toy& other) {
		if (this == &other)
			return *this;
		name = other.name;
		return *this;
	}
private:
	std::string name;
};


class shared_ptr_toy {
public:
	shared_ptr_toy(std::string _name) {
		toy = new Toy(_name);
		c = new int(1);
	}
	shared_ptr_toy() {
		toy = nullptr;
		c = new int(0);
	}
	shared_ptr_toy(shared_ptr_toy& other) {
		toy = other.toy;
		c = other.c;
		*c += 1;
	}
	shared_ptr_toy& operator=(shared_ptr_toy& other) {
		if (this == &other)
			return *this;
		if (*c <= 1) {
			delete c;
			if (toy != nullptr)
				delete toy;
		}
		else
			*c -= 1;
		c = other.c;
		*c += 1;
		toy = other.toy;
		return *this;
	}
	std::string getToyName() {
		if (toy == nullptr)
			return "Nothing";
		return toy->getName();
	}
	int use_count() { return *c; }
	~shared_ptr_toy() {
		if (toy && c) {
			if (*c > 1) {
				std::cout << "Toy " << toy->getName() << " was dropped" << std::endl;
				*c -= 1;
			}
			else {
				delete toy;
				delete c;
			}
		}
	}
	void reset() {
		std::cout << "Toy " << toy->getName() << " was dropped" << std::endl;
		if (*c <= 1) {
			if (toy)
				delete toy;
		}
		toy = nullptr;
		c = new int(0);
	}
private:
	Toy* toy;
	int* c;
};
shared_ptr_toy make_shared_toy(std::string _name) { return shared_ptr_toy(_name); }
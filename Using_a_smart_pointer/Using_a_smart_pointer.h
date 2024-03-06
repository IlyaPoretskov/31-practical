// Using_a_smart_pointer.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <string>

#define DEBUG 0



class Toy {
public:
	Toy(const std::string& _name) {
		name = _name;
	}
	std::string getName() {
		return name;
	}
private:
	std::string name;
};



class Dog
{
public:
	Dog(std::string _name, std::shared_ptr<Toy> _toy, int _age) : name(_name), toy(_toy)
	{
		age = 0;
		if (_age >= 0 && age < 30)
			age = _age;
	}
	Dog() : Dog("Sharik", std::make_shared<Toy>("SomeName"), 0) {};
	Dog(std::string _name) : Dog(_name, std::make_shared<Toy>("SomeName"), 0) {};
	Dog(std::shared_ptr<Toy> _toy) : Dog("Sharik", _toy, 0) {};
	Dog(int _age) : Dog("Sharik", std::make_shared<Toy>("SomeName"), _age) {};
	Dog(std::string _name, std::shared_ptr<Toy> _toy) : Dog(_name, _toy, 0) {};
	Dog(std::shared_ptr<Toy> _toy, int _age) : Dog("Sharik", _toy, _age) {};
	Dog(std::string _name, int _age) : Dog(_name, std::make_shared<Toy>("SomeName"), _age) {};

	inline void getToy(const std::shared_ptr<Toy>& other, int use_count)
	{
#if DEBUG:
		std::cout << toy.use_count() << std::endl;
#endif
		if (toy == other)
		{
			std::cout << "I already have this toy" << std::endl;
		}
		else if (use_count > 1)
		{
			std::cout << "Another dog is playing with this toy" << std::endl;
		}
		else 
		{
			toy = other;
		}
	}
	void dropToy()
	{
		if (toy->getName() == "" || toy->getName() == "SomeName")
		{
			std::cout << "Nothing to drop" << std::endl;
		}
		else
		{
			toy.reset();
		}
	}
	std::string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}

private:
	std::string name;
	int age;
	std::shared_ptr<Toy> toy;
};
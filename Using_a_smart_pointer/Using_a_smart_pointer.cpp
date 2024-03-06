// Using_a_smart_pointer.cpp: определяет точку входа для приложения.
//

#include "Using_a_smart_pointer.h"



int main()
{
	std::cout << "Please name the toy: " << std::endl;
	std::string toyname;
	std::cin >> toyname;

	std::shared_ptr<Toy> toy = std::make_shared<Toy>(toyname);

#if DEBUG:
	std::cout << toy.use_count() << std::endl;
#endif

	std::string firstDogName, secondDogName;
	int firstDogAge, secondDogAge;

	std::unique_ptr<Dog> a;
	std::unique_ptr<Dog> b;

#if DEBUG:
	std::cout << toy.use_count() << std::endl;
#endif

	std::cout << "There's two dogs, please, name them and point out their age: " << std::endl;
	std::cout << "First: ";
	std::cin >> firstDogName >> firstDogAge;

	std::cout << "Second: ";
	std::cin >> secondDogName >> secondDogAge;

	while (secondDogName == firstDogName)
	{
		std::cerr << "Wrong input, names can only be different, please, try again" << std::endl;
		std::cout << "Please enter second dog's name and age: " << std::endl;
		std::cin >> secondDogAge >> secondDogName;
	}
	
	a = std::make_unique<Dog>(firstDogName, firstDogAge);
	b = std::make_unique<Dog>(secondDogName, secondDogAge);

#if DEBUG:
	std::cout << toy.use_count() << std::endl;
#endif

	while (true)
	{
		std::string command;
		std::string owner;

		std::cout << "Please, enter the command(get, drop, exit) " << std::endl;
		std::cin >> command;

		while (command != "get" && command != "drop" && command != "exit")
		{
			std::cerr << "Wrong input, there's no similar command, please, try again" << std::endl;
			std::cout << "Please, enter the command(get< drop, exit) " << std::endl;
			std::cin >> command;
		}

		if (command == "get")
		{

			std::cout << "Please, enter who will be playing with the " << toyname << ": " << std::endl;
			std::cin >> owner;

			while (owner != a->getName() && owner != b->getName())
			{
				std::cerr << "Wrong input, there's no dogs with that name, please, try again" << std::endl;
				std::cout << "Please, enter who will be playing with the " << toyname << ": " << std::endl;
				std::cin >> owner;
			}

			if (owner == a->getName())
			{
				a->getToy(toy, toy.use_count());
#if DEBUG:
				std::cout << toy.use_count() << std::endl;
#endif
			}
			else
			{
				b->getToy(toy, toy.use_count());
#if DEBUG:
				std::cout << toy.use_count() << std::endl;
#endif
			}
		}
		else if (command == "drop")
		{
			std::string dropper;
			std::cout << "Please enter, who will drop the " << toy->getName() << ": " << std::endl;
			std::cin >> dropper;

			while (dropper != a->getName() && dropper != b->getName())
			{
				std::cerr << "Wrong input, there's no dogs with that name, please, try again" << std::endl;
				std::cout << "Please enter, who will drop the " << toy->getName() << ": " << std::endl;
				std::cin >> dropper;
			}

			if (dropper == a->getName())
			{
				a->dropToy();

#if DEBUG:
				std::cout << toy.use_count() << std::endl;
#endif
			} 
			else
			{
				b->dropToy();
#if DEBUG:
				std::cout << toy.use_count() << std::endl;
#endif
			}
		}
		else
		{
			break;
		}
	}
	std::cout << "Goodbye!" << std::endl;
	system("pause");
}
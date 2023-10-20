#include "../include/headers.hpp"

static void welcome(void)
{
	std::cout << "Welcome to the PhoneBook!" << std::endl;
	std::cout << "Please enter one of the following commands:" << std::endl;
	std::cout << "- ADD" << std::endl;
	std::cout << "- SEARCH" << std::endl;
	std::cout << "- EXIT" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

int main()
{
	PhoneBook phonebook = PhoneBook();

	welcome();
	while (phonebook.prompt())
		;
	std::cout << "Goodbye!" << std::endl;
	return (0);
}
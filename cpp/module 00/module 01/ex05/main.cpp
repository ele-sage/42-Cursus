#include "Harl.hpp"

int main()
{
    std::string input;
    Harl        harl;

    std::cout << "To close the program, enter: exit" << std::endl;
    std::cout << "level: DEBUG, INFO, WARNING, ERROR" << std::endl;
    while (1)
    {
        std::cout << std::endl << "Enter a level: ";
        std::cin >> input;
        if (input == "exit")
            break;
        harl.complain(input);
    }

    return (0);
}
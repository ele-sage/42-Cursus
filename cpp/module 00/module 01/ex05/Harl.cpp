#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void    Harl::debug(void)
{
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain( std::string level )
{
    struct LevelFunctionPair {
        std::string level;
        void (Harl::*function)();
    };
    
    LevelFunctionPair levelFunctionPairs[] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };
    
    for (size_t i = 0; i < levelFunctionPairs->level.length(); i++)
    {
        if (levelFunctionPairs[i].level == level)
        {
            (this->*levelFunctionPairs[i].function)();
            return;
        }
    }

    std::cout << "Invalid level: " << level << std::endl;
}
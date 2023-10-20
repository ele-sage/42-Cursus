#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void    Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void    Harl::complain(const char *level)
{
    struct LevelFunctionPair {
        const char *level;
        void (Harl::*function)();
    };
    
    LevelFunctionPair levelFunctionPairs[] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };

    switch (level[0])
    {
        case 'D':
            (this->*levelFunctionPairs[0].function)();
        case 'I':
            (this->*levelFunctionPairs[1].function)();
        case 'W':
            (this->*levelFunctionPairs[2].function)();
        case 'E':
            (this->*levelFunctionPairs[3].function)();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    } 
}
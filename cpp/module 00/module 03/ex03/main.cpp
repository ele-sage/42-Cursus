#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d1("first");
    DiamondTrap d2("second");

    d1 = d2;
    d1.whoAmI();
    d2.whoAmI();
    
    return (0);
}
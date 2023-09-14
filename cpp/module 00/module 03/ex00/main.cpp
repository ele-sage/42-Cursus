#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap    eboyce("eboyce");
    ClapTrap    staff("cory");

    staff.attack("eboyce");
    eboyce.takeDamage(2);
    eboyce.beRepaired(1);
    eboyce.attack("cory");
    staff.takeDamage(100);
    staff.beRepaired(100);
    staff.attack("eboyce");
    
    return (0);
}
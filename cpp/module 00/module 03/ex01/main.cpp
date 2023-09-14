#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap    scav("Emile");

    scav.attack("a tree");
    scav.takeDamage(2);
    scav.beRepaired(1);
    scav.guardGate();
    scav.attack("a wall");
    scav.takeDamage(100);
    scav.beRepaired(100);

    return (0);
}
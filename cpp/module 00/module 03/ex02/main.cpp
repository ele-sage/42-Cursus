#include "FragTrap.hpp"

int main( void )
{
    FragTrap    frag("Emile");

    frag.attack("water");
    frag.takeDamage(2);
    frag.beRepaired(1);
    frag.highFivesGuys();
    frag.attack("air");
    frag.takeDamage(100);
    frag.beRepaired(100);

    return (0);
}
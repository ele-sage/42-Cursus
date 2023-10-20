#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap claptrap("myClap");
    claptrap.attack("Cat");
    claptrap.takeDamage(5);
    claptrap.beRepaired(5);
    for (size_t i = 0; i < 10; i++)
    {
        claptrap.attack("Cat"); // attaque 10 fois 
    }
    // na plus denergie

    ClapTrap claptrap2("myClap2");
    claptrap2 = claptrap; // operateur assignation =
    claptrap2.beRepaired(20); // ne peut pas reparer car aucune energie

    ClapTrap claptrap3(claptrap2); // constructeur copie
    claptrap3.attack("Cat"); // ne peut pas attaquer car aucune energie

    // apelle les 3 destructeurs
    return 0;
}
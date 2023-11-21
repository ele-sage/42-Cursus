#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap me("me");
    DiamondTrap me2(me);
    DiamondTrap me3(".");

    me.whoAmI();
    me2.whoAmI();
	me3.whoAmI();
    me3 = me;
    me3.whoAmI();

    me.attack("the dummy");
    me.takeDamage(10 );
    me.beRepaired(10);

    return 0;
}
#include "../include/ClapTrap.hpp"

int main()
{
    ClapTrap clap("Swordfish");
    clap.attack("Enemy");
    clap.takeDamage(3);
    clap.beRepaired(2);

    return 0;
}
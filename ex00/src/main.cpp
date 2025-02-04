#include "../include/ClapTrap.hpp"

int main()
{
    ClapTrap clap("Swordfish");
    clap.attack("Pirate");
    clap.takeDamage(1);
    clap.takeDamage(5);
    clap.beRepaired(2);

    return 0;
}
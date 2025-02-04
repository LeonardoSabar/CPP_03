#include "../include/ClapTrap.hpp"

int main()
{
    ClapTrap clap("Swordfish");
    clap.attack("Pirate");
    clap.takeDamage(1);
    clap.takeDamage(5);
    clap.attack("Pirate");
    clap.attack("Pirate");
    clap.attack("Pirate");
    clap.beRepaired(2);
    clap.takeDamage(10);
    clap.takeDamage(10);
    clap.beRepaired(10);

    return 0;
}
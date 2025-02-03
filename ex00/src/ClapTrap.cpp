#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout <<  Y << "ClapTrap " << Name << " created!" << RST << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << RED << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << RST << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    HitPoints -= amount;
    std::cout << G << Name << " took " << amount << " points of damage!" << RST << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    HitPoints += amount;
    std::cout << B << Name << " was repaired for " << amount << " hit points!" << RST << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << O << "ClapTrap " << Name << " destroyed!" << RST << std::endl;
}
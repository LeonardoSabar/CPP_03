#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    if (HitPoints != 10 || EnergyPoints != 10 || AttackDamage != 0)
    {
        std::cout << O << "Invalid points for ClapTrap " << Name << "!" << RST << std::endl;
        return;
    }
    std::cout << Y << "ClapTrap " << Name << " created!" << RST << std::endl;
}


void ClapTrap::attack(const std::string &target)
{
    std::cout << P << "ClapTrap " << Name << " attacks " << target 
              << ", causing " << AttackDamage << " points of damage!" << RST << std::endl;
    HitPoints--;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > INT_MAX)
    {
        std::cout << RED << "Invalid damage amount!" << RST << std::endl;
        return;
    }

    if (HitPoints <= 0)
    {
        std::cout << M << "ClapTrap " << Name << " received " << amount 
            << " points of damage, but it is already dead!" << RST << std::endl;
        return;
    }

    if (amount >= HitPoints)
    {
        std::cout << RED << "ClapTrap " << Name << " received " << amount 
            << " points of damage and died!" << RST << std::endl;
        HitPoints = 0;
        return;
    }

    HitPoints -= amount;
    std::cout << RED << "ClapTrap " << Name << " took " 
        << amount << " points of damage!" << RST << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount)
{

    HitPoints--;
    if (amount > INT_MAX)
    {
        std::cout << M << "Invalid repair amount!" << RST << std::endl;
        return;
    }

    if (HitPoints <= 0)
    {
        std::cout << M << "ClapTrap " << Name 
            << " cannot be repaired, because it is dead!" << RST << std::endl;
        return;
    }

    HitPoints += amount;
    if (HitPoints > 10)
    {
        HitPoints = 10;
    }

    std::cout << G << "ClapTrap " << Name << " was repaired for " << amount 
        << " hit points. And now it has " << HitPoints << " hit points!" << RST << std::endl;
}


ClapTrap::~ClapTrap() {
    std::cout << O << "ClapTrap " << Name << "'s body was destroyed!" << RST << std::endl;
}
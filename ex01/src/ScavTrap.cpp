/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:44:55 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/03 22:44:55 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"


// ########################  Constructor and Destructor ########################

ScavTrap::ScavTrap(std::string name) : ClapTrap() 
{
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << Y << "ScavTrap " << name << " created!" << RST << std::endl; 
}

ScavTrap::ScavTrap() : ClapTrap()
{
    this->setName("Ordinary Joe");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << Y << "ScavTrap " << this->getName() 
        << " created!" << RST << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << O << "The ScavTrap components of " << this->Name 
        << " were destroyed!" << RST << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.getName())
{
    *this = other;
    std::cout << Y << "ScavTrap " << other.getName() << " created!" << RST << std::endl; 
}


// ########################  Operator Overloadings ########################

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        this->setName(other.getName());
        this->setHitPoints(other.getHitPoints());
        this->setEnergyPoints(other.getEnergyPoints());
        this->setAttackDamage(other.getAttackDamage());
    }
    return *this;
}	


// ###########################  Member Functions ###########################

void ScavTrap::guardGate()
{
    if (HitPoints <= 0)
    {
        std::cout << M << "ScavTrap " << Name << " cannot guard the gate, because they are already dead!" << RST << std::endl;
        return;
    }
    std::cout << B << "ScavTrap " << Name << " is now in Gate keeper mode!" << RST << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
    if (this->HitPoints <= 0)
    {
        std::cout << M << "ScavTrap " << Name << " cannot attack, because they are already dead!" << RST << std::endl;
        return;
    }
    if (this->EnergyPoints <= 0)
    {
        std::cout << M << "ClapTrap " << this->Name 
            << " cannot attack, because they have no energy!" << RST << std::endl;
        return;
    }
    std::cout << P << "ScavTrap " << Name << " attacks " << target 
        << ", causing " << AttackDamage << " points of damage!" << RST << std::endl;
}

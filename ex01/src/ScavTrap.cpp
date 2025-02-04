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

ScavTrap::ScavTrap(std::string name) : ClapTrap() 
{
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << Y << "ScavTrap " << name << " created!" << RST << std::endl; 
}

ScavTrap::~ScavTrap() {
    std::cout << O << "ScavTrap " << Name << " destroyed!" << RST << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.getName())
{
    *this = other;
    std::cout << Y << "ScavTrap " << other.getName() << " created!" << RST << std::endl; 
}

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


void ScavTrap::attack(const std::string &target)
{
    std::cout << RED << "ScavTrap " << Name << " attacks " << target 
              << " with a different strategy, causing " << AttackDamage << " points of damage!" << RST << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << B << "ScavTrap " << Name << " is now in Gate keeper mode!" << RST << std::endl;
}

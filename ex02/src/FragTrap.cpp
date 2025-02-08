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

#include "../includes/FragTrap.hpp"


// ########################  Constructor and Destructor ########################

FragTrap::FragTrap(std::string name) : ClapTrap() 
{
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(20);
    std::cout << Y << "FragTrap " << this->Name << " created!" << RST << std::endl; 
}

FragTrap::FragTrap() : ClapTrap()
{
    this->setName("Joe");
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(20);
    std::cout << Y << "FragTrap " << this->Name << " created!" << RST << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.getName())
{
    *this = other;
    std::cout << Y << "FragTrap " 
        << other.getName() << " created!" << RST << std::endl; 
}
FragTrap::~FragTrap()
{
    std::cout << O << "The FragTrap components of " << this->Name 
    << " were destroyed!" << RST << std::endl;
}


// ########################  Operator Overloadings ########################

FragTrap &FragTrap::operator=(const FragTrap &other)
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

void FragTrap::highFivesGuys()
{
    if (HitPoints <= 0)
    {
        std::cout << M << "FragTrap " << this->Name 
            << " cannot request high fives, because they are already dead!" 
                << RST << std::endl;
        return;
    }
    std::cout << B << "FragTrap " << this->Name 
        << " requests high fives!" << RST << std::endl;
}

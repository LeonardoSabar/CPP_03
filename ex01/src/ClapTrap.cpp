/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:44:39 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/03 22:44:39 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    if (HitPoints != 10 || EnergyPoints != 10 || AttackDamage != 0)
    {
        std::cout << O << "Invalid points for ClapTrap " << this->Name << "!" << RST << std::endl;
        return;
    }
    std::cout << Y << "ClapTrap " << this->Name << " created!" << RST << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << Y << "ClapTrap " << this->Name << " created!" << RST << std::endl;
}

ClapTrap::ClapTrap()
{
    std::cout << Y << "A Ordinary ClapTrap was created!" << RST << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->Name = other.Name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return *this;
}


std::string ClapTrap::getName() const
{
    return this->Name;
}

int ClapTrap::getHitPoints() const
{
    return this->HitPoints;
}

int ClapTrap::getEnergyPoints() const
{
    return this->EnergyPoints;
}

int ClapTrap::getAttackDamage() const
{
    return this->AttackDamage;
}

void ClapTrap::setName(std::string name)
{
    this->Name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
    this->HitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
    this->EnergyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
    this->AttackDamage = attackDamage;
}


void ClapTrap::attack(const std::string &target)
{
    std::cout << P << "ClapTrap " << this->Name << " attacks " << target 
              << ", causing " << this->AttackDamage << " points of damage!" << RST << std::endl;
    this->HitPoints--;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > INT_MAX)
    {
        std::cout << RED << "Invalid damage amount!" << RST << std::endl;
        return;
    }

    if (this->HitPoints <= 0)
    {
        std::cout << M << "ClapTrap " << this->Name << " received " << amount 
            << " points of damage, but it is already dead!" << RST << std::endl;
        return;
    }

    if (amount >= this->HitPoints)
    {
        std::cout << RED << "ClapTrap " << this->Name << " received " << amount 
            << " points of damage and died!" << RST << std::endl;
        this->HitPoints = 0;
        return;
    }

    this->HitPoints -= amount;
    std::cout << RED << "ClapTrap " << this->Name << " took " 
        << amount << " points of damage!" << RST << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount)
{

    this->HitPoints--;
    if (amount > INT_MAX)
    {
        std::cout << M << "Invalid repair amount!" << RST << std::endl;
        return;
    }

    if (this->HitPoints <= 0)
    {
        std::cout << M << "ClapTrap " << this->Name 
            << " cannot be repaired, because it is dead!" << RST << std::endl;
        return;
    }

    this->HitPoints += amount;
    if (this->HitPoints > 10)
    {
        this->HitPoints = 10;
    }

    std::cout << G << "ClapTrap " << this->Name << " was repaired for " << amount 
        << " hit points. And now it has " << this->HitPoints << " hit points!" << RST << std::endl;
}


ClapTrap::~ClapTrap() {
    std::cout << O << "ClapTrap " << this->Name << "'s body was destroyed!" << RST << std::endl;
}
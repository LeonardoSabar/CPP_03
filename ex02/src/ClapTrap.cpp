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

// ###########################  Static Functions ################################

static void ClapTrapDraw() {
    std::cout << B << "               " << std::endl;
    std::cout << B << "               __    HI" << std::endl;
    std::cout << B << "       _(\\    |"<< RST << Y << "@@" << RST 
        << B << "|     " << std::endl;
    std::cout << B << "      (__/\\__ \\--/ __ " << std::endl;
    std::cout << B << "         \\___|----|  |   __ " << std::endl;
    std::cout << B << "             \\ }{ /\\ )_ / _\\ " << std::endl;
    std::cout << B << "             /\\__/\\ \\__O (__ " << std::endl;
    std::cout << B << "            (--/\\--)    \\__/ " << std::endl;
    std::cout << B << "            _)(  )(_        " << std::endl;
    std::cout << B << "           `---''---`      " << std::endl;
    std::cout << RST << "               " << std::endl;
}


// ########################  Constructor and Destructor ########################

ClapTrap::ClapTrap(std::string name) : Name(name), 
    HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    ClapTrapDraw();
    std::cout << Y << "ClapTrap " << this->Name 
        << " created!" << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << Y << "ClapTrap " << this->Name 
        << " created!" << RST << std::endl;
}

ClapTrap::ClapTrap() : Name("Joe"), 
    HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    ClapTrapDraw();
    std::cout << Y << "ClapTrap " << this->Name 
        << " created!" << RST << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << O << "The ClapTrap components of " << this->Name 
        << " were destroyed!" << RST << std::endl;
}


// ########################  Operator Overloadings ########################

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


// ###########################  Member Functions ###########################

void ClapTrap::attack(const std::string &target)
{
    if (EnergyPoints <= 0)
    {
        std::cout << M << "ClapTrap " << this->Name 
            << " cannot attack, because they have no energy!" << RST << std::endl;
        return;
    }
    if (HitPoints <= 0)
    {
        std::cout << M << "ClapTrap " << Name 
            << " cannot attack, because they are dead!" << RST << std::endl;
        return;
    }
    std::cout << P << "ClapTrap " << this->Name << " attacks " << target 
              << ", causing " << this->AttackDamage 
                << " points of damage!" << RST << std::endl;
    this->EnergyPoints--;
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
            << " points of damage, but they are already dead!" << RST << std::endl;
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
    if (EnergyPoints <= 0)
    {
        std::cout << M << "ClapTrap " << this->Name 
            << " cannot be repaired, because they have no energy!" 
                << RST << std::endl;
        return;
    }

    this->EnergyPoints--;
    if (this->HitPoints <= 0)
    {
        std::cout << M << "ClapTrap " << this->Name 
            << " cannot be repaired, because they are already dead!" 
                << RST << std::endl;
        return;
    }

    this->HitPoints += amount;
    if (this->HitPoints > 10)
    {
        this->HitPoints = 10;
    }

    std::cout << G << "ClapTrap " << this->Name << " was repaired for " << amount 
        << " hit points. And now they have " 
            << this->HitPoints << " hit points!" << RST << std::endl;
}

// ###########################  Getters and Setters ###########################

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


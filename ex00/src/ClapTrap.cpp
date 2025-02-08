/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:44:11 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/08 10:26:41 by leobarbo         ###   ########.fr       */
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

ClapTrap::ClapTrap() : Name("Joe"),
	HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	ClapTrapDraw();
	std::cout << Y << "ClapTrap " << this->Name
		<< " created!" << RST << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	ClapTrapDraw();
	std::cout << Y << "ClapTrap " << this->Name << " created!" << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << Y << "ClapTrap " << this->Name << " created!" << RST << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << O << "ClapTrap " << this->Name << "'s body was destroyed!" << RST << std::endl;
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


// ########################  Member Functions ########################

void ClapTrap::attack(const std::string &target)
{
	if (HitPoints <= 0)
	{
		std::cout << M << "ClapTrap " << this->Name << " cannot attack, because they are dead!" << RST << std::endl;
		return;
	}
	if (EnergyPoints <= 0)
	{
		std::cout << M << "ClapTrap " << this->Name
			<< " cannot attack, because they have no energy!" << RST << std::endl;
		return;
	}
	std::cout << P << "ClapTrap " << this->Name << " attacks " << target
			  << ", causing " << AttackDamage << " points of damage!" << RST << std::endl;
	this->EnergyPoints--;
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
		std::cout << M << "ClapTrap " << this->Name << " received " << amount
			<< " points of damage, but they are already dead!" << RST << std::endl;
		return;
	}

	if (amount >= static_cast<unsigned int>(HitPoints))
	{
		std::cout << RED << "ClapTrap " << this->Name << " received " << amount
			<< " points of damage and died!" << RST << std::endl;
		HitPoints = 0;
		return;
	}

	HitPoints -= amount;
	std::cout << RED << "ClapTrap " << this->Name << " took "
		<< amount << " points of damage!" << RST << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints <= 0)
	{
		std::cout << M << "ClapTrap " << this->Name
			<< " cannot be repaired, because they have no energy!"
				<< RST << std::endl;
		return;
	}

	this->EnergyPoints--;
	if (amount > INT_MAX)
	{
		std::cout << M << "Invalid repair amount!" << RST << std::endl;
		return;
	}

	if (this->HitPoints <= 0)
	{
		std::cout << M << "ClapTrap " << this->Name
			<< " cannot be repaired, because they are already dead!" << RST << std::endl;
		return;
	}

	this->HitPoints += amount;
	if (this->HitPoints > 10)
	{
		this->HitPoints = 10;
	}

	std::cout << G << "ClapTrap " << this->Name << " was repaired for " << amount
		<< " hit points. And now they have " << this->HitPoints << " hit points!" << RST << std::endl;
}

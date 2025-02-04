
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../includes/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ~ScavTrap();
    
    ScavTrap &operator=(const ScavTrap &other);
    
    void attack(const std::string &target);
    void guardGate();
};

#endif
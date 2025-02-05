/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:44:48 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/03 22:44:48 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main()
{
    ScavTrap scav;
    scav.attack("Target1");
    scav.guardGate();
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.takeDamage(100);
    scav.beRepaired(100);
    scav.beRepaired(100);
    scav.takeDamage(101);
    scav.attack("Target2");
    scav.guardGate();
    
    return 0;
}
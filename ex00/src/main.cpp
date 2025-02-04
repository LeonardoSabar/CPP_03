/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:44:20 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/03 22:44:20 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
    ClapTrap clap("Swordfish");
    clap.attack("Pirate");
    clap.takeDamage(1);
    clap.takeDamage(5);
    clap.attack("Pirate");
    clap.attack("Pirate");
    clap.attack("Pirate");
    clap.beRepaired(2);
    clap.takeDamage(10);
    clap.takeDamage(10);
    clap.beRepaired(10);

    return 0;
}
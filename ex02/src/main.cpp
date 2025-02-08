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

#include "../includes/FragTrap.hpp"

int main()
{
    FragTrap clap;
    clap.attack("Pirate");
    clap.takeDamage(80);
    clap.highFivesGuys();
    clap.takeDamage(5);
    clap.takeDamage(45);
    clap.takeDamage(45);
    clap.attack("Pirate");
    clap.attack("Pirate");
    clap.highFivesGuys();
    
    return 0;
}
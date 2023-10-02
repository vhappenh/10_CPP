/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:41:35 by vhappenh          #+#    #+#             */
/*   Updated: 2023/10/02 15:10:48 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	try {
        Bureaucrat bureaucrat("ash", 2);
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << "\n---------------first test----------------" << std::endl;
		form1.beSigned(bureaucrat);
		bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        std::cout << "\n---------------second test---------------" << std::endl;
		form2.beSigned(bureaucrat);
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        std::cout << "\n---------------third test----------------" << std::endl;
		form3.beSigned(bureaucrat);
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
		std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

	return (0);
}
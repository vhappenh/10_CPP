/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:41:35 by vhappenh          #+#    #+#             */
/*   Updated: 2023/09/13 10:37:48 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	// AForm			*form = NULL;
	// Bureaucrat		bob("bob", 1);
	// Bureaucrat		phil("phil", 40);
	// Bureaucrat		luc("luc", 150);

	// try
	// {
	// 	form = new PresidentialPardonForm("28Z");
	// 	form->execute(bob);
	// 	delete form;
	// 	form = NULL;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try
	// {
	// 	form = new PresidentialPardonForm("28A");
	// 	form->beSigned(bob);
	// 	form->execute(bob);
	// 	delete form;
	// 	form = NULL;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }


	// try
	// {
	// 	form = new RobotomyRequestForm("28B");
	// 	form->beSigned(bob);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	form->execute(phil);
	// 	delete form;
	// 	form = NULL;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }


	// try
	// {
	// 	form = new ShrubberyCreationForm("28C");
	// 	form->beSigned(bob);
	// 	form->execute(phil);
	// 	form->execute(luc);
	// 	delete form;
	// 	form = NULL;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	try {
        Bureaucrat bureaucrat("ash", 2); // error with 200
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
		std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

	return (0);
}
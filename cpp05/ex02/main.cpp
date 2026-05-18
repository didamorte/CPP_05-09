#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "========================================" << std::endl;
	std::cout << "       SHRUBBERY CREATION FORM         " << std::endl;
	std::cout << "========================================" << std::endl;

	std::cout << "\n--- Shrubbery: SUCCESS ---" << std::endl;
	{
		Bureaucrat bob("Bob", 137);
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		bob.signForm(shrub);
		bob.executeForm(shrub);
	}

	std::cout << "\n--- Shrubbery: FAIL sign (grade too low) ---" << std::endl;
	{
		Bureaucrat intern("Intern", 146);
		ShrubberyCreationForm shrub("garden");
		std::cout << intern << std::endl;
		intern.signForm(shrub);
	}

	std::cout << "\n--- Shrubbery: FAIL execute (not signed) ---" << std::endl;
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("office");
		boss.executeForm(shrub);
	}

	std::cout << "\n--- Shrubbery: FAIL execute (grade too low) ---" << std::endl;
	{
		Bureaucrat signer("Signer", 145);
		Bureaucrat executor("Executor", 140);
		ShrubberyCreationForm shrub("park");
		signer.signForm(shrub);
		executor.executeForm(shrub);
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "        ROBOTOMY REQUEST FORM          " << std::endl;
	std::cout << "========================================" << std::endl;

	std::cout << "\n--- Robotomy: SUCCESS ---" << std::endl;
	{
		Bureaucrat alice("Alice", 45);
		RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;
		alice.signForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot);
	}

	std::cout << "\n--- Robotomy: FAIL sign (grade too low) ---" << std::endl;
	{
		Bureaucrat lowGrade("LowGrade", 73);
		RobotomyRequestForm robot("Target");
		std::cout << lowGrade << std::endl;
		lowGrade.signForm(robot);
	}

	std::cout << "\n--- Robotomy: FAIL execute (not signed) ---" << std::endl;
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot("Unsign");
		boss.executeForm(robot);
	}

	std::cout << "\n--- Robotomy: FAIL execute (grade too low) ---" << std::endl;
	{
		Bureaucrat signer("Signer", 72);
		Bureaucrat executor("Executor", 46);
		RobotomyRequestForm robot("Victim");
		signer.signForm(robot);
		executor.executeForm(robot);
	}

	std::cout << "\n========================================" << std::endl;
	std::cout << "      PRESIDENTIAL PARDON FORM         " << std::endl;
	std::cout << "========================================" << std::endl;

	std::cout << "\n--- Pardon: SUCCESS ---" << std::endl;
	{
		Bureaucrat president("President", 5);
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}

	std::cout << "\n--- Pardon: FAIL sign (grade too low) ---" << std::endl;
	{
		Bureaucrat manager("Manager", 26);
		PresidentialPardonForm pardon("Criminal");
		std::cout << manager << std::endl;
		manager.signForm(pardon);
	}

	std::cout << "\n--- Pardon: FAIL execute (not signed) ---" << std::endl;
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Prisoner");
		boss.executeForm(pardon);
	}

	std::cout << "\n--- Pardon: FAIL execute (grade too low) ---" << std::endl;
	{
		Bureaucrat signer("Signer", 25);
		Bureaucrat executor("Executor", 6);
		PresidentialPardonForm pardon("Convict");
		signer.signForm(pardon);
		executor.executeForm(pardon);
	}
}

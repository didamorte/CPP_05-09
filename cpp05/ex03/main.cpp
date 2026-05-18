#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

	std::cout << "\n========================================" << std::endl;
	std::cout << "              INTERN TESTS             " << std::endl;
	std::cout << "========================================" << std::endl;

	std::cout << "\n--- Intern: Create Robotomy Request ---" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	}

	std::cout << "\n--- Intern: Create all form types ---" << std::endl;
	{
		Intern intern;
		AForm* forms[3];

		forms[0] = intern.makeForm("shrubbery creation", "Garden");
		forms[1] = intern.makeForm("robotomy request", "Marvin");
		forms[2] = intern.makeForm("presidential pardon", "Ford Prefect");

		for (int i = 0; i < 3; i++)
		{
			if (forms[i])
			{
				std::cout << *forms[i] << std::endl;
				delete forms[i];
			}
		}
	}

	std::cout << "\n--- Intern: Invalid form name ---" << std::endl;
	{
		Intern intern;
		AForm* form = intern.makeForm("invalid form", "Target");
		if (form == NULL)
			std::cout << "Form pointer is NULL as expected" << std::endl;
	}

	std::cout << "\n--- Intern: Full workflow (create, sign, execute) ---" << std::endl;
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm* pardon = intern.makeForm("presidential pardon", "Zaphod");

		if (pardon)
		{
			boss.signForm(*pardon);
			boss.executeForm(*pardon);
			delete pardon;
		}
	}
}

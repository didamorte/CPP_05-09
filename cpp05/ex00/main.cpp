#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- Default constructor ---" << std::endl;
	Bureaucrat def;
	std::cout << def << std::endl;

	std::cout << "\n--- Named constructor ---" << std::endl;
	Bureaucrat alice("Maria", 75);
	std::cout << alice << std::endl;

	std::cout << "\n--- Copy constructor ---" << std::endl;
	Bureaucrat bob(alice);
	std::cout << bob << std::endl;

	std::cout << "\n--- Assignment operator ---" << std::endl;
	Bureaucrat charlie("Antonio", 100);
	charlie = alice;
	std::cout << charlie << std::endl;

	std::cout << "\n--- Increment/Decrement ---" << std::endl;
	Bureaucrat mid("Mid", 5);
	std::cout << "Before: " << mid << std::endl;
	mid.incrementGrade();
	std::cout << "After increment: " << mid << std::endl;
	mid.decrementGrade();
	std::cout << "After decrement: " << mid << std::endl;

	std::cout << "\n--- GradeTooHighException ---" << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		top.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- GradeTooLowException ---" << std::endl;
	try
	{
		Bureaucrat bot("Bot", 150);
		bot.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Invalid grade at construction ---" << std::endl;
	try
	{
		Bureaucrat bad("Bad", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bad("Bad", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Destructors ---" << std::endl;
}

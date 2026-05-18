#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "--- Form creation ---" << std::endl;
	Form a("Tax Form", 50, 25);
	std::cout << a << std::endl;

	std::cout << "\n--- Form too high grade ---" << std::endl;
	try
	{
		Form bad("Bad", 0, 25);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Form too low grade ---" << std::endl;
	try
	{
		Form bad("Bad", 151, 25);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- signForm success ---" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 40);
		Form contract("Contract", 50, 100);
		std::cout << bob << std::endl;
		std::cout << contract << std::endl;
		bob.signForm(contract);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- signForm failure ---" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 140);
		Form topSecret("Top Secret", 1, 1);
		std::cout << intern << std::endl;
		std::cout << topSecret << std::endl;
		intern.signForm(topSecret);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Copy and assignment ---" << std::endl;
	Form original("Original", 30, 60);
	Form copy(original);
	std::cout << "Original: " << original << std::endl;
	std::cout << "Copy:     " << copy << std::endl;

	std::cout << "\n--- Destructors ---" << std::endl;
}

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(0), gradeToSign(50), gradeToExecute(5)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(0), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form " << name << " constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : 
	name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "Form " << name << " copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "Form " << name << " destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return name;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (getGradeToSign() >= b.getGrade())
		isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat& b) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (b.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	action();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form isn't signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "Form: " << f.getName() << ", grade to sign " << f.getGradeToSign() << ", grade to execute " << f.getGradeToExecute();
	return (os);
}
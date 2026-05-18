#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(0), gradeToSign(50), gradeToExecute(5)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(0), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form " << name << " constructor called" << std::endl;
}

Form::Form(const Form& other) : 
	name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "Form " << name << " copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << name << " destructor called" << std::endl;
}

std::string Form::getName() const
{
	return name;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void Form::beSigned(const Bureaucrat& b)
{
	if (getGradeToSign() >= b.getGrade())
		isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form: " << f.getName() << ", grade to sign " << f.getGradeToSign() << ", grade to execute " << f.getGradeToExecute();
	return (os);
}
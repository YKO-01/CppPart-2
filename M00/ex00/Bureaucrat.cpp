#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("none"), grade(1)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	*this = copy;
}

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::operator=(const Bureaucrat& copy)
{
	this->grade = copy.grade;
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int		Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::increment()
{


#ifndef BUREAUCRAT
#define BUREAUCRAT


#include <iosteam>

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat&	operator = (const Bureaucrat& copy); 
		std::string	getName() const;
		int		getGrade() const;
		void		increment();
		void		decrement();
};




#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:24:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/12/24 12:22:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

# define WHITE_B	"\033[1;37m"
# define YELLOW	"\033[33m"
# define GREEN	"\033[32m"
# define RESET	"\033[0m"

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(const std::string& name, int gradeSign, int gradeExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm(void);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;

		void 			beSigned(const Bureaucrat& bureaucrat);
		void			execute(Bureaucrat const & execute) const;
		virtual void	executeAction(void) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string 	_name;
		bool 				_isSigned;
		const int		 	_gradeSign;
		const int 			_gradeExec;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif

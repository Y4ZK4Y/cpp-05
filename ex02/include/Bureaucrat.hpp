/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 10:26:40 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 13:22:59 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <ostream>
#include "AForm.hpp"

class Bureaucrat {
private:
    const std::string   name_;
    int                 grade_;

public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& rhs);
    ~Bureaucrat();

    /* Exceptions */
    class GradeTooHighException: public std::exception {
        public:            
            const char* what() const noexcept override;
    };
    class GradeTooLowException: public std::exception {
        public:
            const char* what() const noexcept override;
    };
    
    const std::string&  getName()   const;
    int                 getGrade()  const;

    void                incrementGrade();
    void                decrementGrade();

    void                signForm(AForm& form);
    void                executeForm(AForm const& form) const;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:26:40 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/14 21:26:18 by yasamankari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <ostream>
#include <exception>

class AForm;

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
    void                executeForm(const AForm& form) const;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:57:01 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/14 21:16:12 by yasamankari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
                        AForm("PresidentialPardonForm", 25, 5, target) { 
    std::cout << "PresidentialPardonForm constructor called.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other) {
    std::cout << "PresidentialPardonForm copy constructor called.\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    std::cout << "PresidentialPardonForm ass operator called.\n";
    AForm::operator=(rhs);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called.\n";
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw NotSignedException();
    else if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}

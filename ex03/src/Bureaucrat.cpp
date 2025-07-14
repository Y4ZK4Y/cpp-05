/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 10:43:34 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 16:40:37 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name), grade_(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat " << name_ << " constructor called.\n"; 
} 

Bureaucrat::Bureaucrat(const Bureaucrat& other): name_(other.name_), grade_(other.grade_) {
    std::cout << "Bureaucrat copy constructor called.\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (this != &rhs)
        grade_ = rhs.grade_;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "RIP Bureaucrat: " << name_ << ".\n";
}

const std::string& Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

void Bureaucrat::incrementGrade() {
    if (grade_ == 1)
        throw GradeTooHighException();
    std::cout << "Bureaucrat " << getName() << " went one point up!";
    --grade_;
}

void Bureaucrat::decrementGrade() {
    if (grade_ == 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat " << getName() << " went one point down!";
   ++grade_;
}

// exceptions
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Grade too high!";
}


const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return os;
}

void Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << name_ << " signed " << f.getName() << '\n';
    }
    catch (const std::exception& e) {
        std::cout << name_ << " couldn’t sign " << f.getName()
        << " because " << e.what() << '\n';
    }
}

void Bureaucrat::executeForm(AForm const& form) const {
    try {
        form.execute(*this);
        std::cout << name_ << " executed " << form.getName();
    }
    catch (const std::exception& e) {
        std::cout << name_ << " couldn't execute "
        << form.getName() << " because " << e.what();
    } 
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 10:43:34 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 13:12:48 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name), grade_(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat " << name_ << " constructor called.\n"; 
} 

Bureaucrat::Bureaucrat(const Bureaucrat& other): name_(other.name_), grade_(other.grade_) {
    std::cout << "Copy constructor called.\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (this != &rhs)
        grade_ = rhs.grade_;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "RIP Bureaucrat: " << name_ << ".\n";
}

/* ------------------------- Getters -------------------------*/
const std::string& Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

/* ------------------------- Exceptions -------------------------*/
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Grade too low!";
}

/* ------------------------- Grade Modifiers -------------------------*/
void Bureaucrat::incrementGrade() {
    if (grade_ == 1)
        throw GradeTooHighException();
    std::cout << "Bureaucrat " << getName() << " went one point up!\n";
    --grade_;
}

void Bureaucrat::decrementGrade() {
    if (grade_ == 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat " << getName() << " went one point down!\n";
   ++grade_;
}


void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << name_ << " signed " << form.getName() << '\n';
    }
    catch (const std::exception& e) {
        std::cout << name_ << " couldn’t sign " << form.getName()
                  << " because " << e.what() << '\n';
    }
}

/* ------------------------- Insertion Overload -------------------------*/

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return os;
}


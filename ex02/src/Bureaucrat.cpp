/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:43:34 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/12 12:54:20 by yasamankari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name), grade_(grade) {
    if (grade < 1)
        throw GradeTooLowException();
    if (grade > 150)
        throw GradeTooHighException();
    std::cout << "Bureaucrat " << name_ << " enters!" << std::endl; 
} 

Bureaucrat::Bureaucrat(const Bureaucrat& other): name_(other.name_), grade_(other.grade_) {
    std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        grade_ = other.grade_; // name_ const we we skip
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "RIP Bureaucrat: " << name_ << "." << std::endl;
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
    std::cout << "Bureaucrat " << getName() << " went one point up!" << std::endl;
    grade_--;
}

void Bureaucrat::decrementGrade() {
    if (grade_ == 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat " << getName() << " went one point down!" << std::endl;
   ++grade_; // invari ya oonvari?
}

// exceptions
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Grade too high!";
}


const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
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
        std::cout << name_ << " executed " << form.getName()
        << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << name_ << " couldn't execute "
        << form.getName() << " because " << e.what()
        << std::endl;
    } 
}
/*
It must attempt to execute the form. If successful, print something like:
<bureaucrat> executed <form>
If not, print an explicit error message
*/

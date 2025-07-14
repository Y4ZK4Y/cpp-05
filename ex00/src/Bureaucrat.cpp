/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 10:43:34 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 12:41:42 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        grade_ = other.grade_; // name_ const so we skip
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


/* ------------------------- Exceptions ------------------------- */
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Grade too high!";
}


const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Grade too low!";
}

/* ------------------------- Grade Modifiers ------------------------- */
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

/* ------------------------- << Operator Overload ------------------------- */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return os;
}

/*
Idiomatic C++	Taking large objects by const& is the standard pattern unless you need to modify or you rely on move semantics (
*/

/*

grade_ ++ vs. grade_ --
We use --_grade (prefix decrement) instead of _grade-- (postfix) because we're not interested in the value 
returned by the operation—only the side effect of decreasing the grade. Prefix is preferred in such cases because it 
directly decrements the variable without creating a temporary copy of the old value (as postfix does), making it slightly 
more efficient and semantically clearer. Although the difference is negligible for simple types like int, using prefix is 
considered good practice when the result isn’t needed, as it more explicitly communicates the intent: "just decrement.
*/
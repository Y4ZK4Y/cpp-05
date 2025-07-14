/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:20:21 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/12 12:30:15 by yasamankari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec, const std::string& target):
    name_(name), signed_(false), gradeToSign_(gradeToSign), gradeToExec_(gradeToExec), target_(target) {
    if (gradeToSign_ < 1 || gradeToExec_ < 1)
        throw GradeTooHighException();
    else if (gradeToSign_ > 150 || gradeToExec_ > 150)
        throw GradeTooLowException();
    std::cout << "An unsigned form created.\n";
}

AForm::AForm(const AForm& other): name_(other.name_), signed_(other.signed_),
    gradeToSign_(other.gradeToSign_), gradeToExec_(other.gradeToExec_), target_(other.target_) {
    std::cout << "Copy constructor called.\n";
}

AForm& AForm::operator=(const AForm& rhs) {
    if (this!= &rhs)
        signed_ = rhs.signed_;
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destroyed.\n";
}

/* Getters */
const std::string& AForm::getName() const {
    return (name_);
}

const std::string& AForm::getTarget() const {
    return target_;
}

bool AForm::isSigned() const {
    return (signed_);
}

int AForm::getGradeToSign() const {
    return (gradeToSign_);
}

int AForm::getGradeToExec() const {
    return (gradeToExec_);
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    signed_ = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (!signed_)
        throw NotSignedException();
    if (executor.getGrade() > gradeToExec_)
        throw GradeTooLowException();
    executeAction();  // Call to derived class
}

const char* AForm::GradeTooHighException::what() const noexcept {
    return "grade too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept {
    return "grade too low!";
}

const char* AForm::NotSignedException::what() const noexcept {
    return "form not signed yet!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName()
    << " [sign grade  " << f.getGradeToSign()
    << " , exec grade " << f.getGradeToExec()
    << ", " << (f.isSigned() ? "signed" : "not signed")
    << ']';
    return (os);
}

/*
check that the form is signed and that the grade of the bureaucrat at-
tempting to execute the form is high enough. Otherwise, throw an appropriate exception.
*/

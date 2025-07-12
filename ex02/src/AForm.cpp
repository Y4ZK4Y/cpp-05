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
#include <string>
#include <iostream>

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec): // are we missing ocnst ?
    name_(name), signed_(false), gradeToSign_(gradeToSign), gradeToExec_(gradeToExec) {
    if (gradeToSign_ < 1 || gradeToExec_ < 1)
        throw GradeTooHighException();
    else if (gradeToSign_ > 150 || gradeToExec_ > 150)
        throw GradeTooLowException();
    std::cout << "An unsigned form created." << std::endl;
}

AForm::AForm(const AForm& other): name_(other.name_), signed_(other.signed_),
    gradeToSign_(other.gradeToSign_), gradeToExec_(other.gradeToExec_) {
    std::cout << "Copy constructor called." << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this!= &other)
        signed_ = other.signed_;
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destroyed." << std::endl;
}

/* Getters */
const std::string& AForm::getName() const {
    return (name_);
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

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName()
    << " [sign grade  " << f.getGradeToSign()
    << " , exec grade " << f.getGradeToExec()
    << ", " << (f.isSigned() ? "signed" : "not signed")
    << ']' << std::endl;
    return (os);
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

/*
check that the form is signed and that the grade of the bureaucrat at-
tempting to execute the form is high enough. Otherwise, throw an appropriate exception.
*/

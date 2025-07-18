/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 20:20:21 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 13:03:27 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Form::Form(const std::string& name, int gradeToSign, int gradeToExec):
    name_(name), signed_(false), gradeToSign_(gradeToSign), gradeToExec_(gradeToExec) {
    if (gradeToSign_ < 1 || gradeToExec_ < 1)
        throw GradeTooHighException();
    else if (gradeToSign_ > 150 || gradeToExec_ > 150)
        throw GradeTooLowException();
    std::cout << "An unsigned form created.\n";
}

Form::Form(const Form& other): name_(other.name_), signed_(other.signed_),
    gradeToSign_(other.gradeToSign_), gradeToExec_(other.gradeToExec_) {
    std::cout << "Copy constructor called.\n";
}

Form& Form::operator=(const Form& rhs) {
    if (this!= &rhs)
        signed_ = rhs.signed_;
    return *this;
}

Form::~Form() {
    std::cout << "Form destroyed.\n";
}

/* ------------------------- Getters -------------------------*/
const std::string& Form::getName() const {
    return (name_);
}

bool Form::isSigned() const {
    return (signed_);
}

int Form::getGradeToSign() const {
    return (gradeToSign_);
}

int Form::getGradeToExec() const {
    return (gradeToExec_);
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    signed_ = true;
}

/* ------------------------- Exceptions ------------------------- */
const char* Form::GradeTooHighException::what() const noexcept {
    return "grade too high!";
}

const char* Form::GradeTooLowException::what() const noexcept {
    return "grade too low!";
}

/* ------------------------- Insertion Overload ------------------------- */
std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName()
    << " [sign grade  " << f.getGradeToSign()
    << " , exec grade " << f.getGradeToExec()
    << ", " << (f.isSigned() ? "signed" : "not signed") << ']';
    return (os);
}

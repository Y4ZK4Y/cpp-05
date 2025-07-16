/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:31:39 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/14 21:36:03 by yasamankari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
    AForm("ShrubberyCreationForm", 145, 137, target) {
    std::cout << "ShrubberyCreationForm constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm& other):
AForm(other) {
    std::cout << "ShrubberyCreationForm copy constructor called.\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    std::cout << "ShrubberyCreationForm copy ass operator called.\n";
    AForm::operator=(rhs);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called.\n";
    // close if open
}

static const char* asciiTree = "TREE";

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw NotSignedException();
    else if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();

    std::ofstream f((getTarget() + "_shrubbery").c_str());
    if (!f) {
        std::cerr << "cant create file\n";
        return; // silent return? return sth else ? exceptipn?
    }
    for (int i = 0; i < 3; i++)
        f << asciiTree;
        
}

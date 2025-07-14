/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 12:31:39 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 11:44:10 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
    AForm("ShrubberyCreationForm", 145, 137, target) {
    std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm& other):
AForm(other) { // base class copy constructor does the job
    std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm copy ass operator called." << std::endl;
    AForm::operator=(other); // copied signed only
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called." << std::endl;
    // close if open
}

static const char* asciiTree = "TREE";

void ShrubberyCreationForm::executeAction(const Bureaucrat& executor) const {
    // if nor signed throw excpetion
    std::ofstream f((getTarget() + "_shrubbery").c_str());
    if (!f) {
        std::cerr << "cant create file\n";
        return; // silent return? return sth else ? exceptipn?
    }
    for (int i = 0; i < 3; i++)
        f << asciiTree;
        // flush() ?
        
}

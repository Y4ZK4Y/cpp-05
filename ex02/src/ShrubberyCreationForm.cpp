/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 12:31:39 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 17:08:43 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
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

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm copy ass operator called.\n";
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called.\n";
    // close if open
}

static const char* asciiTree =
R"( 
       O~~~ O~~~~~~O~~~~~~~    O~~~~~~~~O~~~~~~~~
            O~~    O~~    O~~  O~~      O~~      
            O~~    O~~    O~~  O~~      O~~      
            O~~    O~ O~~      O~~~~~~  O~~~~~~  
            O~~    O~~  O~~    O~~      O~~      
            O~~    O~~    O~~  O~~      O~~      
            O~~    O~~      O~~O~~~~~~~~O~~~~~~~~
)";

void ShrubberyCreationForm::executeAction() const {
    // if nor signed throw excpetion
    const std::string filename = getTarget() + "_shrubbery";
    std::ofstream f(filename.c_str());
    if (!f) {
        std::cerr << "cant create file.\n";
        return; // silent return? return sth else ? exceptipn?
    }
    for (int i = 0; i < 3; i++)
        f << asciiTree << "\n";
    f.close();
}

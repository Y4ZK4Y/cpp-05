/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 12:56:58 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 17:19:35 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib> // for rand()

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45, target) {
    std::cout << "RobotomyRequestForm constructor called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other) {
    std::cout << "RobotomyRequestForm copy constructor called.\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    std::cout << "RobotomyRequestForm ass operator called.\n";
    AForm::operator=(rhs);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called.\n";
}

void RobotomyRequestForm::executeAction() const {
    // check for if signed
    std::cout << "DREEEEEEEE\n";

    if (std::rand() %2 == 0)
        std::cout << getTarget() << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed for " << getTarget() << ".\n";

}

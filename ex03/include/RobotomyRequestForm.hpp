/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 12:39:09 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 16:41:07 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {

public:
    explicit RobotomyRequestForm(std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
    ~RobotomyRequestForm();

    void executeAction() const override;
};

/*
Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.
take only one parameter in their constructor: the target of the form
*/

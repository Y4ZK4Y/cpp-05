/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 12:38:50 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 17:15:45 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm: public AForm {

public:
    explicit PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
    ~PresidentialPardonForm();

    void executeAction()    const override;
};


/*
Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox
take only one parameter in their constructor: the target of the form
*/
/*
if we do PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs) = delete; 
we're telling the complier we odnt want htis class to be assignable
For example, if it contains const members or if copying doesn't make sense (like in singleton or unique resource wrapper


PresidentialPardonForm a("target1");
PresidentialPardonForm b("target2");

a = b; //  Compile error if operator= is deleted


*/

/*

explicit keyword:

You want to prevent accidental implicit conversions (from const char* or std::string)


*/
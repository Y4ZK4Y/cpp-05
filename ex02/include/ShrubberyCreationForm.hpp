/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/12 12:32:06 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 17:05:43 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm: public AForm {

public:
    explicit ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
    ~ShrubberyCreationForm();

    void executeAction() const override;
};


/*
explicit keyword ?
watch out for circular inlcudes (?)
*/

/*
required grades: sign 145 exec 137
creates a file <target>_shrubbery in . writes ascii trees
take only one parameter in their constructor: the target of the form

*/

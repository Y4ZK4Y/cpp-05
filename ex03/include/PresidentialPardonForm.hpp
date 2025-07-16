/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:38:50 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/14 21:07:00 by yasamankari      ###   ########.fr       */
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

    void execute(const Bureaucrat& executor) const override;
};


/*
Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox
take only one parameter in their constructor: the target of the form
*/

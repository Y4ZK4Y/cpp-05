/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 10:05:04 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/07/14 16:45:45 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
//#include <exception>
#include "AForm.hpp"

class Intern {

public:
    Intern();
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    ~Intern();
    
    AForm* makeForm(const std::string& formName,
                    const std::string& target) const;

    /* Exception */
    class UnknownFormException: public std::exception {
    public:
        const char* what() const noexcept override;
    };
};

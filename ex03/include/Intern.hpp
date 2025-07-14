/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 10:05:04 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/07/14 11:35:33 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include "AForm.hpp"

class Intern {

public:
    Intern();
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    ~Intern();
    
    /* Exception */
    class UnknownFormException: public std::exception {
    public:
        const char* what() const noexcept override;
    };
    
    AForm* makeForm(const std::string& formName,
                    const std::string& target) const;
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:24:03 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/11 20:20:10 by yasamankari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat; // forward declaration

class Form {

private:
    const std::string   name_;
    bool                signed_;
    const int           gradeToSign_;
    const int           gradeToExec_;

public:
    Form(const std::string& name, int gradeToSign, int gradeToExec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    /* Exception types */
    class GradeTooHighException: public std::exception {
    public:
        const char* what() const noexcept override;
    };
    
    class GradeTooLowException: public std::exception {
    public:
        const char* what() const noexcept override;    
    };

    /* Getters */
    const std::string&  getName()           const;
    int                 getGradeToSign()    const;
    int                 getGradeToExec()    const;
    bool                isSigned()          const;

    void                beSigned(const Bureaucrat& b); // why const?

};
std::ostream& operator<<(std::ostream& os, const Form& f);




/*
choice of private vs protected

*/

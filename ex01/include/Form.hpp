/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 15:24:03 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 12:57:30 by ykarimi       ########   odam.nl         */
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

    /* Exception types */
    class GradeTooHighException: public std::exception {
    public:
        const char* what() const noexcept override;
    };
    class GradeTooLowException: public std::exception {
    public:
        const char* what() const noexcept override;    
    };

    /* Canonical form */
    Form(const std::string& name, int gradeToSign, int gradeToExec);
    Form(const Form& other);
    Form& operator=(const Form& rhs);
    ~Form();

    /* Getters */
    const std::string&  getName()           const;
    int                 getGradeToSign()    const;
    int                 getGradeToExec()    const;
    bool                isSigned()          const;

    void                beSigned(const Bureaucrat& b);
};
std::ostream& operator<<(std::ostream& os, const Form& f);



/*
choice of private vs protected

private:    
only Form class can access the members

protected:
    derived calsses could dierctly access the members

if protected, then derived classes might be able to changer the grad erange for example

if changes needed, we can do  that in one place(Form class)
*/

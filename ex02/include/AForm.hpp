/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 15:24:03 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 17:13:01 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ostream>
//#include <exception>

class Bureaucrat;

class AForm {

private:
    const std::string   name_;
    bool                signed_;
    const int           gradeToSign_;
    const int           gradeToExec_;
    const std::string   target_;

public:
    AForm(const std::string& name, int gradeToSign,
        int gradeToExec, const std::string& target); 
    AForm(const AForm& other);
    AForm& operator=(const AForm& rhs);
    virtual ~AForm();

    /* Getters */
    const std::string&  getName()           const;
    int                 getGradeToSign()    const;
    int                 getGradeToExec()    const;
    const std::string&  getTarget()         const;
    bool                isSigned()          const;

    void                beSigned(const Bureaucrat& b);
    void                execute(const Bureaucrat& executor) const; // a template

    virtual void        executeAction() const = 0; // implemented in derived classes - hook

    /* Exception */
    class GradeTooHighException: public std::exception {
    public:
        const char* what() const noexcept override;
    };
    class GradeTooLowException: public std::exception {
    public:
        const char* what() const noexcept override;    
    };
    class NotSignedException: public std::exception {
        public:
            const char* what() const noexcept override;
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);


/*
circular dependancy
how it happens ? example

*/
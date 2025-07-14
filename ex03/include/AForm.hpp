/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 15:24:03 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 16:30:21 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat;

class AForm {

private:
    const std::string   name_;
    bool                signed_;
    const int           gradeToSign_;
    const int           gradeToExec_;
    const std::string   target_;

public:
    AForm(const std::string& name, int gradeToSign, int gradeToExec, std::string& target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    /* Exception types */
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

    /* Getters */
    const std::string&  getName()           const;
    int                 getGradeToSign()    const;
    int                 getGradeToExec()    const;
    const std::string&  getTarget()         const;
    bool                isSigned()          const;

    void                beSigned(const Bureaucrat& b);
    void                execute(Bureaucrat const& executor) const;

    /* Pure virtual hook */
    virtual void        executeAction(const Bureaucrat& executor) const = 0;

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:26:40 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/11 15:16:50 by yasamankari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <ostream>

class Bureaucrat {
private:
    const std::string name_;
   int grade_; // unsigned int?

public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    /* Exception types */
    class GradeTooHighException: public std::exception {
        public:
            // Exception specification – promises this function itself will never throw. If it did throw while another exception is already propagating, the program would call std::terminate(). Marking it noexcept (C++11+) makes that guarantee explicit and lets the compiler optimize.
            //Compile-time check – tells the compiler: “I intend to override a virtual function from a base class.” If you mistype the signature (e.g., char* what()), the compiler errors out instead of silently creating a new unrelated method.
            
            const char* what() const noexcept override; // or  const char* what() const throw() ?
    };
    class GradeTooLowException: public std::exception {
        public:
            const char* what() const noexcept override;
    };
    
    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade(); 

};

// insertion operator overload - outputs the sam stream it has received
// by placing this in the namespace scope(a free function), lets the stream come first
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


/*
noexcept vs throw()
throw() pre c++11
const char* what() const throw();

modern cpp:
const char* what() const noexcept;


*/


/*
Signature must match base (const char* what() const) so polymorphic catching works.
noexcept is essential: throwing from what() during stack-unwinding would crash the program.
override protects you from typos and keeps maintenance safe.
Returning a static literal is enough when your exception type has no runtime data. For richer info, store a std::string inside and return c_str().
*/

/*
cv qualifier
const and/or volatile
So when we say a function has a cv-qualifier, we mean it's marked as const, volatile, or both
*/


/*
Why the exact what() signature matters
1. Virtual-function mechanics in one sentence

When you call a virtual function through a base-class reference or pointer, C++ looks up the actual function in the object’s v-table at run time.
That lookup only works if the derived class overrides a function with the identical name and type signature that the base class declares.

namespace std {
class exception {
public:
    virtual const char* what() const noexcept;
};
}

Use override — the compiler will force the signature to match and save you from silent bugs.



*/

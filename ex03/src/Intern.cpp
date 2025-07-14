/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 10:07:42 by ykarimi       #+#    #+#                 */
/*   Updated: 2025/07/14 16:48:41 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

/*
type alias for form-creation functions used inside the lookup table
instead of repeating : AForm* (*)(const std::string&)
we just use FormCreator as a name for any pointer to a function that
complies with htis: AForm* (*)(const std::string&) - returns a AForm pointer and takes a const std::string&
*/


/* ----------------------- Intern class ----------------------- */
Intern::Intern() {
    std::cout << "Intern construcor.\n";   
}

Intern::Intern(const Intern&) {
    std::cout << "Intern copy construcor.\n";
}

Intern& Intern::operator=(const Intern&) {
    std::cout << "Intern ass operator.\n";
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor.\n";
}

/* ----------------------- Exception ----------------------- */
const char* Intern::UnknownFormException::what() const noexcept {
    return "Intern: requested form is unknown.";
}


/* ----------------------- Helper functions ----------------------- */
typedef AForm* (*FormCreator)(const std::string&);

static AForm* newShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* newRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* newPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& formName,
                        const std::string& target) const {
    struct Pair {
        const char* name;
        FormCreator creator;
    };

    static const Pair table[] = {
        {"shrubbery creation",newShrubbery},
        {"robotomy creation", newRobotomy},
        {"presidential pardon", newPresidential}
    };

    const size_t tableSize = sizeof(table)/sizeof(table[0]);
    for (size_t i = 0; i < tableSize; i++) {
        if (formName == table[i].name) {
            std::cout << "Intern creates " << formName << '\n';
            return table[i].creator(target);
        }
    }
    std::cerr << "Intern finds " << formName << " an unknown form type.\n";
    throw UnknownFormException();
}

/* 
make everyhting static

*/
/*
this function needs to:
formName is a valid form type
create a form targeted at <target>
return a pointer to the form


*/

/*
 Type alias for function pointer
*/

/*
makeForm function:
makeForm(name, target):
for each (formName,, creator func) in lookup table:
    if name == formName
        print intern creates <name>
        return creator func
print <name> is unknown
return NULL

*/


/*
lookup tables in cpp
a structure (usually an array or std::map) that associates keys with actions
need to define a new "type alias"
    gives a nickname to an existing type
    example:
    typedef unsigned int uint;
    so we can write:
    uint a = 5;  // same as: unsigned int a = 5;

*/
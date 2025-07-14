/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 10:25:55 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 11:39:31 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"                // from previous exercises
#include <iostream>
#include <memory>                        // for smart‑ptr wrapper (optional)

static void separator(const std::string& title)
{
    std::cout << "\n======= " << title << " =======\n";
}

int main()
{
    separator("Setup: three bureaucrats");
    Bureaucrat low   ("LowBob" , 150);
    Bureaucrat mid   ("MidAnn" ,  70);
    Bureaucrat high  ("HighZed",   1);

    std::cout << low  << '\n' << mid << '\n' << high << '\n';

    separator("Intern fabricates forms");
    Intern  intern;

    const char* names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
        "coffee form"             // ← invalid on purpose
    };

    /* keep raw pointers; remember to delete later */
    AForm* forms[4] = { NULL, NULL, NULL, NULL };

    for (int i = 0; i < 4; ++i)
    {
        try {
            forms[i] = intern.makeForm(names[i], "Target_" + std::string(1, 'A'+i));
        }
        catch (const std::exception& e) {
            std::cerr << "makeForm failed: " << e.what() << '\n';
        }
    }

    separator("Signing attempts (mid, then high)");
    for (int i = 0; i < 4; ++i)
        if (forms[i]) mid.signForm(*forms[i]);          // some will fail

    for (int i = 0; i < 4; ++i)
        if (forms[i]) high.signForm(*forms[i]);         // high should succeed

    separator("Execution attempts (low, mid, high)");
    for (int i = 0; i < 4; ++i)
        if (forms[i]) low.executeForm(*forms[i]);       // expect fails

    for (int i = 0; i < 4; ++i)
        if (forms[i]) mid.executeForm(*forms[i]);       // some succeed

    for (int i = 0; i < 4; ++i)
        if (forms[i]) high.executeForm(*forms[i]);      // high succeeds

    separator("Cleanup");
    for (int i = 0; i < 4; ++i)
        delete forms[i];
}


/*
factory pattern:
Definition: A design pattern that encapsulates object creation logic inside a method.
In this case, Intern::makeForm() is a factory method that returns different AForm*s.

The caller doesn't care how the object is created—just that it gets one.


INTERN builds different concrete forms from a single call


polymorphic return(base-class pointer):
What it means: You return a pointer to the base class (AForm*),
but what you actually give back is a derived type


lookup table:



minimalist class - intern has no data members; only behavior
Behavior-only utility objects 
You don't need to over-design - write just enough

*/

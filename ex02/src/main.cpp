/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 10:25:55 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 17:17:12 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static void banner(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    /* ------------------------------------------------------------------ *
     *  1.  Happy‑path for each concrete form                             *
     * ------------------------------------------------------------------ */
    banner("HAPPY‑PATH EXECUTION");

    Bureaucrat boss("Boss", 1);                    // grade 1 → can do everything

    ShrubberyCreationForm  shrub("backyard");
    RobotomyRequestForm    robo("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    boss.signForm(shrub);
    boss.signForm(robo);
    boss.signForm(pardon);

    boss.executeForm(shrub);
    boss.executeForm(robo);
    boss.executeForm(pardon);

    /* ------------------------------------------------------------------ *
     *  2.  Attempt to execute unsigned form                              *
     * ------------------------------------------------------------------ */
    banner("EXECUTE UNSIGNED FORM  → should fail");

    Bureaucrat alice("Alice", 10);
    ShrubberyCreationForm unsignedShrub("park");

    alice.executeForm(unsignedShrub);   // not signed yet → throws

    /* ------------------------------------------------------------------ *
     *  3.  Sign but execute with low‑grade bureaucrat                    *
     * ------------------------------------------------------------------ */
    banner("EXECUTE WITH GRADE TOO LOW → should fail");

    Bureaucrat lowGuy("LowGuy", 150);          // worst grade
    PresidentialPardonForm highForm("Arthur");

    lowGuy.signForm(highForm);                 // cannot sign (grade too low)
    boss.signForm(highForm);                   // signed by boss
    lowGuy.executeForm(highForm);              // execute fails (grade too low)

    /* ------------------------------------------------------------------ *
     *  4.  Boundary tests for grades                                     *
     * ------------------------------------------------------------------ */
    banner("BOUNDARY CHECKS");

    try {
        Bureaucrat badHigh("BadHigh", 0);      // too high → exception
    } catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << '\n';
    }

    try {
        Bureaucrat badLow("BadLow", 200);      // too low → exception
    } catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << '\n';
    }

    banner("All tests finished");
    return 0;
}

/*
Learning Objectives:
run-time polymorphism(dynamic dispatch)
correct use of const
*/

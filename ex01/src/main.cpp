/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 10:25:55 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 13:16:56 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void banner(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    /* ------------------------------------------------------------------ */
    banner("1. Valid Bureaucrat & Form creation, operator<<");
    try
    {
        Bureaucrat alice("Alice", 42);
        Form       shrub("ShrubForm", 50, 25);

        std::cout << alice << std::endl;
        std::cout << shrub << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    /* ------------------------------------------------------------------ */
    banner("2. Form constructor range checks");
    try { Form badHigh("BadHigh", 0, 30); }
    catch (const std::exception& e) { std::cerr << "Caught: " << e.what() << std::endl; }

    try { Form badLow("BadLow", 151, 30); }
    catch (const std::exception& e) { std::cerr << "Caught: " << e.what() << std::endl; }

    /* ------------------------------------------------------------------ */
    banner("3. Signing attempts: failure then success");
    Bureaucrat mid("Mid", 100);             // too low to sign sign‑grade 50
    Bureaucrat high("High", 1);             // can sign anything
    Form shrub("ShrubForm", 50, 25);

    mid.signForm(shrub);    // should fail
    high.signForm(shrub);   // should succeed
    std::cout << shrub << std::endl;

    /* ------------------------------------------------------------------ */
    banner("4. Increment / decrement boundaries");
    try
    {
        Bureaucrat b("Bob", 2);
        b.incrementGrade();               // grade becomes 1
        std::cout << b << std::endl;
        b.incrementGrade();               // should throw (too high)
    }
    catch (const std::exception& e) { std::cerr << "Caught: " << e.what() << std::endl; }

    try
    {
        Bureaucrat c("Carl", 149);
        c.decrementGrade();               // grade becomes 150
        std::cout << c << std::endl;
        c.decrementGrade();               // should throw (too low)
    }
    catch (const std::exception& e) { std::cerr << "Caught: " << e.what() << std::endl; }

    banner("All tests finished");
    return 0;
}


/*
class-to-class collaboration
two calsses call each others apis (shit that's private)
const vs mutable
class forwar declartation
*/

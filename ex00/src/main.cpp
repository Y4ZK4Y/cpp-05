/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 10:25:55 by yasamankari   #+#    #+#                 */
/*   Updated: 2025/07/14 12:39:38 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

static void banner(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    /* ------------------------------------------------------------------ */
    banner("Valid construction & stream operator");
    try
    {
        Bureaucrat alice("Alice", 42);
        std::cout << alice << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    /* ------------------------------------------------------------------ */
    banner("Constructor range checks");
    try
    {
        Bureaucrat zero("Zero", 0);          // too high
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat over("Over", 151);        // too low
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    /* ------------------------------------------------------------------ */
    banner("Increment boundary (2 → 1 then fail)");
    try
    {
        Bureaucrat bob("Bob", 2);
        bob.incrementGrade();                // now 1
        std::cout << bob << std::endl;
        bob.incrementGrade();                // should throw
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    /* ------------------------------------------------------------------ */
    banner("Decrement boundary (149 → 150 then fail)");
    try
    {
        Bureaucrat carl("Carl", 149);
        carl.decrementGrade();               // now 150
        std::cout << carl << std::endl;
        carl.decrementGrade();               // should throw
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    /* ------------------------------------------------------------------ */
    banner("Copy constructor & assignment operator");
    try
    {
        Bureaucrat don("Don", 10);
        Bureaucrat copy(don);                // copy ctor
        Bureaucrat ed("Ed", 50);
        ed = don;                            // assignment
        std::cout << "Original: " << don
                  << " | Copy: " << copy
                  << " | Assigned: " << ed << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    banner("All tests finished");
    return 0;
}


/*
Exception classes
throwing and catching exceptions
std::exception
what classes can skip OCF? state holding classes cannot 
const-correctness ?
*/

/*
exception handling:
if no exception is thwwon inside try, the catch blocks are skipped.
if an exception is thrown, control jumps to the first compatible catch (matching type or base class),
executes it, then continues after the whole try/catch
std::Exception
exception is an object
exception vs. return ==>
    normal path stays clean, only abnormal path needs handling
*/

/*
some best practices:
Throw by value, catch by (const) reference.
Do not throw raw pointers or primitive types. Always objects derived from std::exception.
Mark a what() override noexcept.
Don’t use exceptions for regular control flow (e.g., loop exits).
Keep objects valid after an operation fails or roll them back; never leave half-formed state.
Know your environment: some embedded or game engines forbid exceptions for cost reasons.
*/

/*
what exactly happens when exception is thrown?
stack unwinding: All automatic variables (those on the stack) are destroyed properly by calling their destructors.

*/

/*
std::exception
what
    returns an explanatory string
*/

/* 
Throwing an exception
transfers control to a handler
throwing an exception initializes an object with dynamic storage duration

*/

/*
try-catch block
exceptions are thrown with a type

heirrchy of exception calls

*/

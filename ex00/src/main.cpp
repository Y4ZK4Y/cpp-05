/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:25:55 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/11 14:26:29 by yasamankari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat bob("Bob", 3);
        std::cout << bob << '\n';

        bob.incrementGrade();  // 2
        bob.incrementGrade();  // 1
        std::cout << bob << '\n';

        bob.incrementGrade();  // boom
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        Bureaucrat bad("Bad", 151);      // constructor throws
    }
    catch (const std::exception& e) {
        std::cerr << "Ctor error: " << e.what() << '\n';
    }
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

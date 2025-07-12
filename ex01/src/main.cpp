/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasamankarimi <yasamankarimi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:25:55 by yasamankari       #+#    #+#             */
/*   Updated: 2025/07/11 20:50:28 by yasamankari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void separator(const std::string& title) {
    std::cout << "\n====== " << title << " ======\n";
}

int main() {
    separator("Valid Form Signing");

    try {
        Bureaucrat alice("Alice", 42);
        Form formA("FormA", 50, 30); // Alice is strong enough to sign (42 ≤ 50)

        std::cout << alice << '\n';
        std::cout << formA << '\n';

        alice.signForm(formA);

        std::cout << formA << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }

    separator("Invalid Signing Attempt");

    try {
        Bureaucrat bob("Bob", 100);
        Form formB("FormB", 50, 20); // Bob is too weak to sign (100 > 50)

        std::cout << bob << '\n';
        std::cout << formB << '\n';

        bob.signForm(formB); // should fail gracefully

        std::cout << formB << '\n'; // still not signed
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }

    separator("Invalid Form Creation");

    try {
        Form badForm("TooHigh", 0, 30); // gradeToSign = 0 → too high
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << '\n';
    }

    try {
        Form badForm("TooLow", 151, 30); // gradeToSign = 151 → too low
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << '\n';
    }

    separator("Already Signed Form");

    try {
        Bureaucrat carol("Carol", 10);
        Form formC("FormC", 20, 10);

        carol.signForm(formC);  // success
        carol.signForm(formC);  // redundant; should not throw, might print same line
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << '\n';
    }

    separator("All Tests Finished");
    return 0;
}

/*
class-to-class collaboration
two calsses call each others apis (shit that's private)
const vs mutable
class forwar declartation
*/

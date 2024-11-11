/**
 * @file main.cpp
 * @brief This program reads a text file specified by the user, processes the words using a Dictionary object, and prints the results.
 */

#include <iostream>
#include "Dictionary.h"

using std::cout;
using std::cin;
using std::string;

/**
 * @brief The main function of the program.
 *
 * This function prompts the user to input the name of a text file. It then creates a Dictionary object using the file,
 * processes the file, and prints the result.
 *
 * @return int - Returns 0 if the program runs successfully.
 */
int main() {
    // Prompt the user to enter the name of the input text file
    cout << "Enter the name of input text file: " ;

    // Read the filename input by the user
    string filename;
    cin >> filename;

    // Create a Dictionary object using the file specified by the user
    Dictionary dictionary(filename);

    // Process the file and print the results
    dictionary.print(cout);

    // End the program
    return 0;
}


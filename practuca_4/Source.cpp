#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>

int main() {
    std::ifstream input("name1.txt"); // Open the input file
    std::ofstream output("name2.txt"); // Open the output file

    if (!input.is_open()) {
        std::cout << "Failed to open input file." << std::endl;
        return 1;
    }

    if (!output.is_open()) {
        std::cout << "Failed to open output file." << std::endl;
        return 1;
    }

    std::istream_iterator<std::string> inputIterator(input); // Iterator for reading words from input file
    std::ostream_iterator<std::string> outputIterator(output, "\n"); // Iterator for writing words to output file

    while (inputIterator != std::istream_iterator<std::string>()) {
        std::string word = *inputIterator;

        // Check if the word starts and ends with the same letter
        if (!word.empty() && word.front() == word.back()) {
            *outputIterator++ = word; // Write the word to the output file
        }

        ++inputIterator; // Move to the next word in the input file
    }

    input.close(); // Close the input file
    output.close(); // Close the output file

    std::cout << "Words written to name2.txt successfully." << std::endl;

    return 0;
}

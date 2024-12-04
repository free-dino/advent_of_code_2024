#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::string filename = "input.txt"; // Input file name
    std::ifstream infile(filename);

    if (!infile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(infile)),
                         std::istreambuf_iterator<char>());
    infile.close();

    // Regular expressions for "mul(number,number)", "do()", and "don't()"
    std::regex mul_pattern(R"(mul\((\-?\d+),(\-?\d+)\))");
    std::regex do_pattern(R"(do\(\))");
    std::regex dont_pattern(R"(don't\(\))");

    int total_sum = 0;
    bool mul_enabled = true; // Mul instructions are enabled by default

    // Combined regex pattern to match all relevant instructions
    std::regex combined_pattern(R"(do\(\)|don't\(\)|mul\((\-?\d+),(\-?\d+)\))");

    // Start scanning the corrupted memory
    auto start = content.cbegin();
    auto end = content.cend();
    std::smatch match;

    while (std::regex_search(start, end, match, combined_pattern)) {
        if (match[0].str() == "do()") {
            mul_enabled = true;
        } else if (match[0].str() == "don't()") {
            mul_enabled = false;
        } else if (match[1].matched && mul_enabled) { // Check if mul is matched and enabled
            int num1 = std::stoi(match[1].str());
            int num2 = std::stoi(match[2].str());
            total_sum += num1 * num2;
        }

        // Move start to the end of the current match
        start = match.suffix().first;
    }

    std::cout << "The total sum of all enabled mul expressions is: " << total_sum << std::endl;

    return 0;
}

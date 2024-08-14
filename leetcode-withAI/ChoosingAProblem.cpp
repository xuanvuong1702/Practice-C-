#include "ChoosingAProblem.hpp"

using namespace ChoosingAProblem;

void ChoosingAProblem::ReadInput() {
    int n;
    std::vector<int> numbers;

    std::cout << "Enter a number: ";
    std::cin >> n;
    
    std::cout << "Enter a list of numbers (separated by spaces): ";
    std::string input;
    std::getline(std::cin >> std::ws, input);
    
    std::istringstream iss(input);
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }

    
}


void ChoosingAProblem::Run(){
    ChoosingAProblem::ReadInput();
}


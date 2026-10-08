#include <iostream>
#include <string>

int main() {
    int passengerCount;
    std::cout << "Enter number of passengers: ";
    std::cin >> passengerCount;

    std::string* passengerNames = new std::string[passengerCount];

    std::cout << "Enter passenger names:\n";
    for (int index = 0; index < passengerCount; ++index) {
        std::cin >> passengerNames[index];
    }

    std::cout << "\nBoarding sequence:\n";
    for (int index = passengerCount - 1; index >= 0; --index) {
        std::cout << passengerNames[index] << std::endl;
    }

    delete[] passengerNames;
    return 0;
}
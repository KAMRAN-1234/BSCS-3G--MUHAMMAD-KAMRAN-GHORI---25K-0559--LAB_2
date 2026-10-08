#include <iostream>
#include <string>

int main() {
    int capacity = 3;
    int itemCount = 0;
    std::string* itemList = new std::string[capacity];

    for (int entry = 0; entry < 7; ++entry) {
        std::string item;
        std::cout << "Enter item " << entry + 1 << ": ";
        std::cin >> item;

        if (itemCount == capacity) {
            int newCapacity = capacity * 2;
            std::cout << "Resize triggered: " << capacity << " -> " << newCapacity << std::endl;

            std::string* resizedList = new std::string[newCapacity];
            for (int index = 0; index < itemCount; ++index) {
                resizedList[index] = itemList[index];
            }

            delete[] itemList;
            itemList = resizedList;
            capacity = newCapacity;
        }

        itemList[itemCount] = item;
        ++itemCount;
    }

    std::cout << "\nCart items:\n";
    for (int index = 0; index < itemCount; ++index) {
        std::cout << itemList[index] << std::endl;
    }

    delete[] itemList;
    return 0;
}
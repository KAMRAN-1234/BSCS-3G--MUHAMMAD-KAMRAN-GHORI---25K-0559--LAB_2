#include <iostream>

int main() {
    int shelf[6] = {102, 0, 305, 0, 401, 908};

    std::cout << "Shelf before compacting: ";
    for (int index = 0; index < 6; ++index) {
        std::cout << shelf[index] << ' ';
    }

    int writeIndex = 0;
    for (int index = 0; index < 6; ++index) {
        if (shelf[index] != 0) {
            shelf[writeIndex] = shelf[index];
            ++writeIndex;
        }
    }

    while (writeIndex < 6) {
        shelf[writeIndex] = 0;
        ++writeIndex;
    }

    std::cout << "\nShelf after compacting: ";
    for (int index = 0; index < 6; ++index) {
        std::cout << shelf[index] << ' ';
    }

    std::cout << std::endl;
    return 0;
}
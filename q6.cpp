#include <iostream>

int main() {
    int* seatMap[3];

    seatMap[0] = new int[2];
    seatMap[1] = new int[4];
    seatMap[2] = new int[6];

    for (int index = 0; index < 2; ++index) seatMap[0][index] = 0;
    for (int index = 0; index < 4; ++index) seatMap[1][index] = 0;
    for (int index = 0; index < 6; ++index) seatMap[2][index] = 0;

    int cabinChoice;
    int seatNumber;

    std::cout << "Enter -1 to exit.\n";
    while (true) {
        std::cout << "\nEnter class (0=First, 1=Business, 2=Economy): ";
        std::cin >> cabinChoice;

        if (cabinChoice == -1) {
            break;
        }

        std::cout << "Enter seat number: ";
        std::cin >> seatNumber;

        if (cabinChoice < 0 || cabinChoice > 2) {
            std::cout << "Invalid class!\n";
        } else if (cabinChoice == 0 && (seatNumber < 0 || seatNumber >= 2)) {
            std::cout << "Error: First Class has only 2 seat slots!\n";
        } else if (cabinChoice == 1 && (seatNumber < 0 || seatNumber >= 4)) {
            std::cout << "Error: Business Class has only 4 seat slots!\n";
        } else if (cabinChoice == 2 && (seatNumber < 0 || seatNumber >= 6)) {
            std::cout << "Error: Economy Class has only 6 seat slots!\n";
        } else if (seatMap[cabinChoice][seatNumber] == 1) {
            std::cout << "Seat already reserved!\n";
        } else {
            seatMap[cabinChoice][seatNumber] = 1;
            std::cout << "Seat reserved successfully!\n";
        }
    }

    delete[] seatMap[0];
    delete[] seatMap[1];
    delete[] seatMap[2];
    return 0;
}
#include <iostream>

class SafeCommandCenter {
private:
    int* commandValues;
    int commandCount;

public:
    SafeCommandCenter() {
        commandCount = 5;
        commandValues = new int[commandCount];

        for (int index = 0; index < commandCount; ++index) {
            commandValues[index] = 0;
        }
    }

    void safeWrite(int index, int value) {
        if (index < 0 || index >= commandCount || value < 0 || value > 100) {
            std::cout << "CRITICAL ERROR: Invalid command!\n";
            std::cout << "Rover Emergency Braking Triggered!\n";
            return;
        }

        commandValues[index] = value;
    }

    void show() const {
        std::cout << "Commands: ";
        for (int index = 0; index < commandCount; ++index) {
            std::cout << commandValues[index] << ' ';
        }
        std::cout << std::endl;
    }

    ~SafeCommandCenter() {
        delete[] commandValues;
    }
};

int main() {
    SafeCommandCenter roverController;

    roverController.safeWrite(0, 50);
    roverController.safeWrite(1, 80);
    roverController.safeWrite(2, 100);
    roverController.show();

    std::cout << "\nTesting invalid commands:\n";
    roverController.safeWrite(5, 60);
    roverController.safeWrite(-1, 70);
    roverController.safeWrite(2, -20);
    roverController.safeWrite(3, 150);

    std::cout << "\nFinal commands:\n";
    roverController.show();
    return 0;
}
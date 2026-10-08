#include <iostream>

void addNewStudent(int**& studentGrades, int& studentCount) {
    int** updatedGrades = new int*[studentCount + 1];
    for (int index = 0; index <= studentCount; ++index) {
        updatedGrades[index] = new int[3];
    }

    for (int student = 0; student < studentCount; ++student) {
        for (int subject = 0; subject < 3; ++subject) {
            updatedGrades[student][subject] = studentGrades[student][subject];
        }
    }

    std::cout << "\nEnter grades for new student:\n";
    for (int subject = 0; subject < 3; ++subject) {
        std::cin >> updatedGrades[studentCount][subject];
    }

    for (int student = 0; student < studentCount; ++student) {
        delete[] studentGrades[student];
    }
    delete[] studentGrades;

    studentGrades = updatedGrades;
    ++studentCount;

    std::cout << "\nMemory transition: " << studentCount - 1 << " x 3 -> " << studentCount << " x 3\n";
    std::cout << "New student added successfully.\n";
}

int main() {
    int studentCount;
    std::cout << "Enter number of students: ";
    std::cin >> studentCount;

    int** studentGrades = new int*[studentCount];
    for (int student = 0; student < studentCount; ++student) {
        studentGrades[student] = new int[3];
    }

    std::cout << "Enter grades for " << studentCount << " students:\n";
    for (int student = 0; student < studentCount; ++student) {
        std::cout << "Student " << student + 1 << ": ";
        for (int subject = 0; subject < 3; ++subject) {
            std::cin >> studentGrades[student][subject];
        }
    }

    std::cout << "\nInitial memory: " << studentCount << " x 3\n";
    addNewStudent(studentGrades, studentCount);

    std::cout << "\nUpdated grades:\n";
    for (int student = 0; student < studentCount; ++student) {
        std::cout << "Student " << student + 1 << ": ";
        for (int subject = 0; subject < 3; ++subject) {
            std::cout << studentGrades[student][subject] << ' ';
        }
        std::cout << std::endl;
    }

    for (int student = 0; student < studentCount; ++student) {
        delete[] studentGrades[student];
    }
    delete[] studentGrades;

    return 0;
}
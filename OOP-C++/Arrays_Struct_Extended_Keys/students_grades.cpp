#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
    struct subject {
        string name;
        int grade;
    };
        struct student {
        string name;
        int age;
        array<subject, 2> grades;
    };

    array<int, 2> sumOfSubjects = {0, 0};
    array<string, 2> subjectNames;
    array<student, 2> students;

//get data from User
    for (int i = 0; i < students.size(); i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> students[i].name;

        cout << "Enter age of student " << i + 1 << ": ";
        cin >> students[i].age;

        for (int j = 0; j < students[i].grades.size(); j++) {
            cout << "Enter name of subject " << j + 1 << ": ";
            cin >> students[i].grades[j].name;

            cout << "Enter grade for " << students[i].grades[j].name << ": ";
            cin >> students[i].grades[j].grade;
        }
        cout << "----------------------------------\n";
    }
// get the names of Subjects and put it in studentsNames array
    for (int i = 0; i < students[0].grades.size(); i++) {
        subjectNames[i] = students[0].grades[i].name;
    }

    for (int i = 0; i < students.size(); i++) {
        int sumGradesStudent = 0;
        cout << "Student Number " << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;

        for (int j = 0; j < students[i].grades.size(); j++) {
            cout << students[i].grades[j].name << ": " << students[i].grades[j].grade << endl;
            sumGradesStudent += students[i].grades[j].grade;
            sumOfSubjects[j] += students[i].grades[j].grade;
        }

        cout << "Sum of " << students[i].name << "'s grades = " << sumGradesStudent << endl;
        cout << "-----------------------------------------------" << endl;
    }

    for (int i = 0; i < subjectNames.size(); ++i) {
        cout << "Average of " << subjectNames[i] << " = " << sumOfSubjects[i] / 2.0 << endl;
    }

    return 0;
}

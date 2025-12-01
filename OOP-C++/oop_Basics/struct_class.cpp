#include <iostream>

using namespace std;


struct Employee {
    int id;
    float salary;
};

class Employee {
private:
    int id;
    char name[50];
    float salary;

public:
    void setData(int i, float s) {
        id = i;
        salary = s;
    }

    void printInfo() {
        cout << "ID: " << id << ", Salary: " << salary << endl;
    }
};
int main()
{
    return 0;
}

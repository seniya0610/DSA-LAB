#include <iostream>
using namespace std;

int main() {
    int NOD;
    cout << "Enter number of departments: ";
    cin >> NOD;

    float** departments = new float*[NOD];
    int* employeesCount = new int[NOD];

    for (int d = 0; d < NOD; d++) {
        cout << "Enter number of employees for department " << d + 1 << ": ";
        cin >> employeesCount[d];

        departments[d] = new float[employeesCount[d]];

        cout << "Enter the salaries for department " << d + 1 << ": ";
        for (int e = 0; e < employeesCount[d]; e++) {
            cin >> departments[d][e];
        }
    }

    cout << endl;

    // Calculate highest salary in each department
    float* highestSalaries = new float[NOD];
    float* avgSalaries = new float[NOD];
    int maxAvgDept = 0;
    float maxAvg = 0;

    for (int d = 0; d < NOD; d++) {
        float highest = departments[d][0];
        float sum = 0;

        // Find highest salary and calculate sum for average
        for (int e = 0; e < employeesCount[d]; e++) {
            if (departments[d][e] > highest) {
                highest = departments[d][e];
            }
            sum += departments[d][e];
        }

        highestSalaries[d] = highest;
        avgSalaries[d] = sum / employeesCount[d];

        cout << "Department " << d + 1 << " highest salary: " << highestSalaries[d] << endl;
        cout << "Department " << d + 1 << " average salary: " << avgSalaries[d] << endl;

        // Track department with highest average
        if (avgSalaries[d] > maxAvg) {
            maxAvg = avgSalaries[d];
            maxAvgDept = d;
        }
    }

    cout << "\nDepartment with highest average salary: " << endl;
    cout << "Department " << maxAvgDept + 1 << " with average salary: " << maxAvg << endl;

    // Free allocated memory
    for (int d = 0; d < NOD; d++) {
        delete[] departments[d];
    }
    delete[] departments;
    delete[] employeesCount;
    delete[] highestSalaries;
    delete[] avgSalaries;

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout << "Enter number of departments: ";
    cin >> rows;

    int **Departments = new int *[rows];
    int *employees = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        cout << "enter number of employees in department " << i + 1 << ": ";
        cin >> employees[i];
        Departments[i] = new int[employees[i]];
        for (int j = 0; j < employees[i]; j++)
        {
            cout << "enter Salary of employee " << j + 1 << ": ";
            cin >> Departments[i][j];
        }
    }

    int *avg = new int[rows];
    cout << "max salary per department: " << endl;
    for (int i = 0; i < rows; i++)
    {
        int maxSalary = 0;
        int sum = 0;
        for (int j = 0; j < employees[i]; j++)
        {
            if (Departments[i][j] > maxSalary)
            {
                maxSalary = Departments[i][j];
            }
            sum += Departments[i][j];
        }
        avg[i] = sum / employees[i];
        cout << "Department " << i + 1 << ": " << maxSalary << endl;
    }

    int max = 0;
    for (int i = 0; i < rows; i++)
    {
        cout << "Average salary of department " << i + 1 << ": " << avg[i] << endl;

        if (avg[i] > max)
        {
            max = avg[i];
        }
    }

    cout << "Maximum average salary among all departments: " << max << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] Departments[i];
    }
}

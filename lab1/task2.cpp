#include <iostream>
using namespace std;

class Exam {
private:
    string Name;
    string* Date;
    int marks;

public:
    // Constructor
    Exam(string Name = " ", string Date = " ", int marks = 0) {
        this->Name = Name;
        this->marks = marks;
        this->Date = new string;
        *this->Date = Date;
    }

    void setPupilName(string Name) {
        this->Name = Name;
    }

    void setTestDate(string Date) {
        *this->Date = Date;
    }

    void setMarks(int marks) {
        this->marks = marks;
    }

    void displayDetails() {
        cout << "\nName: " << Name << endl 
             << "Test Date: " << *Date << endl 
             << "Marks: " << marks << endl
             << "Date Memory Address: " << Date << endl;
    }

    // Destructor
    ~Exam() {
        delete Date;
    }
};

int main() {
    Exam student1("Seniya Naeem", "14 december, 2024", 89);
    cout << "Original Object:";
    student1.displayDetails();

    Exam student2 = student1;
    cout << "\nShallow Copy (before modification):";
    student2.displayDetails();

    cout << "\nModifying the copy...";
    student2.setPupilName("Ayesha");
    student2.setTestDate("12 August, 2024"); //changed because pointer
    student2.setMarks(90);

    cout << "\nAfter modification:";
    cout << "\nOriginal Object:";
    student1.displayDetails();
    cout << "\nShallow Copy:";
    student2.displayDetails();
    
    return 0;
}

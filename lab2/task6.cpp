#include <iostream>

using namespace std;

class safePointer {
	private:
	    int* gradesArray;
	    size_t arraySize;
	    
	public:
	    safePointer() : gradesArray(nullptr), arraySize(0) {}
	
	    explicit safePointer(size_t studentCount) {
	        gradesArray = new int[studentCount];
	        arraySize = studentCount;
	    }
	
	    void setGrade(size_t studentIndex, int gradeValue) {
	        if (gradesArray != nullptr && studentIndex < arraySize) {
	            gradesArray[studentIndex] = gradeValue;
	        } else {
	            cerr << "Error: Invalid index or uninitialized array!" << endl;
	        }
	    }
	
	    int getGrade(size_t studentIndex) const {
	        if (gradesArray != nullptr && studentIndex < arraySize) {
	            return gradesArray[studentIndex];
	        }
	        cerr << "Error: Invalid index or uninitialized array!" << endl;
	        return -1; // Return -1 to indicate error
	    }
	
	    size_t getStudentCount() const {
	        return arraySize;
	    }
	
	    void deallocateMemory() {
	        delete[] gradesArray;
	        gradesArray = nullptr;
	        arraySize = 0;
	    }
	
	    ~safePointer() {
	        deallocateMemory();
	    }
	    
	    // Prevent copying to avoid double deletion
	    safePointer(const safePointer&) = delete;
	    safePointer& operator=(const safePointer&) = delete;
};

int main() {
    const size_t numberOfStudents = 5;
    safePointer gradeManager(numberOfStudents);

    cout << "Please enter grades for " << numberOfStudents << " students:" << endl;
    for (size_t student = 0; student < numberOfStudents; student++) {
        int grade;
        cin >> grade;
        gradeManager.setGrade(student, grade);
    }

    cout << "\nStudent grades summary:" << endl;
    for (size_t student = 0; student < numberOfStudents; student++) {
        cout << "Student " << (student + 1) << ": " 
             << gradeManager.getGrade(student) << endl;
    }

    return 0;
}

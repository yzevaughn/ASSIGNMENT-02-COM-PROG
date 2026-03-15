#include <iostream>
#include <iomanip>
using namespace std;

void analyzeGrades(int *matrix, int students, int subjects) {
    int highest = *(matrix);

    cout << "\nGrade Matrix:\n";


    cout << "Student\t";
    for(int j = 1; j <= subjects; j++)
        cout << "Sub " << j << "\t";
    cout << "Average\n";


    int totalColumns = 1 + subjects + 1;
    int lineLength = totalColumns * 8;
    for(int i = 0; i < lineLength; i++)
        cout << "-";
    cout << endl;


    for(int i = 0; i < students; i++) {
        double sum = 0;
        cout << i + 1 << "\t";

        for(int j = 0; j < subjects; j++) {
            int value = *(matrix + i * subjects + j);
            cout << value << "\t";
            sum += value;

            if(value > highest) highest = value;
        }

        cout << fixed << setprecision(2) << sum / subjects << endl;
    }

    cout << "\nHighest grade in matrix: " << highest << endl;
}

int main() {
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;
    cout << "Enter number of subjects: ";
    cin >> subjects;

    int grades[students][subjects];

    // Input grades
    cout << "\nEnter grades:\n";
    for(int i = 0; i < students; i++) {
        cout << "Student " << i+1 << "\n";
        for(int j = 0; j < subjects; j++) {

            cout <<" Subject " << j+1 << ": ";
            cin >> grades[i][j];
        }
        cout << "\n";
    }

    analyzeGrades(&grades[0][0], students, subjects);

    return 0;
}

#include<iostream>
#include<fstream>
using namespace std;

int main() {
    float id, hourlyWage, hoursWorked, salary;
    string name;
    int numEmployees;

    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    ofstream file("RT_employee_data.txt");

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    for (int i = 0; i < numEmployees; i++) {
        cout << "\nEnter details for Employee #" << i + 1 << endl;

        cout << "Enter your name: ";
        cin.ignore(); 
        getline(cin, name); 

        cout << "Enter your Employee ID: ";
        cin >> id;
        cout << "Enter your total worked hours: ";
        cin >> hoursWorked;
        cout << "Enter your hourly wage: ";
        cin >> hourlyWage;
        salary = hoursWorked * hourlyWage;

        cout << "\n____________________________" << endl;
        cout << "   HAVELI RESTAURANT LAHORE   " << endl;
        cout << "     Payment Receipt        " << endl;
        cout << "Name:           "<< name << endl;
        cout << "Employee ID:    "<< id << endl;
        cout << "Hours Worked:   "<< hoursWorked << endl;
        cout << "Hourly Wage RS: "<< hourlyWage << endl;
        cout << "Salary RS:      "<< salary << endl;
        cout << "______________________________" <<endl;
        
        file << "_____________________________ " << endl;
        file << "   HAVELI RESTAURANT LAHORE   " << endl;
        file << "     Payment Receipt        " << endl;
        file << "Name:           "<< name << endl;
        file << "Employee ID:    "<< id << endl;
        file << "Hours Worked:   "<< hoursWorked << endl;
        file << "Hourly Wage  RS:"<< hourlyWage << endl;
        file << "Salary: RS      "<< salary << endl;
        file << "______________________________" << endl;
    }
    file.close();
    cout << "\nEmployee data has been saved to 'RT_employee_data.txt'" << endl;

    return 0;
}

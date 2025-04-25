#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    int empNo;
    char empName[16];
    char gender;
    double basicSalary, allowances, loan, netSalary;

    int empNos[999] = {0}; // Array to store employee numbers
    string empNames[999];  // Array to store employee names
    char genders[999];
    double allowances2[999] = {0};   // Array to store allowances
    double basicSalaries[999] = {0}; // Array to store basic salaries
    double loans[999] = {0};         // Array to store loans
    double netSalaries[999] = {0};   // Array to store net salaries

    // Totals for resualt
    double totalBasic = 0, totalAllowances = 0, totalLoan = 0, totalNet = 0;
    int employeeCount = 0;

    char continueInput = 'Y';

    cout << "Employe Payroll Data Entry System\n";
    cout << "---------------------------------\n\n";
    int empCount = 0;

    while (continueInput == 'Y' || continueInput == 'y')
    {
        // Employee Number input and val
        bool vEmpNo = false;
        do
        {
            cout << "Enter Employee Number (1-999): ";
            cin >> empNo;

            if (cin.fail())
            {
                cin.clear();
                cout << "Invalid input Please enter a number 1-999 ";
                continue;
            }

            if (empNo >= 1 && empNo <= 999)
            {
                vEmpNo = true;
            }
            else
            {
                cout << "Employee number must be between 1 and 999. Try again.\n";
            }
        } while (!vEmpNo); // while loop for employee number val

        cin.ignore(10000, '\n'); // Clear newline

        // Employee Name input and val
        bool validName = false;
        do
        {
            cout << "Enter Employee Name max 15 letters ";
            cin.getline(empName, 16); // max num of chars

            bool nvChars = false;
            int nameLength = 0;
            while (empName[nameLength] != '\0')
                nameLength++; // \0 = null

            if (nameLength > 15)
            {
                nvChars = true;
            }
            else
            {
                for (int i = 0; empName[i] != '\0'; i++)
                {
                    char c = empName[i];
                    if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' '))
                    {
                        nvChars = true;
                        break;
                    }
                }
            }

            if (nvChars)
            {
                cout << "Invalid name only letters and spaces max 15 characters \n";
            }
            else
            {
                validName = true;
            }
        } while (!validName);

        // Gender input and validation
        bool validGender = false;
        do
        {
            cout << "Enter Gender (M/F): ";
            cin >> gender;

            gender = toupper(gender); // upperCasing
            if (gender == 'M' || gender == 'F')
            {
                validGender = true;
            }
            else
            {
                cout << " Please enter M or F\n";
            }
        } while (!validGender);

        // Basic Salary input and validation
        bool validSalary = false;
        do
        {
            cout << "Enter Basic Salary 750,000 - 3,500,000.999 ";
            cin >> basicSalary;

            if (cin.fail())
            {
                cin.clear();
                cout << " Please enter a number";
                continue;
            }

            if (basicSalary >= 750000 && basicSalary <= 3500000.999)
            {
                validSalary = true;
            }
            else
            {
                cout << "Basic salary must be between 750,000 and 3,500,000.999 Try again\n";
            }
        } while (!validSalary);

        // Allowances input and validation
        bool vAllowances = false;
        do
        {
            cout << "Enter Allowances 100,000 - 250,000.999 ";
            cin >> allowances;

            if (cin.fail())
            {
                cin.clear();
                cout << "Invalid input ";
                continue;
            }

            if (allowances >= 100000 && allowances <= 250000.999)
            {
                vAllowances = true;
            }
            else
            {
                cout << "Allowances must be between 100,000 and 250,000.999 Try again\n";
            }
        } while (!vAllowances);

        // Calculate loan based on gender
        loan = (gender == 'M') ? basicSalary * 0.04 : basicSalary * 0.05;

        // Calculate net salary
        netSalary = (basicSalary + allowances) - loan;

        // Add to totals
        totalBasic += basicSalary;
        totalAllowances += allowances;
        totalLoan += loan;
        totalNet += netSalary;
        employeeCount++;

        empNos[empCount] = empNo; // Store employee number
        empNames[empCount] = empName;
        genders[empCount] = gender;
        allowances2[empCount] = allowances;
        basicSalaries[empCount] = basicSalary;
        loans[empCount] = loan;
        netSalaries[empCount] = netSalary;

        // Ask to continue
        cout << "Enter another employee? (Y/N) ";
        cin >> continueInput;
        cout << "\n\n\n\n\n\n\n\n\n\n";

        if (continueInput == 'N' || continueInput == 'n')
        {
            // left = left alignment
            // stew = set width
            cout << left << setw(8) << "Emp No" << "| "
                 << setw(15) << "Emp Name" << "| "
                 << setw(8) << "Gender" << "| "
                 << setw(14) << "Basic Salary" << "| "
                 << setw(12) << "Allowances" << "| "
                 << setw(10) << "Loan" << "| "
                 << setw(12) << "Net Salary" << "\n";
            cout << "==============================================================================================\n";
            for (int i = 0; i <= empCount; i++)
            {
                // because we don't know the space the data will take in the table so we have to set constant width so it would be readable

                cout << left << setw(8) << empNos[i] << "| "
                     << setw(15) << empNames[i] << "| "
                     << setw(8) << genders[i] << "| "
                     << setw(14) << fixed << setprecision(3) << basicSalaries[i] << "| "
                     << setw(12) << fixed << setprecision(3) << allowances2[i] << "| "
                     << setw(10) << fixed << setprecision(3) << loans[i] << "| "
                     << setw(12) << fixed << setprecision(3) << netSalaries[i] << "\n";
                cout << "==============================================================================================\n";
            }
            cout << "Number of Employees Processed: " << employeeCount << "\n";

            break;
        }
        empCount++;
    }

    return 0;
}
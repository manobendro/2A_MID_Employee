// Created by Manobendronath at 10:01PM
// CLion 2018.3

#include <iostream>
#include <vector>

using namespace std;

class Employee {

private:
    string name;
    int id;
    int designetion; // 0 for CEO, 1 for FVD, 2 for manager, 3for general worker
    int monthSal; //
    int yearOfExp; //
    int performance; //performance should be 0 - 100;
public:
    Employee() {

    }

    void putData(string name, int id, int designetion, int monthSal, int yearOfExp, int performance) {
        Employee::name = name;
        Employee::id = id;
        Employee::designetion = designetion;
        Employee::monthSal = monthSal;
        Employee::yearOfExp = yearOfExp;
        Employee::performance = performance;
    }

    int getPerformance() {
        return performance;
    }

    void setPerformance(int performance) {
        Employee::performance = performance;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        Employee::name = name;
    }

    int getId() {
        return id;
    }

    void setId(int id) {
        Employee::id = id;
    }

    int getDesignetion() {
        return designetion;
    }

    void setDesignetion(int designetion) {
        Employee::designetion = designetion;
    }

    int getMonthSal() {
        return monthSal;
    }

    void setMonthSal(int monthSal) {
        Employee::monthSal = monthSal;
    }

    int getYearOfExp() {
        return yearOfExp;
    }

    void setYearOfExp(int yearOfExp) {
        Employee::yearOfExp = yearOfExp;
    }

};

class EmployeeDatabase {
private:
    int counter = 0;
    Employee employee[11];
    vector<Employee> employees;
public:
    EmployeeDatabase() {

    }

    void putEmployData(string name, int id, int designetion, int monthSal, int yearOfExp, int per) {
        Employee employeeA = Employee();
        employeeA.putData(name, id, designetion, monthSal, yearOfExp, per);
        employee[counter].putData(name, id, designetion, monthSal, yearOfExp, per);
        counter++;
        employees.push_back(employeeA);
        //cout << "Employe at zero index : " << employees[0].getName() << endl;
    }

    int getNumberOfEmployee() {
        return employees.size();
    }

    int getEmployeeName() {
        for (auto x:employees) {
            cout << x.getName() << endl;
            //return 1;
        }
        return 0;
    }

    int getSalaryById(int id) {
        for (int i = 0; i <= counter; i++) {
            if (employee[i].getId() == id) {
                return employee[i].getMonthSal(); //return salary by employee id
            }
        }
        return 404; // 404 for not found
    }

    void updateDesig(int id) {
        for (int i = 0; i <= counter; i++) {
            if (employee[i].getId() == id) {
                if (employee[i].getYearOfExp() >= 2 && employee[i].getDesignetion() > 0) {
                    employee[i].setDesignetion(employee[i].getDesignetion() - 1);
                    cout << "Designation updated for " << employee[i].getName() << endl;
                    return;
                }
            }
        }
        cout << "Required not fulfil!\n";
    }

    void incrimentSalary(int id) {
        for (int i = 0; i <= counter; i++) {
            if (employee[i].getId() == id) {
                if (employee[i].getPerformance() >= 80) {
                    employee[i].setMonthSal(employee[i].getMonthSal() + 10000);
                    cout << "Salary updated for " << employee[i].getName() << endl;
                    return;
                }
            }
        }
        cout << "Required not fulfil!\n";
    }
};

int main() {

    EmployeeDatabase database;
    database.putEmployData("Manob Biswas", 001, 3, 50000, 5,
                           98); //Name , Id , Designation, Salary, Year of Exp, Performance
    database.putEmployData("Sajal Biswas", 002, 2, 40000, 1, 60);

    cout << "Number of Employee: " << database.getNumberOfEmployee() << endl;

    cout << "For id 1\n";
    cout << database.getSalaryById(001);
    cout << "\n";
    database.updateDesig(001);
    database.incrimentSalary(001);

    cout << "For id 2\n";
    cout << database.getSalaryById(002);
    cout << "\n";
    database.updateDesig(002);
    database.incrimentSalary(002);

    database.getEmployeeName();


    return 0;
}
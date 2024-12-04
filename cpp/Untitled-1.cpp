#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
    private:
        string name;
        int age;
        string designation;
        double salary;
    public:
        Employee(string n, int a, string d, double s) {
            name = n;
            age = a;
            designation = d;
            salary = s;
        }
        void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Designation: " << designation << endl;
            cout << "Salary: " << salary << endl;
        }
};

class Department {
    private:
        string name;
        vector<Employee> employees;
    public:
        Department(string n) {
            name = n;
        }
        void addEmployee(Employee e) {
            employees.push_back(e);
        }
        void display() {
            cout << "Department: " << name << endl;
            for (int i = 0; i < employees.size(); i++) {
                employees[i].display();
                cout << endl;
            }
        }
};

class Company {
    private:
        string name;
        vector<Department> departments;
    public:
        Company(string n) {
            name = n;
        }
        void addDepartment(Department d) {
            departments.push_back(d);
        }
        void display() {
            cout << "Company: " << name << endl;
            for (int i = 0; i < departments.size(); i++) {
                departments[i].display();
                cout << endl;
            }
        }
};

int main() {
    Company c("ABC Company");
    Department d1("Sales");
    Department d2("Marketing");
    Employee e1("John Doe", 30, "Manager", 5000);
    Employee e2("Jane Smith", 25, "Salesperson", 3000);
    Employee e3("Bob Johnson", 35, "Marketing Manager", 6000);
    Employee e4("Alice Brown", 28, "Marketing Executive", 4000);
    d1.addEmployee(e1);
    d1.addEmployee(e2);
    d2.addEmployee(e3);
    d2.addEmployee(e4);
    c.addDepartment(d1);
    c.addDepartment(d2);
    c.display();
    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

// Define an Employee class to store the information of each employee
class Employee {
public:
    int id;
    int age;
    char gender;
    int salary;
    Employee(){}
    Employee(int id, int age, char gender, int salary) : 
        id(id), age(age), gender(gender), salary(salary) {}
};

bool compareGender(const Employee &a, const Employee &b) {
    if (a.age == b.age) {
        //lady first
        if (a.gender == 'f' && b.gender == 'm') {
            return true; 
        } else if (a.gender == 'm' && b.gender == 'f') {
            return false;  
        }else{
            if(a.id>b.id){
                return false;
            }else{
                return true;
            }
        }
    }
    return a.age < b.age;
}

int main(int argc, char* argv[]) {
    //open file
    string filename = argv[1];
    ifstream input_file(filename);
    //vector for employees
    vector<Employee> employees;

    string line;
    while (getline(input_file, line)) {
        int id, age, salary;
        char gender;
        sscanf(line.c_str(), "%d,%d,%c,%d", &id, &age, &gender, &salary);
        employees.push_back(Employee(id, age, gender, salary));
    }
    input_file.close();
    // Group employees by salary using a map
    map<int, vector<Employee>> salary_groups;
    for (const auto& e : employees) {
        salary_groups[e.salary].push_back(e);
    }
    // Print employees by salary and age
    for (const auto& p : salary_groups) {
        int salary = p.first;
        vector<Employee> group = p.second;
        sort(group.begin(), group.end(), compareGender);
        cout << salary << ",";
        for (size_t i = 0; i < group.size(); i++) {
            if (i > 0) {
                cout << ",";
            }
            cout << group[i].id;
        }
        cout << endl;
    }
   return 0;
}
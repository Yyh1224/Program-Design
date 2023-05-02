#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include<sstream>
using namespace std;

class AttendanceRecord {
public:
    string employee_id;
    string signing_type;
    string signing_time;
};

class Employee {
public:
    string id;
    vector<AttendanceRecord> records;

    int count_overloading_days(map<string,bool>sign) const {
        int count = 0;
        map<string, int> hours_map;
        for (const auto& record : records) {
            int hr_in, min_in, hr_out, min_out;
            if(sign[record.signing_time.substr(0, 8)]==0){//check status
                if (record.signing_type == "sign-in"){
                    hr_in = stoi(record.signing_time.substr(8,2))*60;
                    min_in = stoi(record.signing_time.substr(10,2));
                    hours_map[record.signing_time.substr(0, 8)] -= (hr_in + min_in);
                }else{
                    hr_out = stoi(record.signing_time.substr(8, 2))*60;
                    min_out = stoi(record.signing_time.substr(10,2));
                    hours_map[record.signing_time.substr(0, 8)] += (hr_out+min_out);
                }
            }else{count += 0;}   
        }
        for (const auto& record : records){
            if (hours_map[record.signing_time.substr(0, 8)] > 8*60) count ++;
        }
        return count/2;
    }

    map<string, bool> count_sign_forget_days() const {
        map<string, bool> sign_in_map;
        AttendanceRecord test;
        for (const auto& record : records) {
            bool tmp = sign_in_map[record.signing_time.substr(0, 8)];
            if (record.signing_type == "sign-in" && tmp == false) {
                sign_in_map[record.signing_time.substr(0, 8)] = true;
            }else if(record.signing_type == "sign-in" && tmp == true){
                sign_in_map[record.signing_time.substr(0, 8)] = !tmp;
            }else if(record.signing_type == "sign-out" && tmp == false){
                sign_in_map[record.signing_time.substr(0, 8)] = true;
            }else {
                sign_in_map[record.signing_time.substr(0, 8)] = !tmp;
            }   
        }
        return sign_in_map;
    }
};

int main(int argc, char* argv[]) {
    ifstream file(argv[1]);
    vector<Employee> employees;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string field;
        vector<string> fields;
        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }
        if (fields.size() != 3) {
            cerr << "Warning: invalid line: " << line << endl;
            continue;
        }

        string employee_id = fields[0];
        string signing_type = fields[1];
        string signing_time = fields[2];
        // cout<<employee_id<<" "<<signing_type<<" "<<signing_time<<endl;
        auto it = std::find_if(employees.begin(), employees.end(), [&](const Employee& e) { return e.id == employee_id; });
        
        if (it == employees.end()) {
            employees.push_back(Employee{employee_id, {{employee_id, signing_type, signing_time}}});
        } else {
            it->records.push_back({employee_id, signing_type, signing_time});
        }
    }
    sort(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2) { return stoi(e1.id) < stoi(e2.id); });
    
    for (const auto& employee : employees) {
        // cout<<employee.id<<endl;
        int overloading_days = 0, sign_forget_days = 0;
        map<string, bool> check;
        check = employee.count_sign_forget_days();
        for(auto i: check){
            if(i.second) sign_forget_days++;
        }
        overloading_days = employee.count_overloading_days(check);
        cout<<employee.id<<","<<overloading_days<<","<<sign_forget_days<<endl;
        }
}
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

 

int main(int argc, char* argv[])

{
    //open file
    string filename = argv[1];
    ifstream myfile(filename);
    string line;
    while (getline(myfile, line)) {
        cout<<line<<endl;
    }
    myfile.close();
}
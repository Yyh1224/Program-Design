# include <iostream>
using namespace std;
int main(int argc, char** argv){//read cmd input
    int input = atoi(argv[1]);
    int mul=1, x=0 , y=input;
    int max = 0;
    for (int i = 0; i <= input; i ++){
        x = i;
        cout << "(" << x <<","<< y << ")" << endl;
        mul = x * y;
        if (max < mul){
            max = mul;
        }
        y -= 1;    
    }   
    cout << max << endl;
    return 0;
}
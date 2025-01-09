#include<iostream>
#include<climits>
#include<iomanip>
#include<cstdlib>
#include<string>

using namespace std;

// Function Prototypes
void doSomething();
int randomNumber(int, int);

int main(int argc, char* argv[]){
    doSomething();
    int x = 40;
    int y = 60;
    int number = randomNumber(x,y);

    cout << number << endl;

    string txt = "This is a C++ string";
    string name;

    for (int i=0; i<txt.length(); i++){
        cout << txt[i] << "-";
    }
    cout << endl << txt << endl;

    // cout << "Enter Name: ";
    // cin >> name;

    // cout << "Your name is: " << name << endl;

    cout << INT_MAX << " TO " << INT_MIN << endl;

    float fnum = 15433.28934;
    double dnum = 15433.28934;

    cout << setprecision(20) << fixed << fnum << endl;
    cout << setprecision(20) << fixed << dnum << endl;

    cout << fixed << fnum << endl;
    cout << scientific << fnum << endl;

    // long int lNum;
    // short int sNum;
    // long double ldNum;
    // wchar_t spChar;

    cout << "Size of INT: " << sizeof(int) << endl;

    bool bVal = true;
    cout << bVal << endl;

    char cValue = 55; // 55 (DECIMAL) = 7 (ASCII VALUE)
    char num = '7';
    cout << cValue << endl;
    cout << num << endl;
    cout << (int)num << endl;

    // Cannot change again unless const is used again
    const string password = "hello";

    return 0;
}

void doSomething(){
    cout << "Hello World" <<endl;
}

int randomNumber(int x, int y){
    int num = rand();
    return (num-x-y);
}
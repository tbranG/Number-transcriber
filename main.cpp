#include<iostream>
#include"Transc.hpp"

using namespace std;

int main(int argv, char** argc){
    Translator t;
    unsigned int num;
    cin >> num;

    if(num > 999999){
        cout << "Numero invalido para conversao" << endl;
        cout << "Num = " << num;
    }else{
        cout << t.transcribe(num);
    }
    return 0;
}
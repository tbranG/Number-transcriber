#include <iostream>
#include <stdexcept>
#include "transc.hpp"

using namespace std;

int main(int argv, char** argc){
    try{
        //languages 'en', 'pt-BR'
        std::string language;
        cout << "Enter your language:\n\ten\n\tpt-BR\n:";
        cin >> language;

        Translator t(language);
        unsigned int num;
        cout << "Enter the number\n:";
        cin >> num;

        if(num > 999999){
            cout << "Invalid number" << endl;
            cout << "Num = " << num;
        }else{
            cout << t.transcribe(num);
        }
    }catch(std::invalid_argument excp){
        cout << excp.what();
    }
    return 0;
}
#ifndef TRANSC_HPP
#define TRANSC_HPP
#include <string>
#include <vector>

class Translator{
    private:
        unsigned short langCode;
        std::string transAuto(unsigned int num, unsigned int carry, unsigned short it);
        
        std::vector<std::string> unitStrings;
        std::vector<std::string> extraStrings;  //para números no intervalo de 11..19
        std::vector<std::string> tensStrings;
        std::vector<std::string> hundredsStrings;

        std::string connectionString;
        std::string hundredSimpleString;
        std::string thousandSimpleString;

        std::string getUnitStr(unsigned short num);
        std::string getTensStr(unsigned short over, unsigned short left);
        std::string getHundredsStr(unsigned short over, unsigned short left);
        std::string getThousandsStr(unsigned short over, unsigned short left);

    public:
        Translator(std::string lang);
        std::string transcribe(unsigned int num);
};

#endif
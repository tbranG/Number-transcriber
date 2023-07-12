#include<string>
#include"Transc.hpp"

//Construtor
Translator::Translator(){
    unitStrings = {
        "zero", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"
    };
    extraStrings = {
        "onze", "doze", "treze", "quatorze", "quize", "dezesseis", "dezessete", "dezoito", "dezenove"
    };
    tensStrings = {
        "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"
    };
    hundredsStrings = {
        "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"
    };
}

/// @brief Método que retorna uma string transcrevendo números no intervalo de 0..9
/// @param num Número para transcrição
/// @return Número transcrito (string)
std::string Translator::getUnitStr(unsigned short num){
    return Translator::unitStrings[num];
}

/// @brief Método que retorna uma string transcrevendo números no intervalo de 10..99
/// @param over Overflow do número. (exemplo base decimal, resto = 9, overflow = 1, número = 19)
/// @param left Valor restante do número
/// @return Número transcrito (string)
std::string Translator::getTensStr(unsigned short over, unsigned short left){
    //exceção para o intervalo de 11..19
    if(over==1 && left > 0){
        return extraStrings[left - 1];
    }

    if(left==0){
        return tensStrings[over - 1];
    }else{
        return tensStrings[over - 1] + " e " + unitStrings[left];
    }
}

/// @brief Método que retorna uma string transcrevendo números no intervalo de 100..999
/// @param over Overflow do número. (exemplo base decimal, resto = 12, overflow = 1, número = 112)
/// @param left Valor restante do número
/// @return Número transcrito (string)
std::string Translator::getHundredsStr(unsigned short over, unsigned short left){
    //exceção para o número cem. Acima de cem, os números são escritos com cento.
    if(over==1 && left==0){
        return "cem";
    }

    if(left==0){
        return hundredsStrings[over - 1];
    }
    else if(left < 10){
        return hundredsStrings[over - 1] + " e " + getUnitStr(left);
    }else{
        return hundredsStrings[over - 1] + " e " + getTensStr(left / 10, left % 10);
    }
}

std::string Translator::getThousandsStr(unsigned short over, unsigned short left){
    //tratando casos especiais
    if(left==0 && over==1){
        return "mil";
    }
    if(left==0 && over < 10){
        return getUnitStr(over) + " mil";
    }
    if(left==0 && over < 100){
        return getTensStr(over / 10, over % 10) + " mil";
    }
    if(left==0 && over < 1000){
        return getHundredsStr(over / 100, over % 100) + " mil";
    }

    if(over==1 && left < 10){
        return "mil e " + getUnitStr(left);
    }
    if(over==1 && left < 100){
        return "mil e " + getTensStr(left / 10, left % 10);
    }
    if(over==1 && left < 1000){
        return "mil e " + getHundredsStr(left / 100, left % 100);
    }
    //-----------------------------
    //casos genéricos
    
    std::string numStr = "";
    if(over < 10){
        numStr += getUnitStr(over) + " mil e ";
    }
    else if(over < 100){
        numStr += getTensStr(over / 10, over % 10) + " mil e ";
    }
    else if(over < 1000){
        numStr += getHundredsStr(over / 100, over % 100) + " mil e ";
    }

    if(left < 10){
        numStr += getUnitStr(left);
    }
    else if(left < 100){
        numStr += getTensStr(left / 10, left % 10);
    }
    else if(left < 1000){
        numStr += getHundredsStr(left / 100, left % 100);
    }
    return numStr;
}

std::string Translator::transcribe(unsigned int num){
    return transAuto(num, num, 0);
}
std::string Translator::transAuto(unsigned int num, unsigned int carry, unsigned short it){
    if(carry < 10){
        switch(it){
            //número de uma casa. ex: 1
            case 0: return getUnitStr(carry);
            //número de duas casas. ex: 10
            case 1: return getTensStr(num / 10, num % 10);
            //número de tres casas. ex: 100
            case 2: return getHundredsStr(num / 100, num % 100);
            //número no intervalo de 1000..999999
            case 3: case 4: case 5: return getThousandsStr(num / 1000, num % 1000);
            default:
                return "ERROR: nao foi possivel converter numero\n";
        }
    }else{
        return transAuto(num, carry/10, it + 1);
    }
}
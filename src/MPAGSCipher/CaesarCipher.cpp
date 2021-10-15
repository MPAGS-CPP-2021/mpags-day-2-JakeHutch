#include <cctype>
#include <iostream>
#include <string>
#include <vector>

//#include "Caesar_Cipher.hpp"

std::string runCaesarCipher( const std::string& inputText, const size_t key, const bool encrypt ){

    // initialise and create alphabet variable 
    const std::vector<char> alphabet {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    const std::string outputText {""};

    char in_Char {'X'};


    for (std::size_t i{0}; i < inputText.length(); ++i) {
        in_Char = inputText[i];
        int index {}; // this will be the letter of the alphabet which corresponds to in_Char

        for (std::size_t j{0}; j < alphabet.size(); ++j) {
            if (in_Char == alphabet[j]) {
                index=j;
                break;
            }
        }
        if (encrypt){
            if (index + key > 25) {
                outputText += {alphabet[index + key -25]};
            }else {
                outputText += {alphabet[index + key]};
            }
        }else {
            if (index + key < 0) {
                outputText += {alphabet[index - key +25]};
            }else {
                outputText += {alphabet[index - key]};
            }            
        }
    }
    return outputText;
}
int main () {
    // this very much does not work... 
    std::string out_text { runCaesarCipher("Hello 123", 1 , true )};
    std::cout << out_text;
}
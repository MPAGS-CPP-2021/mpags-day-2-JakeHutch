#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "CaesarCipher.hpp"

std::string runCaesarCipher( const std::string& inputText, const int key, const bool encrypt ){



    // initialise and create alphabet variable 
    const std::vector<char> alphabet {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    std::string outputText {""};

    char in_Char {'X'};


    for (std::size_t i{0}; i < inputText.length(); ++i) {
        in_Char = inputText[i];
        int index {0}; // this will be the letter of the alphabet which corresponds to in_Char

        for (std::size_t j{0}; j < alphabet.size(); ++j) {
            if (in_Char == alphabet[j]) {
                index=j;
                break;
            }
        }
        if (encrypt){
            outputText += {alphabet[(index + key) % 26]};
        }else {
            // I have used an int for key not an unsigned int so that index-key can go negative 
            if (key > index) {
                outputText += {alphabet[(index - key) +26]};
            }else {
                outputText += {alphabet[index - key]};
            }             
        }
    }
    return outputText;
}
// int main () {
//     // test script
//     std::string out_text { runCaesarCipher("HELLOONE", 5 , true )};
//     std::cout << out_text << std::endl ;

//     std::string out_text_d {runCaesarCipher(out_text, 5 , false )};
//     std::cout << out_text_d << std::endl ;
// }
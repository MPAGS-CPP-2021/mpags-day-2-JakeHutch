#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "TransformChar.hpp"


std::string transformChar( const char inputChar ){
    /*
    change letters into upper case, numbers into words and ignore special characters

    char in_char : the character to transform 

    return : A string of the transformed character
    */
       // Initialise variables
    std::string inputText;

    if (std::isalpha(inputChar)) {
            inputText = std::toupper(inputChar);
            return inputText;
        }

    // Transliterate digits to English words
    switch (inputChar) {
        case '0':
            inputText = "ZERO";
            break;
        case '1':
            inputText = "ONE";
            break;
        case '2':
            inputText = "TWO";
            break;
        case '3':
            inputText = "THREE";
            break;
        case '4':
            inputText = "FOUR";
            break;
        case '5':
            inputText = "FIVE";
            break;
        case '6':
            inputText = "SIX";
            break;
        case '7':
            inputText = "SEVEN";
            break;
        case '8':
            inputText = "EIGHT";
            break;
        case '9':
            inputText = "NINE";
            break;
    }
    return inputText;
}
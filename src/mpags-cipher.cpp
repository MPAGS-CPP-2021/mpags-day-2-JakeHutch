#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "TransformChar.hpp"
#include "ProcessCmd.hpp"
#include "Caesar_Cipher.hpp"

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    //const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    //call function for processing command line arguements 

    const bool cmdStatus {processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile)};

    if (!cmdStatus) {
        return 0;
    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // Read in user input from stdin/file
    if (!inputFile.empty()) {
        std::ifstream in_file {inputFile};
        if (in_file.good()){
            //in_file >> inputChar ;
            while (in_file >> inputChar){
                inputText += {transformChar(inputChar)};
            }
        }
        
        in_file.close();

        
        
    }else {
        // loop over each character from user input
        while (std::cin >> inputChar) {
            inputText += {transformChar(inputChar)};
    }
    }



    // Print out the transliterated text

    // Warn that output file option not yet implemented
    if (!outputFile.empty()) {
        std::ofstream out_file {outputFile};
        if (out_file.good()){
            out_file << inputText;
        }
        out_file.close();
        return 0;
    }else {
        std::cout << inputText << std::endl;
    }


    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}




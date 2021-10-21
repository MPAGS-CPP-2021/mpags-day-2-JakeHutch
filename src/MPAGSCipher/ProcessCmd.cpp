#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "ProcessCmd.hpp"

bool processCommandLine( const std::vector<std::string>& cmdLineArgs,
    std::size_t& key,
    bool& helpRequested,
    bool& versionRequested,
    bool& encrypt,
    std::string& inputFile,
    std::string& outputFile 
)
{
    /*
    Process the arguements passed from the command line 

    bool& helpRequested : whether help was requested
    bool& versionRequested: whether version was requested 
    std::string& inputFileName : the variable containg the filepath to the input
    std::string& outputFileName : the variable containg the filepath to which the output should be written
    */
    const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
            helpRequested = true;
        } else if (cmdLineArgs[i] == "--version") {
            versionRequested = true;
        }else if (cmdLineArgs[i] == "-d") {
            encrypt = false ;

        } else if (cmdLineArgs[i] == "-k") {
            if (i == nCmdLineArgs - 1) {
                // exit main with non-zero return to indicate failure
                std::cerr << "[error] -k requires a key" << std::endl;
                return false ;
            } else {
                key = std::stoul(cmdLineArgs[i + 1]) ;
                ++i;
            }

        } else if (cmdLineArgs[i] == "-i") {
            // Handle input file option
            // Next element is filename unless "-i" is the last argument
            if (i == nCmdLineArgs - 1) {
                // exit main with non-zero return to indicate failure
                std::cerr << "[error] -i requires a filename argument" << std::endl;
                return false ;
            } else {
                // Got filename, so assign value and advance past it
                inputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-o") {
            // Handle output file option
            // Next element is filename unless "-o" is the last argument
            if (i == nCmdLineArgs - 1) {
                // exit main with non-zero return to indicate failure
                std::cerr << "[error] -o requires a filename argument" << std::endl;
                return false;
            } else {
                // Got filename, so assign value and advance past it
                outputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else {
            // Have an unknown flag to output error message and return non-zero
            // exit status to indicate failure
            std::cerr << "[error] unknown arguement" << std::endl;
            return false;
        } 
    }
    return true;
}

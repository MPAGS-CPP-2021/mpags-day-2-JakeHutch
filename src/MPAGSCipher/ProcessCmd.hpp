#ifndef MPAGSCIPHER_PROCESS_CMD
#define MPAGSCIPHER_PROCESS_CMD

#include <string>
#include <vector>

bool processCommandLine( const std::vector<std::string>& cmdLineArgs,
    int& key,
    bool& helpRequested,
    bool& versionRequested,
    bool& encrypt,
    std::string& inputFile,
    std::string& outputFile 
);

#endif //MPAGSCIPHER_PROCESS_CMD
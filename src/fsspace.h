#pragma once

#include <cstdarg>
#include <string>
#include <map>

using namespace std;

namespace fsspace {

    class FileSystemSpace {
        public:
            FileSystemSpace();
            ~FileSystemSpace();
            
            // Methods
            bool status(
                const std::string& dir,  // in
                std::string& err,        // out
                long& bytesTotal,        // out
                long& bytesAvail,        // out
                long& bytesUsed,         // out
                float& pctUsed);         // out
    
    }; // FileSystemSpace 
} // fsspace namespace

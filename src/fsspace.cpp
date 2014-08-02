#include "fsspace.h"
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <stdlib.h>

using namespace std;
using namespace fsspace;

FileSystemSpace::FileSystemSpace() 
{
}

FileSystemSpace::~FileSystemSpace()
{
}

/**
 * Retrieves disk usage information for the specified directory.
 * @param dir Input - Directory to get usage info for.  Will not be modified.
 * @param err Output - Contains error message if there is a failure.  
 * @param bytesTotal Output - Contains total bytes available on the filesystem the directory resides on.
 * @param bytesAvail Output - Contains remaining bytes available on the filesystem the directory resides on.
 * @param bytesUsed Output - Contains the bytes used by the specified directory.
 * @param pctUsed Output - Contains the pct of total available space that the directory is using.
 *
 * @return true on success, false on failure.
 */
bool FileSystemSpace::status(
        const std::string& dir,   // in
        std::string& err,         // out
        long& bytesTotal,         // out
        long& bytesAvail,         // out
        long& bytesUsed,          // out
        float& pctUsed)           // out
{
    struct statvfs sbuf;
    if (statvfs("/", &sbuf) < 0) {
        return false;
    }
    // Total bytes
    bytesTotal = sbuf.f_frsize*sbuf.f_blocks;
    
    // Available to user process
    bytesAvail = sbuf.f_frsize*sbuf.f_bavail;

    // User process bytes used
    bytesUsed = bytesTotal - bytesAvail;
  
    // % of user process bytes used
    pctUsed= (float)bytesUsed / (float)bytesTotal * 100.0;

    return true;
}

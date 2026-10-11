#include "types.h"
extern char D_00559F20[];
extern char* strrchr(const char* s, int c);
extern char* strchr(const char* s, int c);
extern void String_Copy(char* d, const char* s);
char* Path_GetBaseName(const char* path)
{
    const char* s = strrchr(path, '\\');
    char* d;
    path = s ? s + 1 : path;
    String_Copy(D_00559F20, path);
    d = strchr(D_00559F20, '.');
    if (d)
        *d = 0;
    return D_00559F20;
}

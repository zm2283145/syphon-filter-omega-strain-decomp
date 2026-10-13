#include "types.h"
extern char D_00499C71[];
extern char D_00554F60[];
extern char D_004BD3D8[];
extern char* strrchr(const char* s, int c);
extern char* strncpy(char* d, const char* s, unsigned int n);
extern char* func_00128F58(char* d, const char* s);
char* func_003D9280(char* path)
{
    char* name;
    char* p = strrchr(path, ':');
    if (p) {
        int len; char* s;
        name = p + 1;
        for (p = p - 2; p > path && *p != ':'; p--) {
        }
        if (p > path) s = p + 1; else s = path;
        if ((*s == 'c' || *s == 'n') && (D_00499C71[s[1]] & 1)) s++;
        len = name - s;
        strncpy(D_00554F60, s, len - 2);
        D_00554F60[len - 2] = 0;
        func_00128F58(D_00554F60, D_004BD3D8);
    } else {
        name = path;
        D_00554F60[0] = 0;
    }
    if (*name == 'e' && (D_00499C71[name[1]] & 1)) name++;
    func_00128F58(D_00554F60, name);
    return D_00554F60;
}


#include "types.h"
extern char D_004BB558[];
extern char D_004BB568[];
extern char D_00533790[];
extern int sprintf(char* buf, const char* fmt, ...);
extern char* Loc_LookupText(char* key);
extern unsigned int strlen(const char* s);
extern char func_0012B290(int c);
char* func_0035CB30(int n)
{
    char buf[32];
    unsigned int i;
    sprintf(buf, D_004BB558, n);
    sprintf(D_00533790, D_004BB568, 0x11, Loc_LookupText(buf), 0x10);
    for (i = 0; i < strlen(D_00533790); i++) D_00533790[i] = func_0012B290(D_00533790[i]);
    return D_00533790;
}
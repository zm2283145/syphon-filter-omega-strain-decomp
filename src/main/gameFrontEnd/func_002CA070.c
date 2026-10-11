#pragma cplusplus on
#include "types.h"
extern "C" {
extern signed char D_0051EF60;
extern bool D_0051EF58;
extern char D_004ACF80[];
extern char D_004ACF98[];
char* func_003CBA90(char* s);
int func_00128E80(char* a, char* b);
}
extern "C" bool func_002CA070(void)
{
    if (!D_0051EF60) {
        bool eq = func_00128E80(func_003CBA90(D_004ACF80), D_004ACF98) == 0;
        D_0051EF60 = 1;
        D_0051EF58 = !eq;
    }
    return D_0051EF58;
}
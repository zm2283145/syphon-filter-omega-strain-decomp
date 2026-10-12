#pragma cplusplus on
#include "types.h"
extern "C" {
extern signed char D_0051EF60;
extern bool D_0051EF58;
char* func_003CBA90(char* s);
int String_CompareNoCase(char* a, char* b);
}
extern "C" bool func_002CA070(void)
{
    if (!D_0051EF60) {
        bool eq = String_CompareNoCase(func_003CBA90("LOBBY_DISABLE_REGISTER"), "1") == 0;
        D_0051EF60 = 1;
        D_0051EF58 = !eq;
    }
    return D_0051EF58;
}
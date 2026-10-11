#include "types.h"
extern char D_004BA3B8[];
extern char D_004BA338[];
extern int sprintf(char* buf, const char* fmt, ...);
extern char* Loc_LookupText(char* key);
char* func_003488E0(void* self, int n)
{
    char buf[16];
    char* t;
    if (n < 0 || (unsigned int)n >= 12) return 0;
    sprintf(buf, D_004BA3B8, n);
    t = Loc_LookupText(buf);
    if (t) return t;
    return D_004BA338;
}
